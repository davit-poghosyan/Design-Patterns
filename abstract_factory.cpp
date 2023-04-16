#include <iostream>
#include <string>

class Chair
{
public:
	virtual std::string chair() = 0;
};

class Table
{
public:
	virtual std::string table() = 0;
};

class ArtDecoChair : public Chair
{
public:
	std::string chair() override { return "ArtDeco chair\n"; }
};

class ArtDecoTable : public Table
{
public:
	std::string table() override { return "ArtDeco table\n"; }
};

class VictorianChair : public Chair
{
public:
	std::string chair() override { return "Vircortian chair\n"; }
};

class VictorianTable : public Table
{
public:
	std::string table() override { return "Victorian table\n"; }
};

class ModernChair : public Chair
{
public:
	std::string chair() override { return "Modern chair\n"; }
};

class ModernTable : public Table
{
public:
	std::string table() override { return "Modern table\n"; }
};

class Factory
{
public:
	virtual Chair* createChair() = 0;
	virtual Table* createTable() = 0;

	std::string operationChair()
	{
		Chair* obj = createChair();
		std::string result = "there was created " + obj->chair();
		delete obj;
		return result;
	}

	std::string operationFactory()
	{
		Table* obj = createTable();
		std::string result = "there was created " + obj->table();
		delete obj;
		return result;
	}
};

class createArtDeco : public Factory
{
public:
	Chair* createChair() override { return new ArtDecoChair; }

	Table* createTable() override { return new ArtDecoTable; }
};

class createVictorian : public Factory
{
public:
	Chair* createChair() override { return new VictorianChair; }

	Table* createTable() override { return new VictorianTable; }
};

class createModern : public Factory
{
public:
	Chair* createChair() override { return new ModernChair; }

	Table* createTable() override { return new ModernTable; }
};

int main()
{
}
