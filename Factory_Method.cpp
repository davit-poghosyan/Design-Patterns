#include <iostream>
#include <string>
#include <vector>

class Logistics
{
public:
	virtual ~Logistics() = default;
	virtual std::string shipping() const = 0;
};

class RoadLogist : public Logistics
{
public:
	std::string shipping() const override { return "shipping by road\n"; }
};

class SeaLogist : public Logistics
{
public:
	std::string shipping() const override { return "shipping by sea\n"; }
};

class Factory
{
public:
	~Factory() = default;
	virtual Logistics* create() const = 0;
	std::string SomeOperation() const
	{
		Logistics* product = this->create();
		std::string result = "Creator: The same creator's code has just worked with " + product->shipping();
		delete product;
		return result;
	}
};

class RoadLogistCreator : public Factory
{
public:
	Logistics* create() const override
	{
		return new RoadLogist;
	}
};

class SeaLogistCreator : public Factory
{
public:
	Logistics* create() const override
	{
		return new SeaLogist();
	}
};

void ClientCode(const Factory &src)
{
	std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
			  << src.SomeOperation() << std::endl;
}

int main()
{
	std::cout << "App: Launched with the RoadLogistCreator\n";
	Factory* f1 = new RoadLogistCreator;
	ClientCode(*f1);
	std::cout << std::endl;
	std::cout << "App: Launched with the SeaLogistCreato\n";
	Factory* f2 = new SeaLogistCreator;
	ClientCode(*f2);

	delete f1;
	delete f2;
}
