#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>

class Humans {
private: 
	int amount_of_food;
public:
	Humans(){
		amount_of_food = (rand() % 99) + 1;
	}

	bool Is_feeding(bool weather){
		if(weather == true)
			return true;
		else
			return false;

	}

	int Feed_ducks(int temp){
		return (amount_of_food * 3 / (temp) ) ;
	}
};