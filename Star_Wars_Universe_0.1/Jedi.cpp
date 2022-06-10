#include "Jedi.h"

Jedi::Jedi(const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength)
{
	setName(name);
	setJediRank(rank);
	setAge(age);
	setLightsaberColour(saberColour);
	setStrength(strength);
	while (correctJediRank == false)
	{
		system("CLS");
		std::cout<<"Jedi Rank is Invalid. Try entering valid rank. Valid ranks are: \nYOUNGLING \nINITIATE \nPADAWAN \nKNIGHT_ASPIRANT \nKNIGHT \nMASTER \nBATTLE_MASTER \nGRAND_MASTER \n";
		MyString rank;
		std::cin >> rank;
		setJediRank(rank);
	}
}

void Jedi::setName(const MyString& name)
{
	this->name = name;
}
void Jedi::setLightsaberColour(const MyString& saberColour)
{
	lightsaberColour = saberColour;
}
void Jedi::setStrength(double strength)
{
	this->strength = strength;
}
void Jedi::setJediRank(const MyString& jediRank)
{
	if (jediRank == "YOUNGLING")
		this->jediRank = (JediRank)0;
	else if (jediRank == "INITIATE")
		this->jediRank = (JediRank)1;
	else if (jediRank == "PADAWAN")
		this->jediRank = (JediRank)2;
	else if (jediRank == "KNIGHT_ASPIRANT")
		this->jediRank = (JediRank)3;
	else if (jediRank == "KNIGHT")
		this->jediRank = (JediRank)4;
	else if (jediRank == "MASTER")
		this->jediRank = (JediRank)5;
	else if (jediRank == "BATTLE_MASTER")
		this->jediRank = (JediRank)6;
	else if (jediRank == "GRAND_MASTER")
		this->jediRank = (JediRank)7;
	else
	{
		this->jediRank = (JediRank)-1;
		correctJediRank = false;
		return;
	}
	correctJediRank = true;
}
void Jedi::setAge(unsigned age)
{
	this->age = age;
}

const MyString& Jedi::getName() const
{
	return name;
}
const MyString& Jedi::getLightsaberColour() const
{
	return lightsaberColour;
}
double Jedi::getStrength() const
{
	return strength;
}
const MyString& Jedi::getJediRank() const
{
	switch (jediRank)
	{
	case JediRank::YOUNGLING: return "YOUNGLING";
		break;
	case JediRank::INITIATE: return "INITIATE";
		break;
	case JediRank::PADAWAN: return "PADAWAN";
		break;
	case JediRank::KNIGHT_ASPIRANT : return "KNIGHT_ASPIRANT";
		break;
	case JediRank::KNIGHT: return "KNIGHT";
		break;
	case JediRank::MASTER: return "MASTER";
		break;
	case JediRank::BATTLE_MASTER: return "BATTLE_MASTER";
		break;
	case JediRank::GRAND_MASTER: return "GRAND_MASTER";
		break;
	default: return "UNDEFINED";
		break;
	}
}
unsigned Jedi::getAge() const
{
	return age;
}

void Jedi::promoteJedi(double multiplier)
{
	if (getJediRank() == "GRAND_MASTER")
	{
		std::cout << "This Jedi has been already promoted to the highest rank - Grand Master! \n";
		return;
	}
	if (multiplier < 0)
	{
		std::cout << "Invalid multiplier. Multiplier must be a positive double number! \n";
		return;
	}
	strength *= (1 + multiplier);
	int ind = (int)jediRank;
	jediRank = (JediRank) ++ind;
}

void Jedi::demoteJedi(double multiplier)
{
	if (getJediRank() == "GRAND_MASTER")
	{
		std::cout << "This Jedi has been already demoted to the lowest rank - YOUNGLING! \n";
		return;
	}
	if (multiplier < 0)
	{
		std::cout << "Invalid multiplier. Multiplier must be a positive double number! \n";
		return;
	}
	strength *= (1 - multiplier);
	int ind = (int)jediRank;
	jediRank = (JediRank) --ind;
}

std::ostream& operator<<(std::ostream& ofs, const Jedi& jedi)
{
	ofs << jedi.getName() << " " << jedi.getJediRank() << " " << jedi.getAge() << " " << jedi.getLightsaberColour() << " " << jedi.getStrength() << "\n";
	return ofs;

}

std::istream& operator>>(std::istream& ifs, Jedi& jedi)
{
	char nameBuff[MAX_BUFF3];
	ifs.getline(nameBuff, MAX_BUFF3, ' ');
	jedi.setName(nameBuff);

	char rankBuff[MAX_BUFF3];
	ifs.getline(rankBuff, MAX_BUFF3, ' ');
	jedi.setJediRank(rankBuff);

	unsigned ageBuff;
	ifs >> ageBuff;
	jedi.setAge(ageBuff);

	char saberColourBuff[MAX_BUFF3];
	ifs.getline(saberColourBuff, MAX_BUFF3, ' ');
	jedi.setLightsaberColour(saberColourBuff);

	double strengthBuff;
	ifs >> strengthBuff;
	jedi.setStrength(strengthBuff);

	return ifs;
}
