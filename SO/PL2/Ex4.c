#include <pthread.h>
#include <semaphore.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned maxProdQ = 200;
unsigned producerMaxStock = 150;

unsigned char* productsBuffer = 0;
unsigned maxProductsSp = 0;
unsigned productsSp = 0;

typedef void*(*sr_proto)(void*);


struct Producer{
	char (*processRawMaterial)(char);
	char* rawMaterialBuffr;
	unsigned rawMaterialAmount;
	char* product;
	unsigned productAmount;
	unsigned maxProductAmount;

	sem_t finishedWriting;
	sem_t demand;
	unsigned demandAmount;
	sem_t* ProdBuffer;
};void Producer_init(struct Producer* p){
	sem_init(&p->demand, 0, 0);
	sem_init(&p->finishedWriting, 0, 0);
}void Producer_term(struct Producer* p){
	sem_close(&p->demand);
	sem_close(&p->finishedWriting);
}

struct ProducerThread{
	struct Producer prod;
	pthread_t thread;
};

void* ProducerWork(struct Producer* me){while(1){
	int loopTryWait = 0;			//will be used later
	unsigned i, oldpa = me->productAmount;
	//while we haven't filled up our capacity, and we don't have any requests
	while(me->productAmount != me->maxProductAmount && (loopTryWait = sem_trywait(&me->demand)) == -1){
		me->product[me->productAmount] = me->processRawMaterial(me->rawMaterialBuffr[me->productAmount]);	//create
		me->productAmount++;																				//product
	}
	printf("%u raw materials processed in %p\n", me->productAmount - oldpa, me->processRawMaterial);
	if(loopTryWait == -1)sem_wait(&me->demand); //here if we exited the loop on purpose to push, we won't have to wait again
	if(me->demandAmount == 0)return 0; 			//this is exit scenario

	sem_wait(me->ProdBuffer);					//wait in case someone else is writing to the product buffer
	for (i = 0; i < me->demandAmount && me->productAmount; ++i)	//write all we have or the demand amount
		productsBuffer[productsSp++] = me->product[--me->productAmount];	//depending on which is smallest
	sem_post(me->ProdBuffer);					//make the buffer available for usage again
	printf("shipped %u to the customer\n\n", i);
	sem_post(&me->finishedWriting);				//make it so anyone can know we're done with "shipping" for now
}}												//and that are going back to producing

char prod1(char a){return 'A';}
char prod2(char a){return 'B';}




int main(int argc, char const *argv[]){
	if(argc > 1){
		maxProdQ = atoi(argv[1]);
	}if(argc > 2){
		producerMaxStock = atoi(argv[2]);
	}
	productsBuffer = malloc(maxProdQ);
	maxProductsSp = maxProdQ;
	memset(productsBuffer, '_', maxProductsSp);

	char* rawprod = malloc(producerMaxStock);
	printf("enter raw materials (%u):", producerMaxStock);
	scanf("%s", rawprod);

	sem_t ProdBuffer;
	sem_init(&ProdBuffer, 0, 1);

	struct ProducerThread producers[2] = {
		{{
			prod1, rawprod, producerMaxStock, malloc(producerMaxStock), 0, producerMaxStock, {0}, {0}, 0, &ProdBuffer
		}, 0},
		{{
			prod2, rawprod, producerMaxStock, malloc(producerMaxStock), 0, producerMaxStock, {0}, {0}, 0, &ProdBuffer
		}, 0}
	};

	Producer_init(&producers[0].prod);Producer_init(&producers[1].prod);
	pthread_create(&producers[0].thread, 0, (sr_proto)ProducerWork, &producers[0].prod);
	pthread_create(&producers[1].thread, 0, (sr_proto)ProducerWork, &producers[1].prod);

	sleep(1);

	while(productsSp != maxProductsSp){
		for (int i = 0; i < 2; ++i){
			producers[i].prod.demandAmount = maxProductsSp - productsSp;
			sem_post(&producers[i].prod.demand);
			sem_wait(&producers[i].prod.finishedWriting);
			//sleep(1);
			if(productsSp == maxProductsSp)break;
		}
	}

	printf("%*.*s\n", maxProdQ, maxProdQ, productsBuffer);
	sem_post(&ProdBuffer);

	producers[0].prod.demandAmount = 0;
	sem_post(&producers[0].prod.demand);
	producers[1].prod.demandAmount = 0;
	sem_post(&producers[1].prod.demand);

	pthread_join(producers[0].thread, 0);
	pthread_join(producers[1].thread, 0);

	free(rawprod); free(productsBuffer);
	free(producers[0].prod.product);free(producers[1].prod.product);
	sem_close(&ProdBuffer);
	Producer_term(&producers[0].prod);Producer_term(&producers[1].prod);
	return 0;
}