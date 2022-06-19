#pragma once
#include "PlanetCollection.h"

void system();

void isTherePlanetWithThisName(PlanetCollection& planetCollection);
void addPlanet(PlanetCollection& planetCollection);
void addJedi(PlanetCollection& planetCollection);
void removeJedi(PlanetCollection& planetCollection);
void promoteJedi(PlanetCollection& planetCollection);
void demoteJedi(PlanetCollection& planetCollection);
void getStrongestJedi(PlanetCollection& planetCollection);
void getYoungestJedi(PlanetCollection& planetCollection);
void getMostUsedSaberColour(PlanetCollection& planetCollection);
void printTwoPlanetsAtTheSameTime(PlanetCollection& planetCollection);
void print(PlanetCollection& planetCollection);
void save(PlanetCollection& planetCollection);
void exit(PlanetCollection& planetCollection);
void help();