#include <iostream>
#include "Building.h"

int Building::NextID = 1;



Building::Building(int _MaxAge = 10, int _InitialCost = 100)
	: MaxAge{ _MaxAge }, InitialCost{ _InitialCost }
{
	Cost = InitialCost;
	ID = NextID;
	++NextID;
};

void Building::Destroy() 
{
	std::cout << "Building with id " << Building::ID << " was destroy" << std::endl;
}

void Building::ToAge(const int years) 
{
	Building::CurrentAge = Building::CurrentAge + years;
	if (Building::CurrentAge > Building::MaxAge)
	{
		Building::Destroy();
	}

	Building::Cost = ((Building::CurrentAge) * (-Building::InitialCost)) / Building::MaxAge + Building::InitialCost;
	if (Building::Cost < 0) 
	{
		Building::Cost = 0;
	}
	
};