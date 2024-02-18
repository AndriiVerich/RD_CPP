#include <iostream>
#include "Building.h"

using namespace std;

int main()
{
	Building Build1(10,100);
	Building Build2(30, 500);

	std::cout << Build1.GetCost() << endl;
	Build1.ToAge(2);
	std::cout << Build1.GetCost()<< endl;
	Build1.ToAge(3);
	std::cout << Build1.GetCost() << endl;
	Build1.ToAge(7);
	std::cout << Build1.GetCost() << endl;
	std::cout << Build2.GetCost() << endl;

	return 0;
}