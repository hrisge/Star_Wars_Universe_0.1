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
	if (!isTherePlanetWithThisName(planetName))
	{
		std::cout << "There is already planet with this name! \n";
		return;
	}
	planetCollection.addItem(planetName);
	std::cout << "Planet created successfully!\n";
}

void PlanetCollection::addJedi(const MyString& planetName, const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength)
{
	int ind = getIndexForAPlanetByName(planetName);
	if (ind < 0)
	{
		std::cout << "There is no planet with this name! \n";
		return;
	}
	planetCollection[ind].addAJedi(name, rank, age, saberColour, strength);
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
		return;
	}
	return planetCollection[index].getStrongestJedi();
}

const Jedi* PlanetCollection::getYoungestJedi(const MyString& planetName) const
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return;
	}
	return planetCollection[index].getYoungestJedi();
}

const MyString PlanetCollection::getMostUsedSaberColour(const MyString& planetName, const MyString& jediRank) const
{
	int index = getIndexForAPlanetByName(planetName);
	if (index < 0)
	{
		std::cout << "There is no planet with this name!\n";
		return;
	}
	return planetCollection[index].getMostUsedSaberColour(jediRank);
}

void PlanetCollection::print()
{
	for (size_t i = 0; i < getPlanetCollection().getSize(); ++i)
	{
		planetCollection[i].print();
		std::cout << std::endl << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	}
}
