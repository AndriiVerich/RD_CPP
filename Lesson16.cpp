#include <iostream>
#include <map>
#include <vector>
using namespace  std;

struct Player
{
	string PlayerName;
	float PlayerPower;
};

int GetPlayerCount(const string& ClanName);
int ClanFight(const string& FirstClanName, const string& SecondClanName);

map<string, vector<Player>> MyClans;
int main()
{
	string ClanName;
	string PlayerName;
	float PlayerPower;

	//Manual Input
	/*cout << "Enter clan Name: ";
	cin >> ClanName;
	cout << "Enter Player Name: ";
	cin >> PlayerName;
	cout << "Enter Player Power: ";
	cin >> PlayerPower;*/
	//MyClans.at(ClanName).push_back({ PlayerName,PlayerPower });

	MyClans.insert({ "Wolf",{{"Alex",12.0f}}});
	MyClans.insert({ "Rabbit",{{"Alex",15.0f}} });
	
	MyClans.at("Wolf").push_back({ "Ruslan",13.0f });
	MyClans.at("Wolf").push_back({ "Ivan",33.0f });
	MyClans.at("Rabbit").push_back({ "Jack",43.0f });
	cout<<ClanFight("Wolf", "Rabbit");

	cout << GetPlayerCount("Wolf");
	return 0;
}

int GetPlayerCount(const string& ClanName)
{
	return MyClans.at(ClanName).size();
};

int ClanFight(const string& FirstClanName, const string& SecondClanName)
{
	float FirstPower = 0.0f;
	float SecondPower = 0.0f;
	for (int var = 0;var < MyClans.at(FirstClanName).size();var++)
	{
		FirstPower += MyClans.at(FirstClanName).at(var).PlayerPower;
	}
	for (int var = 0;var < MyClans.at(SecondClanName).size();var++)
	{
		SecondPower += MyClans.at(SecondClanName).at(var).PlayerPower;
	}
	cout << FirstPower << endl;
	cout << SecondPower<< endl;
	if (FirstPower > SecondPower)
	{
		return 1;
	}
	if (FirstPower < SecondPower)
	{
		return -1;
	}
	return 0;
};
