#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase del cuarto
// ENUM

enum objetos_Cuarto
{
	NADA = 0,
	PISTA_UNO,
	PISTA_DOS,
	PISTA_TRES,
	PISTA_CUATRO,
	PISTA_CINCO,
	PISTA_VACIO
};

enum personas_Cuarto
{
	NADIE = 0,
	CARLOS_SALINAS,
	GOBERNADOR_MARGARITA,
	GOBERNADOR_ARISTOTELES,
	BOSS_DUARTE,
	GOBERNADOR_LEMUS,
	NINGUNA_PERSONA
};

enum NumSalones
{
	PARED = 0,
	SALON_UNO,
	SALON_DOS,
	SALON_TRES,
	SALON_CUATRO,
	SALON_CINCO,
	SALON_SEIS,
	SALON_SIETE,
	SALON_OCHO,
	SALON_NUEVE,
	SALON_DIEZ,
	SALON_ONCE,
	SALON_DOCE,
	SALON_TRECE
};

class Cuartos
{
public:
	string nombreSalon;
	string descripcionCuarto;
	string opcion_Direccion;
	string acciones;
	int numeroHabitacion;

	Cuartos(string nombre, string descripcion, string direcciones, string actions, NumSalones  numHabitacion, objetos_Cuarto objetos, personas_Cuarto gente);
	~Cuartos();

	// GETER : Se va a regresar el objeto que hay en un cuarto
	string Get_Item();
	string Get_Persona();

private:
	objetos_Cuarto Item;
	string Arreglo_Pistas[7] =
	{ "Nota personal de Lemus: Si tiene al menos  2 votos y una despensa,\n consideraria votar por esa persona.",
		"Nota personal de Duarte: Aunque tenga algunos problemitas eso no evitara que obtenga algo de ayuda con 1 politico, 1 cancion, 3 votos y 8 despensas para acarrear a los que me estan presionando.",
		"Nota personal de Aristoteles: Con mi antigua candidatura, sera dificil convencerme,\n talvez con 1 cancion pegajosa y 6 despensas votaria por ese representante.",
		"Nota personal de Margarita: Con lo que conozco de politica,\n no votaria por alguien con menos de 4 votos y 5 despansas.",
		"Nota de empleado: Los duenos del lugar son personas complicadas,\n creo que solo con todo lo que venden podrian votar por ese candidato.",
		"Aqui no hay nada mas que publicidad ajena .-." };

	personas_Cuarto Personas;
	string Arreglo_personas[7] = { "LEMUS: Me gusta un candidato capaz, que apoye y tenga votos.","DUARTE: Si lo apoyo a usted, es para que luego me de la mitad de su ganancia.","ARISTOTELES: Me gusta un gobierno que no engane.", "MARGARITA: Me gusta un candidato honesto.", "CARLOS SALINAS: Entre mas consuman de mis productos, mejor.",   "Aqui no se encuentra ninguna persona..." };
};

