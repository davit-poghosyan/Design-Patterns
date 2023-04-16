#include <iostream>
#include <vector>

class IObserver
{
public:
	virtual void update(const std::string&) = 0;
	virtual ~IObserver() = default;
};

class ISubject
{
public:
	virtual void addObserver(IObserver*) = 0;
	virtual void removeObserver(IObserver*) = 0;
	virtual void note() = 0;
};

class Subject : public ISubject
{
private:
	std::vector<IObserver*> observers;
	std::string message;

public:
	Subject() : observers{}, message{} {}

	void addObserver(IObserver* o) override
	{
		observers.push_back(o);
	}

	void removeObserver(IObserver* o) override
	{
		for (int i = 0; i < observers.size() - 1; ++i)
		{
			std::vector<IObserver*> tmp;
			if (observers[i] != o)
			{
				tmp.push_back(observers[i]);
			}
			else
			{
				continue;
			}
			observers = tmp;
		}
	}

	void note()
	{
		std::cout << "insert message\n";
		getline(std::cin, message);
		for (int i = 0; i < observers.size(); ++i)
		{
			observers[i]->update(message);
		}
	}
};

class Observer : public IObserver
{
private:
	std::vector<std::string> notes;
	Subject& subject;
	int num;
	static int amount;

public:
	Observer(Subject& s) : subject{s}
	{
		num = amount;
		++amount;
	}
	void update(const std::string& note) override
	{
		notes.push_back(note);
	}
};

int Observer::amount = 0;

int main()
{
}
