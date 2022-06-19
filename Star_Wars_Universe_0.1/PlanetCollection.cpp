#include "PlanetCollection.h"

int PlanetCollection::getIndexForAPlanetByName(const MyString& planetName) const
{
	for (unsigned i = 0; i < getPlanetCollection().getSize(); ++i)
	{
		if (getPlanetCollection()[i].getName() == planetName)
			return i;
	}
	return -1;
}

void PlanetCollection::load()
{
	std::ifstream fileIn(fileName.getString());


	if (!fileIn.is_open())
	{
		std::cout << "Could not open file!\n";
		return;
	}

	bool fileEnd = fileIn.peek() == '\0';
	while (!fileEnd)
	{
		char nameBuff[MAX_BUFF3];
		fileIn.getline(nameBuff, MAX_BUFF3);
		fileEnd = fileIn.peek() == '\0';

		Planet buff(nameBuff);

		planetCollection.addItem(buff);
	}
	fileIn.close();

	
}

PlanetCollection::PlanetCollection()
{
	load();
}

const MyVector<Planet> PlanetCollection::getPlanetCollection() const
{
	return planetCollection;
}

bool PlanetCollection::isTherePlanetWithThisName(const MyString& planetName) const
{
	int ind = getIndexForAPlanetByName(planetName);
	return (ind >= 0);
}

void PlanetCollection::addPlanet(const MyString& planetName)
{
	if (isTherePlanetWithThisName(planetName))
	{
		std::cout << "There is already planet with this name! \n";
		return;
	}
	planetCollection.addItem(planetName);
	system("CLS");
	std::cout << "Planet created successfully!\n";
}

void PlanetCollection::addJedi(const MyString& planetName, const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength)
{
	system("CLS");
	int ind = getIndexForAPlanetByName(planetName);
	if (ind < 0)
	{
		std::cout << "There is no planet with this name! \n";
		return;
	}

	planetCollection[ind].addAJedi(name, rank, age, saberColour, strength);
	if (planetCollection[ind].getJedi()[planetCollection[ind].getJedi().getSize() - 1].getCorrectData() == false)
	{
		std::cout << "The inputed data was Invalid. Jedi not added to the planet!\n";
		planetCollection[ind].removeJedi(name);
		return;
	}

	std::cout << "Jedi added successfully!\n";
}

void PlanetCollection::removeJedi(const MyString& planetName, const MyString& name)
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return;
	}
	planetCollection[index].removeJedi(name);
}

void PlanetCollection::promoteJedi(const MyString& planetName, const MyString& name, double multiplier)
{
	system("CLS");
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return;
	}
	planetCollection[index].promoteJedi(name, multiplier);
}

void PlanetCollection::demoteJedi(const MyString& planetName, const MyString& name, double multiplier)
{
	system("CLS");
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return;
	}
	planetCollection[index].demoteJedi(name, multiplier);
}

const Jedi* PlanetCollection::getStrongestJedi(const MyString& planetName) const
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return nullptr;
	}
	return planetCollection[index].getStrongestJedi();
}

const Jedi* PlanetCollection::getYoungestJedi(const MyString& planetName, const MyString& rank) const
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return nullptr;
	}
	return planetCollection[index].getYoungestJedi(rank);
}

const MyString PlanetCollection::getMostUsedSaberColour(const MyString& planetName, const MyString& jediRank) const
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return nullptr;
	}
	return planetCollection[index].getMostUsedSaberColour(jediRank);
}

void PlanetCollection::printTwoPlanetsAtTheSameTime(const MyString& planetName1, const MyString& planetName2)
{
	int index1 = getIndexForAPlanetByName(planetName1);
	if (index1 < 0)
		std::cout << "There is no planet with the name " << planetName1;
	else
		planetCollection[index1].printAPlanet();

	int index2 = getIndexForAPlanetByName(planetName2);
	if (index2 < 0)
		std::cout << "There is no planet with the name " << planetName2;
	else
		planetCollection[index2].printAPlanet();

}

void PlanetCollection::print()
{
	for (size_t i = 0; i < getPlanetCollection().getSize(); ++i)
	{
		planetCollection[i].printAPlanet();
		std::cout << std::endl << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	}
}

void PlanetCollection::save() const
{
	std::ofstream fileOut(fileName.getString(), std::ios::out);
	if (!fileOut.is_open())
	{
		std::cout << "Could not open file!\n";
		return;
	}

	for (unsigned i = 0; i < getPlanetCollection().getSize(); ++i)
	{
		fileOut << getPlanetCollection()[i].getName() << "\n";
		planetCollection[i].save();
	}
	fileOut << '\0';
	fileOut.close();
}
