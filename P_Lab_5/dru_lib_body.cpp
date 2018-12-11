#include "dru_lib_body.h"

void player::istream &operator>>(istream &in, player &object){

	return in;
}
void player::ostream &operator<<(ostream &out, player &object){

	return out;
}
void opponent::randOpponent(){
	srand(time(0));
	if(rand()%N==0)			this->T=new toxic();
	else if(rand()%N==1)	this->T=new speed();
	else if(rand()%N==2)	this->T=new sniper();
	else if(rand()%N==3)	this->T=new sredder();
}