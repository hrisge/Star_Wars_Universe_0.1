#include "System.h"

void system()
{
	PlanetCollection planetCollection;
	system("ClS");
	while (true)
	{
		MyString command;
		std::cout << "\nPlease enter a command. If you need help enter help. Command: ";
		std::cin >> command;
		if (command == "addPlanet")
			addPlanet(planetCollection);
		else if (command == "addJedi")
			addJedi(planetCollection);
		else if (command == "removeJedi")
			removeJedi(planetCollection);
		else if (command == "promoteJedi")
			promoteJedi(planetCollection);
		else if (command == "demoteJedi")
			demoteJedi(planetCollection);
		else if (command == "getStrongestJedi")
			getStrongestJedi(planetCollection);
		else if (command == "getYoungestJedi")
			getYoungestJedi(planetCollection);
		else if (command == "getMostUsedSaberColour")
			getMostUsedSaberColour(planetCollection);
		else if (command == "isTherePlanetWithThisName")
			isTherePlanetWithThisName(planetCollection);
		else if (command == "printTwoPlanetsAtTheSameTime")
			printTwoPlanetsAtTheSameTime(planetCollection);
		else if (command == "print")
			print(planetCollection);
		else if (command == "save")
			save(planetCollection);
		else if (command == "exit")
		{
			exit(planetCollection);
			return;
		}
		else if (command == "help")
			help();
		else
			std::cout << "Invalid command. Type help if you need help!\n";
	}
}

void isTherePlanetWithThisName(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet you want to check! :";
	std::cin >> planetName;
	
	bool res = planetCollection.isTherePlanetWithThisName(planetName);
	system("CLS");
	if (res)
		std::cout << "Yes";
	else
		std::cout << "No";
}

void addPlanet(PlanetCollection& planetCollection)
{
	MyString planetName;
	std::cout << "Enter a planet name: ";
	std::cin >> planetName;
	planetCollection.addPlanet(planetName);
}
void addJedi(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet the Jedi lives on! :";
	std::cin >> planetName;

	MyString name;
	std::cout << "Enter Jedi name. Use only letters spaces and dash! : ";
	std::cin >> name;
	
	MyString rank;
	std::cout << "Enter Jedi rank! Possible ranks are :\n";
	std::cout << "1) YOUNGLING\n2)INITIATE\n3)PADAWAN\n4)KNIGHT_ASPIRANT\n5)KNIGHT\n6)MASTER\n7)BATTLE_MASTER\n8)GRAND_MASTER\nRank: ";
	std::cin >> rank;
	
	unsigned age;
	std::cout << "Enter Jedi age! : ";
	std::cin >> age;

	MyString saberColour;
	std::cout << "Enter the Jedi's lightsaber colour! : ";
	std::cin.ignore();
	std::cin >> saberColour;

	double strength;
	std::cout << "Enter The Jedi's strength! : ";
	std::cin >> strength;
	std::cin.ignore();

	planetCollection.addJedi(planetName, name, rank, age, saberColour, strength);
}
void removeJedi(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet the Jedi lives on! :";
	std::cin >> planetName;

	MyString name;
	std::cout << "Enter Jedi name. Use only letters spaces and dash! : ";
	std::cin >> name;

	planetCollection.removeJedi(planetName, name);
}
void promoteJedi(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet the Jedi lives on! :";
	std::cin >> planetName;

	MyString name;
	std::cout << "Enter Jedi name. Use only letters spaces and dash! : ";
	std::cin >> name;

	double multiplier;
	std::cout << "Enter the multiplier of the increased strength of the Jedi! : ";
	std::cin >> multiplier;
	std::cin.ignore();
	planetCollection.promoteJedi(planetName, name, multiplier);
}
void demoteJedi(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet the Jedi lives on! :";
	std::cin >> planetName;

	MyString name;
	std::cout << "Enter Jedi name. Use only letters spaces and dash! : ";
	std::cin >> name;

	double multiplier;
	std::cout << "Enter the multiplier of the decreased strength of the Jedi! : ";
	std::cin >> multiplier;
	std::cin.ignore();
	planetCollection.demoteJedi(planetName, name, multiplier);
}
void getStrongestJedi(PlanetCollection& planetCollection)
{
	Jedi buff;
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet you want to check! :";
	std::cin >> planetName;

	const Jedi* buff2;
	buff2 = planetCollection.getStrongestJedi(planetName);
	if (buff2 == nullptr)
		return;
	
	buff = *buff2;
	system("CLS");
	std::cout << buff;
}
void getYoungestJedi(PlanetCollection& planetCollection)
{
	Jedi buff;
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet you want to check! :";
	std::cin >> planetName;

	MyString rank;
	std::cout << "Enter Jedi rank you want to check! Possible ranks are :\n";
	std::cout << "1) YOUNGLING\n2)INITIATE\n3)PADAWAN\n4)KNIGHT_ASPIRANT\n5)KNIGHT\n6)MASTER\n7)BATTLE_MASTER\n8)GRAND_MASTER\nRank: ";
	std::cin >> rank;

	const Jedi* buff2;
	buff2 = planetCollection.getYoungestJedi(planetName, rank);
	if (buff2 == nullptr)
		return;
	
	buff = *buff2;
	system("CLS");
	std::cout << buff;
}
void getMostUsedSaberColour(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName;
	std::cout << "Enter the name of the planet the Jedi lives on! :";
	std::cin >> planetName;

	MyString rank;
	std::cout << "Enter Jedi rank you want to check! Possible ranks are :\n";
	std::cout << "1) YOUNGLING\n2)INITIATE\n3)PADAWAN\n4)KNIGHT_ASPIRANT\n5)KNIGHT\n6)MASTER\n7)BATTLE_MASTER\n8)GRAND_MASTER\nRank: ";
	std::cin >> rank;

	system("CLS");
	std::cout<<planetCollection.getMostUsedSaberColour(planetName, rank);
}
void printTwoPlanetsAtTheSameTime(PlanetCollection& planetCollection)
{
	system("CLS");
	MyString planetName1;
	std::cout << "Enter the name of the First planet you want to print: ";
	std::cin >> planetName1;

	MyString planetName2;
	std::cout << "Enter the name of the Second planet you want to print: ";
	std::cin >> planetName2;

	planetCollection.printTwoPlanetsAtTheSameTime(planetName1, planetName2);
}
void print(PlanetCollection& planetCollection)
{
	system("CLS");
	planetCollection.print();
}
void save(PlanetCollection& planetCollection)
{
	planetCollection.save();
}
void exit(PlanetCollection& planetCollection)
{
	planetCollection.save();
}
void help()
{
	system("CLS");
	std::cout << "The commands you can enter are : \n1)addPlanet\n2)addJedi\n3)reomveJedi\n4)promoteJedi\n5)demoteJedi\n6)getStrongestJedi\n";
	std::cout << "7)getYoungestJedi\n8)getMostUsedSaberColour\n9)isTherePlanetWithThisName\n10)printTwoPlanetsAtTheSameTime\n11)print\n12)save\n13)exit\n";
}