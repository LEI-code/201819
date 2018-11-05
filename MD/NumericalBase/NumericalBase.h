
struct NumberValue{
	NumberValue(const char* str, unsigned base);	//takes random base
	NumberValue(unsigned long long bs10nr = 10);	//takes base 10 nr
	~NumberValue();
	void print(unsigned base);

	unsigned long long buffer;
};