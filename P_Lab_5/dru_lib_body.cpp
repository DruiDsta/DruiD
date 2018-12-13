#include "dru_lib_body.h"

void body::body(string *K){
	this->kind=K;
	this->size_body=start_size_body;
	this->Speed=start_speed;
}
void istream &operator>>(istream &in, body &object){

	return in;
}
void ostream &operator<<(ostream &out, body &object){

	return out;
}
void body::set_size_body(float *size){
	this->size_body=size;
}
void body::set_Speed(float *speed){
	this->Speed=speed;
}
void body::get_size_body(){
	return this->size_body;
}
void body::get_Speed(){
	return this->Speed;
}

// lolololololololololololololololololollolololo
// lololololololololololololoolololololololololo

void food::food(float *_x, float *_y){
	this->position.first=_x;
	this->position.second=_y;
}

// lolololololololololololololololololollolololo
// lololololololololololololoolololololololololo

void player::player(float *_x, float *_y){
	this->position.first=_x;
	this->position.second=_y;
}
void player::istream &operator>>(istream &in, player &object){

	return in;
}
void player::ostream &operator<<(ostream &out, player &object){

	return out;
}

// lolololololololololololololololololollolololo
// lloloollolololololololololololololololololo

void opponent::opponent(float *_x, float *_y){
	this->position.first=_x;
	this->position.second=_y;
	randOpponent();
}
void opponent::randOpponent(){
	switch(1+rand()%N_T){
		case 1:{this->kind=toxic; break;}
		case 2:{this->kind=speed; break;}
		case 3:{this->kind=sniper; break;}
		case 4:{this->kind=sredder; break;}
		case 5:{this->kind=Anton; break;}
	}
}