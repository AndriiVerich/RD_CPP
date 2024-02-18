#pragma once

class Building
{
	
	int ID;
	int MaxAge ;
	int CurrentAge = 0;
	int InitialCost;
	static int NextID;
	void Destroy();
	int Cost;

public:
	Building(int _MaxAge , int _InitialCost );	
	int GetCost() const { return Cost; }
	void ToAge(const int years);
};