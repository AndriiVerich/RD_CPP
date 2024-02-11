//#include <iostream>
//using namespace std;
//
//struct MyCharacter
//{
//	string Name;
//	float Health;
//	int CharClass; //1-mage, 2-warrior
//	int Power;
//	
//};
//
//int DamageCalculator(MyCharacter& Char, int Damage)
//{
//
//	if (Char.CharClass == 1) // Character class check
//	{
//		if (Damage % 2 == 0) // Parity check
//		{
//			Char.Health = Char.Health - 2 * Damage;
//		}
//		else
//		{
//			Char.Health = Char.Health - Damage;
//		}
//		return 0;
//	}
//
//	if (Char.CharClass == 2) // Character class check
//	{
//		if (Damage % 2 != 0) // Check for oddness
//		{
//			Char.Health = Char.Health - 3 * Damage;
//		}
//		return 0;
//	}
//	
//}
//
//int main() {
//
//	MyCharacter Character;
//
//	cout << "Enter Character Name: ";
//	cin >> Character.Name;
//	cout << "Enter Character Health: ";
//	cin >> Character.Health;
//	cout << "Enter Character Class (1-mage, 2-warrior): ";
//	cin >> Character.CharClass;
//
//
//	bool IsLive = true;
//
//	while (IsLive) 
//	{
//		int Damage;
//		cout << "Enter the damage received: ";
//		cin >> Damage;
//		DamageCalculator(Character, Damage);
//		if (Character.Health <= 0)
//		{
//			IsLive = false;
//			cout << "You are dead";
//			break;
//		}
//		cout << "Current Health: "<< Character.Health;
//
//	}
//
//	return 0;
//
//}