#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef N_M
#define N_M 6
#endif
#ifndef NUB
#define NUB "0"
#endif
#ifndef shelter
#define shelter "shelter"
#endif
#ifndef danger
#define danger "danger"
#endif
#ifndef support
#define support "support"
#endif
#ifndef food_map
#define food_map "F_M"
#endif
#ifndef steroids
#define steroids "steroids"
#endif
#ifndef h
#define h 2.5
#endif

typedef struct tegMM
{
	pair<float, float> center;
	pair<string, float> cell;		// Имеет в себе слово, что означает вид ячейки:
}MM;

class minimap // Карта состоит из матрици маленьких квадратиков определённого размера
// Этот класс и есть маленьким квадратиком
{
	const float sizeX/*=...*/;
	const float sizeY/*=...*/;
	MM segment[500][500];
	// обычная/можно спрятаться(очень маленький персонаж)/уронит персонажа/
	// исцеляет отравление/можно есть/временно повыщает покажатели/...
public:
	minimap();
	~minimap();
	MM generation_segment(float *, float *);
	void action(/*...*/);
	string randCell();
	string getCELL(int *, int *);
	void NewCell();
};