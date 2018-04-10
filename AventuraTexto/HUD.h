#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HUD
{
public:
	/* Variables lagunas legales */
	float dinero_Jugador = 150;
	int popularidad = 0;
	int seguidores = 0;
	int votos = 0;
	int despensas = 0;
	int politicos = 0;
	int cumplidos = 0;		// Si se llega a un cierto numero de cumplidos de otorgaran 3 votos
	int Canciones = 0;

	HUD(float money, int popularity, int followers, int votes, int storeroom, int politicians, int compliments, int songs);
	~HUD();
};

