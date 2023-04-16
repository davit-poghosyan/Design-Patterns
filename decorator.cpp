#include <iostream>

class Bevarage
{
public:
	virtual ~Bevarage() = default;
	virtual std::string description() = 0;
	virtual float cost() = 0;
};

class Decat : public Bevarage
{
public:
	std::string description() override { return "Decat\n"; }
	float cost() override { return 2; }
};

class Expresso : public Bevarage
{
public:
	std::string description() override { return "Expresso\n"; }
	float cost() override { return 1; }
};

class Decorator : public Bevarage
{
public:
	Bevarage* bevarage;
};

class CaramelDecorator : public Decorator
{
public:
	CaramelDecorator(Bevarage* b) { bevarage = b; }

	std::string description() override { return "Caramel decorator was added\n"; }
	float cost() override { return this->bevarage->cost() + 2; }
};

class SoyDecorator : public Decorator
{
public:
	SoyDecorator(Bevarage* b) { bevarage = b; }
	std::string description() override { return "Soy decorator was added\n"; }
	float cost() override { return this->bevarage->cost() + 1; }
};

int main()
{
}
