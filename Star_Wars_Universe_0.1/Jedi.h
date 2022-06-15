#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "MyVector.hpp"
#include "GlobalFunctions.h"

class Jedi
{
	MyString name;
	MyString lightsaberColour;
	double strength;

	enum class JediRank
	{
		UNDEFINED = -1,
		YOUNGLING,
		INITIATE,
		PADAWAN,
		KNIGHT_ASPIRANT,
		KNIGHT,
		MASTER,
		BATTLE_MASTER,
		GRAND_MASTER,
	};
	JediRank jediRank;
	unsigned age;
	bool correctJediRank = true;

public:
	
	Jedi();
	Jedi(const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength);

	void setName(const MyString& name);
	void setLightsaberColour(const MyString& saberColour);
	void setStrength(double strength);
	void setJediRank(const MyString& jediRank);
	void setAge(unsigned age);

	const MyString& getName() const;
	const MyString& getLightsaberColour() const;
	double getStrength() const;
	const MyString getJediRank() const;
	int getJediRankAsNumber() const;
	unsigned getAge() const;

	void promoteJedi(double multiplier);
	void demoteJedi(double multiplier);


	friend std::ostream& operator<<(std::ostream& ofs, const Jedi& jedi);
	friend std::istream& operator>>(std::istream& ifs, Jedi& jedi);
};

std::ostream& operator<<(std::ostream& ofs, const Jedi& jedi);
std::istream& operator>>(std::istream& ifs, Jedi& jedi);