#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "dru_lib_weapon.h"
using namespace std;

#ifndef pause
#define pause system("pause")
#endif
#ifndef N
#define N 4
#endif

template <typename T>
class minimap // Карта состоит из матрици маленьких квадратиков определённого размера
// Этот класс и есть маленьким квадратиком
{
	const float sizeX=/*...*/;
	const float sizeY=/*...*/;
	string cell;	// Имеет в себе слово, что означает вид ячейки:
	// обычная/можно спрятаться(очень маленький персонаж)/уронит персонажа/
	// исцеляет отравление/можно есть/временно повыщает покажатели/...
public:
	minimap();
	~minimap();
	void randCell();
	void NewCell();
};
class body
{
	// parameters
	float size_body; // При получении урона размер уменьшаетсяи и из тела выпадает еда
	float Speed;
	vector<string> privilages; // Пассивное действие на персонажа (яд, ...)
public:
	body();
	~body();
	void set_size_body(/*...*/);
	void set_damage(/*...*/);
	void set_Speed(/*...*/);
	void get_size_body();
	void get_damage();
	void get_Speed();
};
class food
{
	const float size;
public:
	food();
	~food();
	
};
class player //Нужно сделать меню выбора персонажа в main.cpp
{
	T *kind;	// Определим расу персонажа
public:
	player();
	~player();
	void istream &operator>>(istream &, player &);
	void ostream &operator<<(ostream &, player &);
};
class opponent
{
	T *kind;	// Определим расу персонажа
public:
	opponent(){
		randOpponent();
	};
	~opponent();
	void randOpponent();
};
// Рассы персонажей:
// Нужно сделать, что-бы персонажи отличались визуально
class toxic : body // Отравляет персонажа
{
	toxic_W weapon;
public:
	toxic();
	~toxic();
};
class speed : body // Может ускорятся, но теряет немного массы
{
	classic_W weapon;
public:
	speed();
	~speed();
	void UP_Speed(/*...*/);
};
class sniper : body
{
	carabine_W weapon;
public:
	sniper();
	~sniper();
	
};
class shredder : body // Наносит много урона
{
	shredder_W weapon;
public:
	shredder();
	~shredder();
	
};