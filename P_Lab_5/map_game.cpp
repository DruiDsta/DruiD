#include "map_game.h"

void mimimap::minimap(){
	randCell();
}
void minimap::randCell(){
	switch(rand()%N_M){
		case 1:{this->cell=shelter; break;}
		case 2:{this->cell=danger; break;}
		case 3:{this->cell=support; break;}
		case 4:{this->cell=food_map; break;}
		case 5:{this->cell=steroids; break;}
		default: this->cell=NUB;
	}
}