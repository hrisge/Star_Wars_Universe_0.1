#pragma once
#include <iostream>
#include "MyString.h"
#include "MyVector.hpp"
#include "Jedi.h"


class Planet
{
	MyString name;
	MyVector<Jedi> jedi;

public:
	
	Planet();
	Planet(const MyString& name);

	const MyString& getName() const;
	const MyVector<Jedi>& getJedi() const;

	void setName(const MyString& name);
	void addAJedi(const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength);
	void removeJedi(const MyString& name);
	void promoteJedi(const MyString& name);
	void demoteJedi(const MyString& name);
	const Jedi& getStrongestJedi() const;


};

