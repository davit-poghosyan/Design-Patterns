#include <iostream>

class Adaptee
{
public:
	void specificRequest() { std::cout << "specific Request\n"; }
};

class Target
{
public:
	virtual void request() = 0;
};

class Adapter : public Target
{
	Adaptee* adaptee;

public:
	Adapter(Adaptee* a) { adaptee = a; }
	void request() { adaptee->specificRequest(); }
};

class Client
{
	Target* target;
	Adapter* adapter;

public:
	Client(Adaptee* a)
	{
		adapter = new Adapter(a);
		target = nullptr;
	}
	void usingAdapter()
	{
			adapter->request();
	}
};

int main()
{
}
