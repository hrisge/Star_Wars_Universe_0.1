#pragma once
#include "Planet.h"
#include <fstream>

const MyString fileName = "PlanetCollection.db";

class PlanetCollection
{
	MyVector<Planet> planetCollection;

	int getIndexForAPlanetByName(const MyString& planetName) const;
	void load();

public:

	PlanetCollection();
	const MyVector<Planet> getPlanetCollection() const;

	bool isTherePlanetWithThisName(const MyString& planetName) const;
	void addPlanet(const MyString& planetName);
	void addJedi(const MyString& planetName, const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength);
	void removeJedi(const MyString& planetName, const MyString& name);
	void promoteJedi(const MyString& planetName, const MyString& name, double multiplier);
	void demoteJedi(const MyString& planetName, const MyString& name, double multiplier);
	const Jedi* getStrongestJedi(const MyString& planetName) const;
	const Jedi* getYoungestJedi(const MyString& planetName, const MyString& rank) const;
	const MyString getMostUsedSaberColour(const MyString& planetName, const MyString& jediRank) const;
	void print();
	void save() const;
};

