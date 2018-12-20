#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "dru_lib_body.h"
using namespace std;

#ifndef N_M
#define N_M 5
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
#ifndef h
#define h 10
#endif

typedef struct tegMM
{
	pair<float, float> center;
	pair<string, float> cell;		// Имеет в себе слово, что означает вид ячейки:
}MM;

template <typename T> class minimap // Карта состоит из матрици маленьких квадратиков определённого размера
{
	const float sizeX;
	const float sizeY;
	MM segment[99][99];
	// обычная/можно спрятаться(очень маленький персонаж)/уронит персонажа/
	// исцеляет отравление/можно есть/временно повыщает покажатели/...
public:
	minimap();
	~minimap();
	MM generation_segment(float *, float *);
	template <typename T> void action(T *);
	string randCell();
	string getCELL(int *, int *);
	void del_tox(vector<string>);
	void dam(T *, MM *);
	// void NewCell();
};
template <typename T> bool dist_action(T *PL, MM *M);
