#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "dru_lib_body.h"
using namespace std;

class weapon
{
	float damage;
public:
	weapon();
	~weapon();
	
};
class classic_W : weapon
{
public:
	classic_W();
	~classic_W();
	
};
class toxic_W : classic_W
{
public:
	toxic_W();
	~toxic_W();
	UP_damage(float size/*Размер персонажа*/);
};
class carabine_W : weapon
{
	float radius;
public:
	carabine_W();
	~carabine_W();
	
};
class shredder_W : public classic_W
{
public:
	shredder_W();
	~shredder_W();
	
};