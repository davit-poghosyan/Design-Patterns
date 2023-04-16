#include <iostream>

class FirstDepartament
{
public:
	std::string OP1() { return "OP1\n"; }
	std::string OP2() { return "OP2\n"; }
};

class SecondDepartament
{
public:
	std::string OP3() { return "OP3\n"; }
};

class ThirdDepartament
{
public:
	std::string OP4() { return "OP4\n"; }
};

class Facade
{
public:
	FirstDepartament* first;
	SecondDepartament* second;
	ThirdDepartament* third;

	Facade(FirstDepartament* obj1, SecondDepartament* obj2, ThirdDepartament* obj3)
	{
		first = obj1;
		second = obj2;
		third = obj3;
	}

	std::string Operations()
	{
		std::string result;
		result += first->OP1();
		result += first->OP2();
		result += second->OP3();
		result += third->OP4();
		return result;
	}
};

int main()
{
}
