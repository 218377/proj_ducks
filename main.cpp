#include "cstdlib"
#include <cstdio>
#include <iostream>

using namespace std;
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

	int Get_food(){
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

int main(int argc, char const *argv[]){
	srand( time( NULL ) );
	int number_of_ducks = (rand() % 3) + 2;
	Duck *ducks[5];
	GM *game_master = new GM;
	for(int i = 0;i <= (4);i++){
		ducks[i] = new Duck;
	};
	bool end = false;
	while(end != true){
		//weather changing and data display section
		game_master -> Set_weather();
		game_master -> Report();
		bool game_over = true;
		for (int i = 0; i <= 4; i++){
			if((ducks[i]->Is_live()) == true)
			{
				cout << "Duck no. " << (i+1) <<endl;
				ducks[i] -> Duck_status();
				game_over = false;
			};
		}
		if(game_over == true )
			return 0;
		//feeding duck section
		Humans *human = new Humans;
		if(human -> Is_feeding(game_master->Exp_weather()) == true){	
			int food = human -> Feed_ducks(game_master -> Exp_temp() );
			


			for(int f = 0; f <= food; f++){
				int hungerst_duck[2];
				
				for (int a = 0; a < 5; ++a)
				{
					if(hungerst_duck[0] < ducks[a]->Hunger()){
					hungerst_duck[1] = a;
					hungerst_duck[0] = ducks[a]->Hunger();		
					};			
				};
				
				ducks[hungerst_duck[1]]->Get_food();
			};
		};
		delete human;

		//life function section
		for(int i = 0;i <= 4; i++){
			ducks[i]->Hunger_inc();
			ducks[i]->Hp_dsc();
			ducks[i]->Dead();
		}
		//repro section
		
		int repro_ducks[2] = {9,9};
		for(int i = 0;i <= 4; i++){
			if(ducks[i]->Is_live() == false){

				for(int a = 0;a <= 4; a++){
					if(ducks[a]->Is_live()==true && ducks[a]->Gender() == 0)
						repro_ducks[0] = a;
					if(ducks[a]->Is_live()==true && ducks[a]->Gender() == 1)
						repro_ducks[1] = a;
				}

				if(repro_ducks[0] != 9 && repro_ducks[1] != 9){
					if(ducks[repro_ducks[0]]->Try_repro(ducks[repro_ducks[0]]->Vitality(),ducks[repro_ducks[1]]->Vitality()) == true){
						delete ducks[i];
						ducks[i] = new Duck;
					}

				}

			}
		}
		

		getchar();
		game_master -> Add_day();
	};


}