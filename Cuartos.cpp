#include "Cuartos.h"



Cuartos::Cuartos(string nombre, string descripcion, string direcciones, string actions, NumSalones  numHabitacion, objetos_Cuarto objetos, personas_Cuarto gente)
{
	nombreSalon = nombre;
	descripcionCuarto = descripcion;
	opcion_Direccion = direcciones;
	acciones = actions;
	numeroHabitacion = numHabitacion;
	Item = objetos;
	Personas = gente;
}


Cuartos::~Cuartos()
{
}


// METODOS

string Cuartos::Get_Item()
{
	return Arreglo_Pistas[Item - 1];
}

string Cuartos::Get_Persona()
{
	return Arreglo_personas[Item - 1];
}
