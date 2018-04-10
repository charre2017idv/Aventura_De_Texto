#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jugador
{
public:
	// VARIABLE
	string NombreJugador;
	int dinero;

	Jugador(string nombre, int coins);
	~Jugador();


	// SETER
	void Set_Inventory(string items);

	// GETER
	void  Get_Inventory();


private:
	vector <string> Inventario;
};

