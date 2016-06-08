#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "Duck.h"
#include "Humans.h"
#include "GM.h"

using namespace std;

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
				
				ducks[hungerst_duck[1]]->eat();
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