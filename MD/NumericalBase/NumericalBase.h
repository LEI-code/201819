
struct NumberValue{
	NumberValue(const char* str, unsigned base);	//takes random base
	void print(unsigned base);

	unsigned long long buffer;
};