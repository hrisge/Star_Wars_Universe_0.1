#pragma once
#include <iostream>
#include "MyString.h"
#include "MyVector.hpp"
#include "Jedi.h"


class Planet
{
	MyString name;
	MyVector<Jedi> jedi;

	int getIndexOfAJediByName(const MyString& name) const;
	void sort();
	void load();

public:
	
	Planet();
	Planet(const MyString& name);

	const MyString& getName() const;
	const MyVector<Jedi>& getJedi() const;
	const Jedi& searchJediByName(const MyString& name) const;
	bool isThereAJediWithThisName(const MyString& name) const;

	void setName(const MyString& name);
	void addAJedi(const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength);
	void removeJedi(const MyString& name);
	void promoteJedi(const MyString& name, double multiplier);
	void demoteJedi(const MyString& name, double multiplier);
	const Jedi* getStrongestJedi() const;
	const Jedi* getYoungestJedi(const MyString& jediRank) const;
	const MyString getMostUsedSaberColour(const MyString& jediRank) const;
	void printAPlanet();
	void print(const MyString& jediName) const;
	void save() const;
};

