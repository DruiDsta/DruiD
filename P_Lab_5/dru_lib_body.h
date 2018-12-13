#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef point
#define point pair<float,float>
#endif
#ifndef pause
#define pause system("pause")
#endif
#ifndef N_T
#define N_T 5
#endif
#ifndef size_food
#define size_food 5
#endif
#ifndef start_size_body
#define start_size_body 15
#endif
#ifndef normal_speed
#define normal_speed 0.5
#endif
#ifndef toxic
#define toxic "toxic"
#endif
#ifndef speed
#define speed "speed"
#endif
#ifndef sniper
#define sniper "sniper"
#endif
#ifndef shredder
#define shredder "shredder"
#endif
#ifndef Anton
#define Anton "Anton"
#endif


template <typename T>
class body
{
	// parameters
	float size_body; // При получении урона размер уменьшаетсяи и из тела выпадает еда
	float Speed;
	float damage;
protected:
	string kind;
	vector<string> privilages; // Пассивное действие на персонажа (яд, ...)
public:
	body(string *);
	~body();
	void set_size_body(float *);
	void set_Speed(float *);
	void get_size_body();
	void get_Speed();
	void istream &operator>>(istream &, body &);
	void ostream &operator<<(ostream &, body &);
};
class food
{
	point position;
public:
	food(float *, float *);
	~food();
	// есть задифайнина хрень size_food забей нужное значение туда и юзай size_food
};
class player : body //Нужно сделать функцию меню выбора персонажа
{
	point position;
public:
	player(float *, float *);
	~player();
	void istream &operator>>(istream &, player &);
	void ostream &operator<<(ostream &, player &);
};
class opponent : body
{
	point position;
public:
	opponent(float *, float *);
	~opponent()	{delete kind;}
	void randOpponent();
};
