#include "dru_lib_body.h"

body::body(){
	this->size_body=start_size_body;
	this->Speed=normal_speed;
}
void body::set_size_body(float *size){
	this->size_body=*size;
}
void body::set_Speed(float *sp){
	this->Speed=*sp;
}
void body::set_position(float *f, float *s){
	this->position.first=*f;
	this->position.second=*s;
}
float body::get_size_body(){
	return this->size_body;
}
float body::get_Speed(){
	return this->Speed;
}
point body::get_position(){
	return this->position;
}
istream &operator>>(istream &in, body &object){

	return in;
}
ostream &operator<<(ostream &out, body &object){

	return out;
}
void body::attack(body *OP){
	if(dist_attack(*this, *OP)){

	}
}


// lolololololololololololololololololollolololo
// lololololololololololololoolololololololololo

food::food(float *_x, float *_y){
	this->position.first=*_x;
	this->position.second=*_y;
}

// lolololololololololololololololololollolololo
// lololololololololololololoolololololololololo

player::player(){

}
/*void player::istream &operator>>(istream &in, player &object){

	return in;
}
void player::ostream &operator<<(ostream &out, player &object){

	return out;
}*/

// lolololololololololololololololololollolololo
// lloloollolololololololololololololololololo

opponent::opponent(){
	randOpponent();
}
void opponent::randOpponent(){
	switch(1+rand()%N_T){
		case 1:{this->kind=new toxic(); break;}
		case 2:{this->kind=new speed(); break;}
		case 3:{this->kind=new sniper(); break;}
		case 4:{this->kind=new shredder(); break;}
		case 5:{this->kind=new Anton(); break;}
		case 6:{this->kind=new AIDS(); break;}
	}
}

// lolololololololololololololololololollolololo
// lloloollolololololololololololololololololo

toxic::toxic(){

}
void toxic::attack(body *OP){
	if(dist_attack(*this, *OP))	OP->privilages.push_back(TOXIC);
	body::attack(OP);
}

speed::speed(){

}
food speed::UP_Speed(){
	//this->size_body--;
	food *result=new food();
	return *result;
}

sniper::sniper(){

}
void sniper::attack(body *OP){
	float dist_shot=3*body::get_size_body();
}

shredder::shredder(){

}

Anton::Anton(){

}

void AIDS::AIDS(){

}

float distance(point *PL, point *OP){

}
bool dist_attack(body PL, body OP){
	if(distance(PL.get_position(), OP.get_position())
		<=(OP.get_size_body()+PL.get_size_body()))	return true;
	else return false;
}
