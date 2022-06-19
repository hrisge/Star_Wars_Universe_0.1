#include "Planet.h"

int Planet::getIndexOfAJediByName(const MyString& name) const
{
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
		if (getJedi()[i].getName() == name)
			return i;
	return -1;
}

void Planet::sort()
{
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		Jedi buff = getJedi()[i];
		int j = i - 1;
		while (j >= 0 && isLeftStringBeforeRightAlphabetically(buff.getName(), getJedi()[j].getName()))
		{
			jedi[j + 1] = jedi[j];
			--j;
		}
		jedi[j + 1] = buff;
	}

	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		Jedi buff = getJedi()[i];
		int j = i - 1;
		while (j >= 0 && buff.getJediRankAsNumber() < getJedi()[j].getJediRankAsNumber())
		{
			jedi[j + 1] = jedi[j];
			--j;
		}
		jedi[j + 1] = buff;
	}
}

void Planet::load()
{
	MyString fileName = getName();
	fileName.concat(".db"); 

	std::ifstream fileIn(fileName.getString());
	if (!fileIn.is_open())
	{
		std::cout << "File could not be open!\n";
		return;
	}

	bool fileEnd = fileIn.peek() == '\0';
	while (!fileEnd)
	{
		char buffName[MAX_BUFF3];
		fileIn.getline(buffName, MAX_BUFF3, '#');
		
		char buffRank[MAX_BUFF3];
		fileIn.getline(buffRank, MAX_BUFF3, '#');

		char buffAge[MAX_BUFF3];
		fileIn.getline(buffAge, MAX_BUFF3, '#');
		unsigned age = convertArrToUnsigned(buffAge);

		char buffSaberColour[MAX_BUFF3];
		fileIn.getline(buffSaberColour, MAX_BUFF3, '#');

		double strength;
		fileIn >> strength;

		addAJedi(buffName, buffRank, age, buffSaberColour, strength);

		while (fileIn.peek() == '#' || fileIn.peek()=='\n')
			fileIn.get();

		fileEnd = fileIn.peek() == '\0';
	}
	fileIn.close();
}

Planet::Planet()
{

}

Planet::Planet(const MyString& name)
{
	this->name = name;
	load();
}

const MyString& Planet::getName() const
{
	return name;
}

const MyVector<Jedi>& Planet::getJedi() const
{
	return jedi;
}

const Jedi& Planet::searchJediByName(const MyString& name) const
{
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
		if (getJedi()[i].getName() == name)
			return getJedi()[i];
}

bool Planet::isThereAJediWithThisName(const MyString& name) const
{
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
		if (getJedi()[i].getName() == name)
			return true;
	return false;
}

void Planet::setName(const MyString& name)
{
	this->name = name;
}

void Planet::addAJedi(const MyString& name, const MyString& rank, unsigned age, const MyString& saberColour, double strength)
{
	if (!isThereAJediWithThisName(name))
		jedi.addItem({ name, rank, age, saberColour, strength });

	else
		std::cout << "There is already a Jedi with this name on this Planet!\n";
}

void Planet::removeJedi(const MyString& name)
{
	int ind = getIndexOfAJediByName(name);
	if (ind < 0)
	{
		std::cout << "There is no Jedi with this name on this Planet!\n";
		return;
	}

	jedi.removeItem(ind);
	std::cout << "Jedi " << name << " was removed from the Planet!\n";
}

void Planet::promoteJedi(const MyString& name, double multiplier)
{
	int ind = getIndexOfAJediByName(name);
	if (ind < 0)
	{
		std::cout << "There is no Jedi with this name on this Planet!\n";
		return;
	}

	jedi[ind].promoteJedi(multiplier);
}

void Planet::demoteJedi(const MyString& name, double multiplier)
{
	int ind = getIndexOfAJediByName(name);
	if (ind < 0)
	{
		std::cout << "There is no Jedi with this name on this Planet!\n";
		return;
	}
	
	jedi[ind].demoteJedi(multiplier);
}

const Jedi* Planet::getStrongestJedi() const
{
	double strength = -100000;
	int index = -1;

	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		if (strength < getJedi()[i].getStrength())
		{
			strength = getJedi()[i].getStrength();
			index = i;
		}
		else if (strength == getJedi()[i].getStrength())
		{
			if (index < 0)
			{
				strength = getJedi()[i].getStrength();
				index = i;
			}
			else
			{
				if (getJedi()[i].getJediRankAsNumber() > getJedi()[index].getJediRankAsNumber())
				{
					strength = getJedi()[i].getStrength();
					index = i;
				}
				else if (getJedi()[i].getJediRankAsNumber() == getJedi()[index].getJediRankAsNumber())
				{
					if (isLeftStringBeforeRightAlphabetically(getJedi()[i].getName(), getJedi()[index].getName()))
					{
						index = i;
						strength = getJedi()[i].getStrength();
					}
				}
			}
		}
	}
	if (getJedi().getSize() == 0)
	{
		std::cout << "There are no Jedi on this Planet!\n";
		return nullptr;
	}
	return &getJedi()[index];
}

const Jedi* Planet::getYoungestJedi(const MyString& jediRank) const
{
	int index = -1;
	unsigned age = 1000000;

	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		if (jediRank == getJedi()[i].getJediRank())
		{
			if (age > getJedi()[i].getAge())
			{
				index = i;
				age = getJedi()[i].getAge();
			}
			else if (getJedi()[i].getAge() == age)
			{
				if (getJedi()[i].getJediRankAsNumber() > getJedi()[index].getJediRankAsNumber())
				{
					index = i;
					age = getJedi()[i].getAge();
				}
				else if (getJedi()[i].getJediRankAsNumber() == getJedi()[index].getJediRankAsNumber())
				{
					if (isLeftStringBeforeRightAlphabetically(getJedi()[i].getName(), getJedi()[index].getName()))
					{
						index = i;
						age = getJedi()[i].getAge();
					}
				}
			}
		}
	}
	if (getJedi().getSize() == 0)
	{
		std::cout << "There are no Jedi on this Planet!\n";
		return nullptr;
	}
	return &getJedi()[index];
}

const MyString Planet::getMostUsedSaberColour(const MyString& jediRank) const
{
	MyVector<MyString> sabers;
	MyVector<int> counter;

	if (getJedi().getSize() == 0)
	{
		std::cout << "There are no Jedi on this Planet!\n";
		MyString a;
		return a;
	}

	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		if (getJedi()[i].getJediRank() == jediRank)
		{
			bool matched = false;
			for (unsigned j = 0; j < sabers.getSize(); ++j)
			{
				if (getJedi()[i].getLightsaberColour() == sabers[j])
				{
					matched = true;
					counter[j] = counter[j] + 1;
					break;
				}
			}
			if (!matched)
			{
				sabers.addItem(getJedi()[i].getLightsaberColour());
				counter.addItem(1);
			}
		}
	}

	unsigned indexToReturn;
	int max=0;
	for (unsigned i = 0; i < counter.getSize(); ++i)
	{
		if (max <= counter[i])
		{
			max = counter[i];
			indexToReturn = i;
		}
	}
	return sabers[indexToReturn];
}

void Planet::printAPlanet()
{
	std::cout << "Planet name: " << getName() << "\nJedi that are on this planet are: \n";
	sort();
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		std::cout << i+1 << ") Jedi name : " << getJedi()[i].getName();
		std::cout << "\n   Jedi rank: " << getJedi()[i].getJediRank();
		std::cout << "\n   Jedi age:" << getJedi()[i].getAge();
		std::cout << "\n   Jedi's lightsaber colour: " << getJedi()[i].getLightsaberColour();
		std::cout << "\n   Jedi's strength: " << getJedi()[i].getStrength() << std::endl<<std::endl;
	}
}

void Planet::print(const MyString& jediName) const
{
	int index = getIndexOfAJediByName(jediName);
	if (index < 0)
	{
		std::cout << "There is no Jedi with that name!\n";
		return;
	}

	std::cout << getJedi()[index];
}

void Planet::save() const
{
	MyString fileName = getName();
	fileName.concat(".db");

	std::ofstream fileOut(fileName.getString(), std::ios::out | std::ios::trunc);
	if (!fileOut.is_open())
	{
		std::cout << "File could not be open!\n";
		return;
	}

	for (unsigned i = 0; i < getJedi().getSize(); ++i)
	{
		fileOut << getJedi()[i].getName() << '#';
		fileOut << getJedi()[i].getJediRank() << '#';
		fileOut << getJedi()[i].getAge() << '#';
		fileOut << getJedi()[i].getLightsaberColour() << '#';
		fileOut << getJedi()[i].getStrength() << '\n';
	}
	fileOut << '\0';

	fileOut.close();
}


