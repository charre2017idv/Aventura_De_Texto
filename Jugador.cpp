#include "Jugador.h"



Jugador::Jugador(string nombre, int coins)
{
	NombreJugador = nombre;
	dinero = coins;
}


Jugador::~Jugador()
{
}

// METODOS

// Se agregan datos al inventario
void Jugador::Set_Inventory(string items)
{
	cout << endl;
	cout << "* Escribiendo en el block de notas... *" << endl;
	cout << "Se ha agregado '" << items << "' al inventario" << endl;
	cout << endl;
	Inventario.push_back(items);
}

// Se muestran los datos del inventario
void Jugador::Get_Inventory()
{
	cout << endl;
	cout << "Inventario: {";
	for (int i = 0; i < Inventario.size(); i++)
	{
		cout << Inventario[i] << ", ";
	}
	cout << "}" << endl;
	cout << endl;
}
