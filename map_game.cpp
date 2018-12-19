#include "map_game.h"

mimimap::minimap(){
	for (int i = 0, float n = 2.5; i < 500; ++i, n+=h){
		for (int j = 0, float m = 2.5; j < 500; ++j, m+=h){
			segment[i][j] = generation_segment(*n, *m);
		}
	}
	// randCell();
}
MM generation_segment(float *Pn, float *Pm){
	MM result;
	result.center.first = Pn;
	result.center.second = Pm;
	result.cell.first = randCell();
	if(result.cell.first != NUB)	result.cell.second = 2;
	else result.cell.second = 0;
	return result;
}
void action(/*...*/){
	
}
string minimap::randCell(){
	string result;
	switch(rand()%N_M){
		case 1:{result = shelter;	break;}
		case 2:{result = danger;	break;}
		case 3:{result = support;	break;}
		case 4:{result = food_map;	break;}
		case 5:{result = steroids;	break;}
		default: result = NUB;
	}
	return result;
}
string getCELL(int *n, int *m){
	return this->segment[n][m].cell.first;
}