#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <cmath>
#include "map_game.h"
#include <SFML/Graphics.hpp>
using namespace std;

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
	pair<float, float> position;
public:
	body();
	~body();
	vector<string> privilages; // Пассивное действие на персонажа (яд, ...)
	void set_size_body(float *);
	void set_Speed(float *);
	void set_position(float *, float *);
	float get_size_body();
	float get_Speed();
	pair<float, float> get_position();
	friend istream &operator>>(istream &, body &);
	friend ostream &operator<<(ostream &, body &);
	void attack(body *);
	int WhSegX();
	int WhSegY();
};
class food
{
	pair<float, float> position;
public:
	food(float *, float *);
	~food();
	// есть задифайнина хрень size_food забей нужное значение туда и юзай size_food
};
template <typename T> class player //Нужно сделать функцию меню выбора персонажа
{
	T *kind;
public:
	player();
	~player();
};
template <typename T> class opponent
{
	T *kind;
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
	food UP_Speed();
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

float distance(pair<float, float> *PL, pair<float, float> *OP);
template <typename T> bool dist_attack(T PL, T OP);

