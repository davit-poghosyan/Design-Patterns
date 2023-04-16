#include <iostream>
#include <string>
#include <vector>

class House
{
public:
	std::vector<std::string> parts;
	void ListParts() const
	{
		std::cout << "Product parts: \n";

		for (int i = 0; i < parts.size(); ++i)
		{
			std::cout << parts[i];
		}
		std::cout << "\n\n";
	}
};

class Builder
{
public:
	virtual ~Builder() = default;
	virtual void ProduceWall() = 0;
	virtual void ProduceDoor() = 0;
	virtual void ProduceWindow() = 0;
};

class HouseBuilder : public Builder
{
private:
	House* house;

public:
	HouseBuilder() { reset(); }
	~HouseBuilder() { delete house; }

	void reset() { house = new House; }

	void ProduceWall() override { house->parts.push_back("Wall\n"); }
	void ProduceDoor() override { house->parts.push_back("Door\n"); }
	void ProduceWindow() override { house->parts.push_back("Window\n"); }

	House* getHouse()
	{
		House* result = this->house;
		this->reset();
		return result;
	}
};

class Director
{
private:
	Builder* builder;

public:
	void set_builder(Builder *builder) { this->builder = builder; }

	void buildMinimally()
	{
		builder->ProduceWall();
	}
	void buildFully()
	{
		builder->ProduceWall();
		builder->ProduceDoor();
		builder->ProduceWindow();
	}
};

void ClientCode(Director &director)
{
	HouseBuilder* builder = new HouseBuilder;
	director.set_builder(builder);
	std::cout << "Standard basic house\n";
	director.buildMinimally();

	House* p = builder->getHouse();
	p->ListParts();
	delete p;

	std::cout << "Standard full house\n";
	director.buildFully();

	p = builder->getHouse();
	p->ListParts();
	delete p;

	// We can do it without Director

	std::cout << "Custom House\n";
	builder->ProduceDoor();
	builder->ProduceWindow();
	p = builder->getHouse();
	p->ListParts();
	delete p;

	delete builder;
}

int main()
{
	Director* director = new Director();
	ClientCode(*director);
	delete director;
}
