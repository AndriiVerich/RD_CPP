#include <iostream>
#include <vector>
using namespace std;

enum CharClasses
{
	WARRIOR,
	MAGE
};

struct Character
{
	int ID;
	CharClasses CharClas;
	float MeleePower;
	float RangedPower;
};

int StrongestCharacter(std::vector<Character>& InCharacter)
{
	int ID = InCharacter[0].ID;
	float Summ = InCharacter[0].MeleePower + InCharacter[0].RangedPower;
	for (int var = 0; var < InCharacter.size(); var++)
	{
		if (Summ < InCharacter[var].MeleePower + InCharacter[var].RangedPower)
		{
			ID = InCharacter[var].ID;
			Summ = InCharacter[var].MeleePower + InCharacter[var].RangedPower;
		}
	}
	return ID;
}

int main()
{
	std::vector<Character> MyCharacter = {
		{0, WARRIOR, 5.0f, 12.0f}, 
		{11, MAGE, 7.0f, 5.0f},
		{3, WARRIOR, 1.0f, 12.0f},
		{4, MAGE, 10.0f, 12.0f} };

	cout << "Strongest ID: " << StrongestCharacter(MyCharacter);
	
	return 0;
}