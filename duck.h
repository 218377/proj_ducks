#pragma once

#include <cstdlib>
#include <cstdio>
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
	int social_relations;
	bool is_live;
public:
	
	Duck(){
		hp = (rand() % 90 ) + 10;
		gender = (rand() % 2 ) + 0;
		hunger = (rand() % 30 ) + 50;
		charm = (rand() % 100 ) + 0;
		vitality = (rand() % 100 ) + 0;
		protection = (rand() % 100 ) + 0;
		social_relations = (rand() % 100) + 0;
		is_live = true;
	};
	void Duck_status(){
		cout << "HP :"<< hp << " Gender :" << gender << " Hunger : "<< hunger << " Charm :" << charm << " Vitality : "<< hp << " Protection :" << protection << " Social Relations: " << social_relations << "\n";
	}
	bool Is_live(){
		return is_live;
	}

	int Hp(){
		return hp;
	}

	int Hunger(){
		return hunger;
	}

	void eat(){
		hunger --;
	}

	void Hunger_inc(){
		hunger++;
	}

	void Hp_dsc(){
		if(hunger >= 80)
			hp = hp - hunger/20;
	}

	void Dead(){
		if(hp <= 0)
			is_live = false;
	}
	int Gender(){return gender;}
	int Vitality(){return vitality;}

	bool Try_repro(int vit_0, int vit_1){
		if(vit_0 > 50 && vit_1>50){
			if(((rand() % 100) + 0) >= 50)
				return true;
			else
				return false;
		}
		return false;
	}
};