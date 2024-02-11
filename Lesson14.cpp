#include <iostream>
#include <array>
#include <algorithm> 
#include <climits> // Для INT_MAX
using namespace std;
const int ZeroDamage = 1;

struct Stat
{
	int ID = 0;
	int Damage = 0;
	
};

struct DamageStatic
{
	
	std::array<Stat, 5> MaxDamage;
	std::array<Stat, 5> MinDamage ;
	std::array<Stat, 5> ZeroDamage;
	std::array<Stat, 5> Heal;
	int TotalDamage = 0;
	int TotalHeal = 0;
};

// Функция сравнения для сортировки по значению Value
bool CompareByValue(const Stat& a, const Stat& b)
{
	return a.Damage < b.Damage;
}

int MaxArrayIndex(DamageStatic& Damage)
{
	int index = 0;
	int MaxValue = Damage.MinDamage[0].Damage;

	for (int var = 0; var < 5; var++)
	{
		if (Damage.MinDamage[var].Damage == 0)
		{
			index = var;
			return index;
		}
		else if	(MaxValue < Damage.MinDamage[var].Damage) 
		{
			index = var;
		}
	}
	return index;
}

void DamageStat(int InDamage,int ID, DamageStatic &Damage)
{
	if (InDamage > 0) {
		Damage.TotalDamage += InDamage;
		// Max Damage
		if (InDamage > Damage.MaxDamage[0].Damage)
		{
			Damage.MaxDamage[0].Damage = InDamage;
			Damage.MaxDamage[0].ID = ID;
			std::sort(Damage.MaxDamage.begin(), Damage.MaxDamage.end(), CompareByValue);		
		}
		
		//// Min Damage
		int MaxIndex = MaxArrayIndex(Damage);
		if (InDamage < Damage.MinDamage[MaxIndex].Damage);
		{
			Damage.MinDamage[MaxIndex].Damage = InDamage;
			Damage.MinDamage[MaxIndex].ID = ID;	
			std::sort(Damage.MinDamage.begin(), Damage.MinDamage.end(), CompareByValue);	
		}	
	}
	//Heal
	else if (InDamage < 0)
	{
		Damage.TotalHeal += -InDamage;
		Damage.Heal[0].Damage = -InDamage;
		Damage.Heal[0].ID = ID;
		std::sort(Damage.Heal.begin(), Damage.Heal.end(), CompareByValue);
	}
	else
	//Zero Damage
	{
		if (InDamage == 0)
		{
			Damage.ZeroDamage[0].Damage = ZeroDamage;
			Damage.ZeroDamage[0].ID = ID;
			std::sort(Damage.ZeroDamage.begin(), Damage.ZeroDamage.end(), CompareByValue);
		}
	}
}

int main()
{
	int counter = 0; // 
	DamageStatic MyDamage; // stores information about the damage and the index of who caused it
	
	while (true) {

		int Damage;
		cout << "Enter Damage: ";
		cin >> Damage;
		if (Damage == -1)
		{
			cout << MyDamage.TotalDamage << " ";
			cout << MyDamage.TotalHeal << " ";
			break;
			
		}
		DamageStat(Damage, counter, MyDamage);
		counter++;
		
		for (int var = 0; var < 5; var++)
		{
			cout << MyDamage.MaxDamage[var].ID << " ";
			cout << MyDamage.MaxDamage[var].Damage << endl;
			cout << MyDamage.ZeroDamage[var].ID << " ";
			cout << MyDamage.ZeroDamage[var].Damage << endl;
			
		}
	}
	return 0;
}