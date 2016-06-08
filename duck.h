#pragma once
#include "duck.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class Duck {
private:
	int hp;
	int gender;
	int hunger;
	int charm;
	int vitality;
	int protection;
	int repro;
	int social_relations;
public:
	int CreatDuck ();
	Duck();
};