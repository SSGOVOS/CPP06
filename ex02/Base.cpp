#include "Base.hpp"

int	random(int max)
{
	srand(time(NULL));
	return (rand() % (max));
}

Base *generate(void)
{
	int rand= random(3);

	if (rand == 0)
	{
		std::cout << "Generated A" << std::endl;
		return new A;
	}
	else if (rand == 1)
	{
		std::cout << "Generated B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Generated C" << std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	std::cout << "Reference: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception& e) {}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception& e) {}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception& e) {}
}

int main()
{
	Base *something = generate();
	identify(something);
	sleep(1);
	Base &ref = generate()[0];
	identify(ref);
	return (0);
}