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
#define N_T 6
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
#ifndef TOXIC
#define TOXIC "TOXIC"
#endif

class body
{
	// parameters
	float size_body; // При получении урона размер уменьшаетсяи и из тела выпадает еда
	float Speed;
	point position;
public:
	body();
	~body();
	vector<string> privilages; // Пассивное действие на персонажа (яд, ...)
	void set_size_body(float *);
	void set_Speed(float *);
	void set_position(float *, float *);
	float get_size_body();
	float get_Speed();
	point get_position();
	friend istream &operator>>(istream &, body &);
	friend ostream &operator<<(ostream &, body &);
	virtual void attack(body *);

};
class food
{
	point position;
public:
	food(float *, float *);
	~food();
	// есть задифайнина хрень size_food забей нужное значение туда и юзай size_food
};
class player //Нужно сделать функцию меню выбора персонажа
{
	body *kind;
public:
	player();
	~player();
};
class opponent
{
	body *kind;
public:
	opponent();
	~opponent();
	void randOpponent();
};
// Рассы персонажей:
// Нужно сделать, что-бы персонажи отличались визуально
class toxic : public body // Отравляет персонажа
{
public:
	toxic();
	~toxic();
	void attack(body *);
};
class speed : public body // Может ускорятся, но теряет немного массы
{
public:
	// в функции передвижения сделать двойное передвижение
	// и в ней вызывать UP_speed()
	speed();
	~speed();
	food UP_Speed(/*...*/);
};
class sniper : public body
{
	float damage;
public:
	sniper();
	~sniper();
	void attack(body *);
};
class shredder : public body // Наносит много урона
{
public:
	shredder();
	~shredder();
};
class Anton : public body
{
public:
	Anton();
	~Anton();

};
class AIDS : public body
{
public:
	AIDS();
	~AIDS();

};

float distance(body *PL, body *OP);
bool dist_attack(body PL, body OP);
