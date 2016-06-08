#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>

class GM{
private:
	int day_counter;
	int temp;
	bool is_sunny;
public:
	GM(){
		day_counter = 0;
		temp = (rand() % 20 ) + 10;
		if(((rand() % 2 ) + 0) == 1 )
			is_sunny = true;
		else
			is_sunny = false;
	}

	void Report(){
		cout << "Day :"<< day_counter << " Weather :" << temp << " *C ";
		if (is_sunny == true)
			cout << ", Sunny \n";
		else
			cout << ", Rainy \n";

	}
	void Add_day(){
		day_counter ++;
	}

	void Set_weather(){
		temp = (rand() % 20 ) + 10;
		if(((rand() % 2 ) + 0) == 1 )
			is_sunny = true;
		else
			is_sunny = false;

	}

	int Exp_temp(){return temp;}
	bool Exp_weather(){return is_sunny;}

};