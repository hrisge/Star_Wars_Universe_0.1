#include "Planet.h"

int Planet::getIndexOfAJediByName(const MyString& name) const
{
	for (unsigned i = 0; i < getJedi().getSize(); ++i)
		if (getJedi()[i].getName() == name)
			return i;
	return -1;
}

Planet::Planet()
{

}

Planet::Planet(const MyString& name)
{
	this->name = name;
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
	
	jedi[ind].demoteJedi(multiplier)
}

const Jedi& Planet::getStrongestJedi() const
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

				}
			}
		}
	}
}
