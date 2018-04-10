// TEMA: AVENTURA DE TEXTO 2.0
#include<iostream>
#include <string>
#include <vector>
#include "Cuartos.h"
#include "Jugador.h"
#include "HUD.h"
using namespace std;

// Se declara los espacios en el array para recorrer la matriz
int Mapa_Escuela[5][11] =

{ { 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 },

{ 0, 1, 0, 2, 0, 0,  0,  0,  0,  0 }, // Se inicializa en la segunda posicion

{ 0, 3, 4, 5, 8, 9,  11, 12, 13, 0 },

{ 0, 6, 0, 7, 0, 10, 0,  0,  0,  0 },

{ 0, 0, 0, 0, 0, 0,  0,  0,  0,  0 }
};

// Variables del Juego

/* Se inicializa la posicion actual */
int columna_Y = 1;
int fila_X = 1;

/* Variable de opciones de comandos */
string opcion;
string opcionesMenu;
string nombre;
string Accion;			// Acciones como: 'ir', 'examinar', 'guardar', 'salir', 'ver', 'intentar'
string instruccion;		// Instrucciones como: 'norte', 'sur', 'este', 'oeste', 'salon1', 'pasillo1', 'inventario', 'brujula', 'instrucciones', 'partida', 'hablar'

						/* Variables lagunas legales */
float dinero_Jugador = 200;
int popularidad = 0;
int seguidores = 0;
int votos = 0;
int despensas = 0;
int politicos = 0;
int cumplidos = 0;		// Si se llega a un cierto numero de cumplidos de otorgaran 3 votos
int Canciones = 0;

bool convencido_Salon1 = false;
int votos_Salon1 = 0;
int votos_Salon2 = 0;
int votos_Salon6 = 0;
int votos_Salon7 = 0;
int votos_Salon10 = 0;
// SALONES

// si mapa(fila x columna) && 'palabra' en arreglo, se ejecuta el paso de cuarto4
void SALON_1() // Para conseguir el seguidor se requiere de 2 votos y 1 despensa, $90 pesos
{
	if (Mapa_Escuela[fila_X][columna_Y] == 1)
	{
		Cuartos Salon_1(string("Salon 1"), string("En este salon se encuentra el representante de Zapopan."), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_UNO, objetos_Cuarto::PISTA_UNO, personas_Cuarto::GOBERNADOR_LEMUS);
		cout << "Nombre del salon: " << Salon_1.nombreSalon << endl;
		cout << "Descripcion: " << Salon_1.descripcionCuarto << endl;
		cout << "Direcciones: " << Salon_1.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Salon_1.acciones << endl;
		cout << "Numero Cuarto: " << Salon_1.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 1 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Salon_1(string("Salon 1"), string("En este salon se encuentra el representante de Zapopan."), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_UNO, objetos_Cuarto::PISTA_UNO, personas_Cuarto::GOBERNADOR_LEMUS);
		cout << Salon_1.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 1 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Salon_1(string("Salon 1"), string("En este salon se encuentra el representante de Zapopan."), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_UNO, objetos_Cuarto::PISTA_UNO, personas_Cuarto::GOBERNADOR_LEMUS);
		cout << Salon_1.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 1 && Accion == "convencer" && instruccion == "publico" && dinero_Jugador >= 10 && votos >= 2 && despensas >= 1 && votos_Salon1 <= 0)
	{
		seguidores += 1;
		dinero_Jugador += 50;
		votos_Salon1 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
		convencido_Salon1 = true;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 1 && Accion == "convencer" && instruccion == "publico" && votos < 2 && despensas < 1)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL PUBLICO */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 1 && Accion == "convencer" && instruccion == "publico" && votos_Salon1 >= 1 && votos >= 2 && despensas >= 1)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}

} // en caso de qu requiera contrasena hacer comprobacion // (1)
void SALON_2() // Para conseguir al seguidor se requiere
{
	if (Mapa_Escuela[fila_X][columna_Y] == 2)
	{
		Cuartos Salon_2(string("Salon 2"), string("Actualmente tiene problemas en el paraiso...  (fiscal)"), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DOS, objetos_Cuarto::PISTA_DOS, personas_Cuarto::BOSS_DUARTE);
		cout << "Nombre del salon: " << Salon_2.nombreSalon << endl;
		cout << "Descripcion: " << Salon_2.descripcionCuarto << endl;
		cout << "Direcciones: " << Salon_2.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Salon_2.acciones << endl;
		cout << "Numero Cuarto: " << Salon_2.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 2 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Salon_2(string("Salon 2"), string("Actualmente tiene problemas en el paraiso...  (fiscal)"), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DOS, objetos_Cuarto::PISTA_DOS, personas_Cuarto::BOSS_DUARTE);
		cout << Salon_2.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 2 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Salon_2(string("Salon 2"), string("Actualmente tiene problemas en el paraiso...  (fiscal)"), string("Sur"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DOS, objetos_Cuarto::PISTA_DOS, personas_Cuarto::BOSS_DUARTE);
		cout << Salon_2.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 2 && Accion == "convencer" && instruccion == "publico" && dinero_Jugador >= 10 && politicos >= 1 && despensas >= 8 && votos_Salon2 <= 0)
	{
		seguidores += 1;
		dinero_Jugador += 50;
		votos_Salon2 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 2 && Accion == "convencer" && instruccion == "publico" && politicos < 1 && despensas < 8)
	{
		dinero_Jugador -= 25;
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL PUBLICO */" << endl;
		cout << "/* DUARTE TE A ROBADO $25 PESOS.*/" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 2 && Accion == "convencer" && instruccion == "publico" && votos_Salon2 >= 1 && politicos >= 1 && despensas >= 8)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
} // (4)
void SALON_6()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 6)
	{
		Cuartos Salon_6(string("Salon 6"), string("Es el 'gran' representante de Guadalajara."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SEIS, objetos_Cuarto::PISTA_TRES, personas_Cuarto::GOBERNADOR_ARISTOTELES);
		cout << "Nombre del salon: " << Salon_6.nombreSalon << endl;
		cout << "Descripcion: " << Salon_6.descripcionCuarto << endl;
		cout << "Direcciones: " << Salon_6.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Salon_6.acciones << endl;
		cout << "Numero Cuarto: " << Salon_6.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 6 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Salon_6(string("Salon 6"), string("Hay una nota en el suelo."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SEIS, objetos_Cuarto::PISTA_TRES, personas_Cuarto::GOBERNADOR_ARISTOTELES);
		cout << Salon_6.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 6 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Salon_6(string("Salon 6"), string("Hay una nota en el suelo."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SEIS, objetos_Cuarto::PISTA_TRES, personas_Cuarto::GOBERNADOR_ARISTOTELES);
		cout << Salon_6.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 6 && Accion == "convencer" && instruccion == "publico" && dinero_Jugador >= 10 && Canciones >= 1 && despensas >= 6 && votos_Salon6 <= 0)
	{
		seguidores += 1;
		dinero_Jugador += 50;
		votos_Salon6 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 6 && Accion == "convencer" && instruccion == "publico" && Canciones < 1 && despensas < 6)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL PUBLICO */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 6 && Accion == "convencer" && instruccion == "publico" && votos_Salon6 >= 1 && Canciones >= 1 && despensas >= 6)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
} // (3)
void SALON_7() // Para conseguir al seguidor se requiere 4 votos y 5 despensas, $210 pesos
{
	if (Mapa_Escuela[fila_X][columna_Y] == 7)
	{
		Cuartos Salon_7(string("Salon 7"), string("Esta en su segunda propuesta de campana."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SIETE, objetos_Cuarto::PISTA_CUATRO, personas_Cuarto::GOBERNADOR_MARGARITA);
		cout << "Nombre del salon: " << Salon_7.nombreSalon << endl;
		cout << "Descripcion: " << Salon_7.descripcionCuarto << endl;
		cout << "Direcciones: " << Salon_7.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Salon_7.acciones << endl;
		cout << "Numero Cuarto: " << Salon_7.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 7 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Salon_7(string("Salon 7"), string("Esta en su segunda propuesta de campana."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SIETE, objetos_Cuarto::PISTA_CUATRO, personas_Cuarto::GOBERNADOR_MARGARITA);
		cout << Salon_7.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 7 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Salon_7(string("Salon 7"), string("Esta en su segunda propuesta de campana."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_SIETE, objetos_Cuarto::PISTA_CUATRO, personas_Cuarto::GOBERNADOR_MARGARITA);
		cout << Salon_7.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 7 && Accion == "convencer" && instruccion == "publico" && dinero_Jugador >= 10 && votos >= 4 && despensas >= 5 && votos_Salon7 <= 0)
	{
		seguidores += 1;
		dinero_Jugador += 50;
		votos_Salon7 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 7 && Accion == "convencer" && instruccion == "publico" && votos < 4 && despensas < 5)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL PUBLICO */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 7 && Accion == "convencer" && instruccion == "publico" && votos_Salon7 >= 1 && votos >= 4 && despensas >= 5)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}

} // (2)
void SALON_10() // Tienda - Para conseguir su voto se requieren 150 pesos para que sobren 10 pesos, necesitan mas de 3 cosas compradas de cada uno 
{
	if (Mapa_Escuela[fila_X][columna_Y] == 10)
	{
		Cuartos Salon_10(string("Politics - Shop"), string("Se dice que los duenos vienen de Rusia."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DIEZ, objetos_Cuarto::PISTA_CINCO, personas_Cuarto::PROFESOR_CAPUCHINO);
		cout << "Nombre del salon: " << Salon_10.nombreSalon << endl;
		cout << "Descripcion: " << Salon_10.descripcionCuarto << endl;
		cout << "Direcciones: " << Salon_10.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Salon_10.acciones << endl;
		cout << "Numero Cuarto: " << Salon_10.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Salon_10(string("Politics - Shop"), string("Se dice que los duenos vienen de Rusia."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DIEZ, objetos_Cuarto::PISTA_CINCO, personas_Cuarto::PROFESOR_CAPUCHINO);
		cout << Salon_10.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Salon_10(string("Politics - Shop"), string("Se dice que los duenos vienen de Rusia."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DIEZ, objetos_Cuarto::PISTA_CINCO, personas_Cuarto::PROFESOR_CAPUCHINO);
		cout << Salon_10.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "ver" && instruccion == "tienda")
	{
		Cuartos Salon_10(string("Politics - Shop"), string("Los duenos del lugar vienen de otro pais."), string("Norte"), string("examinar salon, intentar hablar, convencer publico"), NumSalones::SALON_DIEZ, objetos_Cuarto::PISTA_CINCO, personas_Cuarto::PROFESOR_CAPUCHINO);
		cout << "Bienvenido a la tienda 'Compra Votos'." << endl;

		cout << endl;
		cout << "===============================================================================" << endl;
		cout << "===========             Bienvenido al Politics - Shop              ============" << endl;
		cout << "===============================================================================" << endl;
		cout << "= 1) Si desea comprar politicos $60.........\tESCRIBA 'comprar + politicos'.=" << endl; // Se agregan 5 puntos al marcador de ganar
		cout << "= 2) Si desea comprar votos     $40.........\tESCRIBA 'comprar + votos'.    =" << endl; // Se agregan 3 puntos al marcador de ganar
		cout << "= 3) Si desea comprar canciones $30.........\tESCRIBA 'comprar + cancion'.  =" << endl; // Se agregan 2 puntos al marcador de ganar
		cout << "= 4) Si desea comprar despensas $10.........\tESCRIBA 'comprar + despensas'.=" << endl; // Se agregan 1 punto al marcador de ganar
		cout << "===============================================================================" << endl;
		cout << endl;
	}
	// Comprar Politicos + 5 puntos al marcador de ganar
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "comprar" && instruccion == "politicos" && dinero_Jugador > 0)
	{
		dinero_Jugador -= 60;
		popularidad += 5;
		politicos += 1;
		cout << "/* HAS COMPRADO UN POLITICO */" << endl;
	}
	// Comprar Votos + 3 puntos al marcador de ganar
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "comprar" && instruccion == "votos" && dinero_Jugador > 0)
	{
		dinero_Jugador -= 40;
		popularidad += 3;
		votos += 1;
		cout << "/* HAS COMPRADO UN VOTO */" << endl;
	}
	// Comprar Cancion + 2 puntos al marcador de ganar
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "comprar" && instruccion == "cancion" && dinero_Jugador > 0)
	{
		dinero_Jugador -= 30;
		popularidad += 2;
		Canciones += 1;
		cout << "/* HAS COMPRADO UNA CANCION */" << endl;
	}
	// Comprar despensas + 1 punto al marcador de ganar
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "comprar" && instruccion == "despensas" && dinero_Jugador > 0)
	{
		dinero_Jugador -= 10;
		popularidad += 1;
		despensas += 1;
		cout << "/* HAS COMPRADO UNA DESPENSA: */" << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "convencer" && instruccion == "publico" && dinero_Jugador >= 10 && votos >= 3 && politicos >= 3 && Canciones >= 3 && despensas >= 3 && votos_Salon10 <= 0)
	{
		seguidores += 1;
		dinero_Jugador += 50;
		votos_Salon10 += 1;
		cout << endl;
		cout << "/* FELICIDADES TIENES UN NUEVO SEGUIDOR */" << endl;
		cout << "/* Se Otorgan 50 pesos mas al fondo de la campana electoral */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "convencer" && instruccion == "publico" && votos < 3 && politicos < 3 && Canciones < 3 && despensas < 3)
	{
		cout << endl;
		cout << "/* NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA CONVENCER AL PUBLICO */" << endl;
		cout << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 10 && Accion == "convencer" && instruccion == "publico" && votos_Salon10 >= 1 && politicos >= 1 && despensas >= 8)
	{
		cout << endl;
		cout << "/* YA TIENES A ESTE SEGUIDOR */" << endl;
		cout << endl;
	}
}

// PASILLOS
void PASILLO_1()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 3)
	{
		Cuartos Pasillo_1(string("Pasillo 1"), string("Casilleros alrededor"), string("Norte, Sur, Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRES, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_1.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_1.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_1.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_1.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_1.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 3 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_1(string("Pasillo 1"), string("Casilleros alrededor"), string("Norte, Sur, Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRES, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_1.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 3 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_1(string("Pasillo 1"), string("Casilleros alrededor"), string("Norte, Sur, Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRES, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_1.Get_Persona() << endl;
	}
}
void PASILLO_2()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 4)
	{
		Cuartos Pasillo_2(string("Pasillo 2"), string("Casilleros alrededor."), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CUATRO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_2.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_2.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_2.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_2.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_2.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 4 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_2(string("Pasillo 2"), string("Casilleros alrededor."), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CUATRO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_2.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 4 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_2(string("Pasillo 2"), string("Casilleros alrededor."), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CUATRO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_2.Get_Persona() << endl;
	}
}
void PASILLO_3()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 5)
	{
		Cuartos Pasillo_3(string("Pasillo 3"), string("Casilleros alrededor"), string("Norte, Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CINCO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_3.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_3.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_3.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_3.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_3.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 5 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_3(string("Pasillo 3"), string("Casilleros alrededor"), string("Norte, Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CINCO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_3.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 5 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_3(string("Pasillo 3"), string("Casilleros alrededor"), string("Norte, Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_CINCO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_3.Get_Persona() << endl;
	}
}
void PASILLO_4()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 8)
	{
		Cuartos Pasillo_4(string("Pasillo 4"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_OCHO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_4.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_4.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_4.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_4.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_4.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 8 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_4(string("Pasillo 4"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_OCHO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_4.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 8 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_4(string("Pasillo 4"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_OCHO, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_4.Get_Persona() << endl;
	}
}
void PASILLO_5()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 9)
	{
		Cuartos Pasillo_5(string("Pasillo 5"), string("Casilleros alrededor"), string("Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_NUEVE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_5.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_5.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_5.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_5.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_5.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 9 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_5(string("Pasillo 5"), string("Casilleros alrededor"), string("Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_NUEVE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_5.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 9 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_5(string("Pasillo 5"), string("Casilleros alrededor"), string("Sur, Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_NUEVE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_5.Get_Persona() << endl;
	}
}
void PASILLO_6()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 11)
	{
		Cuartos Pasillo_6(string("Pasillo 6"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_ONCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_6.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_6.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_6.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_6.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_6.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 11 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_6(string("Pasillo 6"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_ONCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_6.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 11 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_6(string("Pasillo 6"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_ONCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_6.Get_Persona() << endl;
	}
}
void PASILLO_7()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 12)
	{
		Cuartos Pasillo_7(string("Pasillo 7"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_DOCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_7.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_7.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_7.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_7.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_7.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 12 && Accion == "examinar" && instruccion == "pasillo")
	{
		Cuartos Pasillo_7(string("Pasillo 7"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_DOCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Objeto en el cuarto: " << Pasillo_7.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 12 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_7(string("Pasillo 7"), string("Casilleros alrededor"), string("Este, Oeste"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_DOCE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_7.Get_Persona() << endl;
	}
}
void PASILLO_8()
{
	if (Mapa_Escuela[fila_X][columna_Y] == 13)
	{
		Cuartos Pasillo_8(string("Congreso de postulados"), string("En este lugar se decide quien sera elegido."), string("Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRECE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << "Nombre del salon: " << Pasillo_8.nombreSalon << endl;
		cout << "Descripcion: " << Pasillo_8.descripcionCuarto << endl;
		cout << "Direcciones: " << Pasillo_8.opcion_Direccion << endl;
		cout << "Acciones que se pueden realizar: " << Pasillo_8.acciones << endl;
		cout << "Numero Cuarto: " << Pasillo_8.numeroHabitacion << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 13 && Accion == "examinar" && instruccion == "salon")
	{
		Cuartos Pasillo_8(string("Pasillo 8"), string("En este lugar se decide quien sera elegido."), string("Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRECE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_8.Get_Item() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 13 && Accion == "intentar" && instruccion == "hablar")
	{
		Cuartos Pasillo_8(string("Pasillo 8"), string("En este lugar se decide quien sera elegido."), string("Este"), string("examinar pasillo, intentar hablar"), NumSalones::SALON_TRECE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
		cout << Pasillo_8.Get_Persona() << endl;
	}
	if (Mapa_Escuela[fila_X][columna_Y] == 13 && Accion == "convencer" && instruccion == "publico" && popularidad <= 100 && seguidores <= 3)
	{
		cout << "/*  NO CUENTAS CON LOS REQUISITOS NECESARIOS PARA SER ELEGIDO COMO REPRESENTANTE. */" << endl;
	}
}

// FUNCIONES DEL JUEGO

void Historia()
{
	cout << "Campana Electoral 2018" << endl;
	cout << endl;
	cout << "Cada seis anos se hace el cambio de representante presidencial en el congreso electoral, en este lugar, " << endl;
	cout << "los representantes politicos, postulan a su candidato para demostrar cuantos seguidores tienen y cual es su " << endl;
	cout << "propuesta para liderear al pais, antiguos candidatos decidiran si apoyan a ese reprentante o no..." << endl;
}

/* Funcion del Menu de la brujula */
void Brujula()
{
	cout << "+-----------------------+" << endl;
	cout << "|\t    N	 \t|" << endl;
	cout << "|\t    |	 \t|" << endl;
	cout << "|\tO<--X-->E\t|" << endl;
	cout << "|\t    |	 \t|" << endl;
	cout << "|\t    S	 \t|" << endl;
	cout << "+-----------------------+" << endl;
	cout << endl;
}

/* Funcion de comandos del menu principal */
void comandos_Menu()
{
	cout << "Tecle la accion que quiera realizar:" << endl;
	cout << "> ";
	cin >> opcionesMenu;
	cout << endl;
	system("cls");
}

/* Funcion del Menu de comandos */
void accion()
{
	cout << "--------------------------------------------" << endl;
	cout << "Escribe la accion que quieras realizar:" << endl;
	cout << "(?) Como jugar,\n tecle'como jugar'." << endl;
	cout << "(?) Ayuda,\n tecle'ver instrucciones'." << endl;
	cout << "> ";
	cin >> Accion >> instruccion;
	cout << "____________________________________________" << endl;
	cout << endl;
}

/* Funcion del Aviso */
void precaucion_Pared()
{
	cout << "Hay una pared, amigo. No creo que puedas atravesarla." << endl;
}

/* Funcion del Menu principal */
void Menu()
{
	cout << "==================================" << endl;
	cout << "=====     MENU PRINCIPAL     =====" << endl;
	cout << "==================================" << endl;
	cout << "= > 1) Nueva Partida             =" << endl;
	cout << "= > 2) Cargar partida            =" << endl;
	cout << "= > 3) Como Jugar                =" << endl;
	cout << "= > 4) Instrucciones             =" << endl;
	cout << "= > 5) Creditos                  =" << endl;
	cout << "= > 0) Salir                     =" << endl;
	cout << "==================================" << endl;
	//accion();
	comandos_Menu();
}

/* Funcion del Menu de Ayuda */
void Como_Jugar()
{
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "===========                   Mecanica de juego                    ============" << endl;
	cout << "===============================================================================" << endl;
	cout << "= Mecanica de juego: Para que el candidato pueda representar al pais sera     =" << endl;
	cout << "= necesario que intente hablar con las personas, busque y examine en busca    =" << endl;
	cout << "= de alguna pista y convensa al publico para que sean un seguidor mas.        =" << endl;
	cout << "===============================================================================" << endl;
	cout << endl;
}

/* Funcion de instrucciones */
void Instrucciones()
{
	cout << endl;
	cout << "===============================================================================" << endl;
	cout << "===========          Bienvenido al menu de instrucciones           ============" << endl;
	cout << "===============================================================================" << endl;
	cout << "= 1) Si desea crear una nueva partida......\tESCRIBA '1'.                  =" << endl;
	cout << "= 2) Si desea cargar una partida existente.\tESCRIBA '2'.                  =" << endl;
	cout << "= 3) Si desea ver como jugar...............\tESCRIBA '3'.                  =" << endl;
	cout << "= 4) Si desea ver las instrucciones........\tESCRIBA '4'.                  =" << endl;
	cout << "= 5) Si desea ver los creditos.............\tESCRIBA '5'.                  =" << endl;
	cout << "= 7) Si desea ver el menu de ayuda.........\tESCRIBA 'ver + instruccione'. =" << endl;
	cout << "= 8) Si desea ver la brujula...............\tESCRIBA 'ver + brujula'.      =" << endl;
	cout << "= 9) Si desea examinar un salon............\tESCRIBA 'examinar + salon'.   =" << endl;
	cout << "= 10) Si desea examinar un pasillo..........\tESCRIBA 'examinar + pasillo'.=" << endl;
	cout << "= 11) Si desea intentar hablar.............\tESCRIBA 'intentar + hablar'.  =" << endl;
	cout << "= 12) Si desea guardar y salir del juego...\tESCRIBA 'guardar + partida'.  =" << endl;
	cout << "= 13) Si desea ver su dinero...............\tESCRIBA 'ver + fondos'.       =" << endl;
	cout << "= 14) Si desea ver la tienda...............\tESCRIBA 'ver + tienda'.       =" << endl;
	cout << "= 15) Si desea convencer al publico....... \tESCRIBA 'convencer + publico'.=" << endl;
	cout << "= 16) Si desea hacer promocion............ \tESCRIBA 'hacer + promocion'.  =" << endl;
	cout << "= 17) Si desea ver como jugar............. \tESCRIBA 'como + jugar'.       =" << endl;
	cout << "= 17) Si desea hacer un cumplido.......... \tESCRIBA 'hacer + cumplido'.   =" << endl;
	cout << "==============================================================================" << endl;

	cout << endl;
}

/* Funcion de nueva partida */
void nueva_Partida()
{
	// Variable del inventario

	Jugador Usuario(string("charre"), 500);
	//cout << "Ingresa tu nombre: " << endl;
	//cin >> nombre;

	int vivo = true;
	//Menu();

	while (true)
	{
		
		cout << "------  DATOS INSTALACIONES  ------" << endl;
		// Se manda a llamar las funciones de los salones
		SALON_1();
		SALON_2();
		SALON_6();
		SALON_7();
		SALON_10();

		// Se manda a llamar las funciondes de los pasillos
		PASILLO_1();
		PASILLO_2();
		PASILLO_3();
		PASILLO_4();
		PASILLO_5();
		PASILLO_6();
		PASILLO_7();
		PASILLO_8();
		cout << endl;

		// Valores Estaticos
		accion(); // Se pregunta que se quiere realizar

				  // MOVIMIENTO

				  // Norte
		if (Accion == "ir" && instruccion == "norte") // Norte
		{
			if (Mapa_Escuela[fila_X - 1][columna_Y] != 0)
			{
				fila_X -= 1;
			}
			else
			{
				precaucion_Pared();
			}
		}
		// Sur
		if (Accion == "ir" && instruccion == "sur") // Sur
		{
			if (Mapa_Escuela[fila_X + 1][columna_Y] != 0)
			{
				fila_X += 1;
			}
			else
			{
				precaucion_Pared();
			}
		}
		// Este
		if (Accion == "ir" && instruccion == "este") //Oeste
		{
			if (Mapa_Escuela[fila_X][columna_Y + 1] != 0)
			{
				columna_Y += 1;
			}
			else
			{
				precaucion_Pared();
			}
		}
		// Oeste
		if (Accion == "ir" && instruccion == "oeste")
		{
			if (Mapa_Escuela[fila_X][columna_Y - 1] != 0)
			{
				columna_Y -= 1;
			}
			else
			{
				precaucion_Pared();
			}
		}

		// ACCIONES
		system("cls");
		// Ayuda
		if (Accion == "como" && instruccion == "jugar")
		{
			Como_Jugar();
		}
		// Instrucciones
		if (Accion == "ver" && instruccion == "instrucciones")
		{
			Instrucciones();
		}\
			// Brujula
			if (Accion == "ver" && instruccion == "brujula")
			{
				Brujula();
			}
		// Inventario
		if (Accion == "ver" && instruccion == "inventario")
		{
			string opcionInv;
			cout << "Quieres agregar algo al inventario: si / ver" << endl;
			cout << "> ";
			cin >> opcionInv;
			if (opcionInv == "si")
			{
				string item;
				cout << "Agregar: ";
				cin >> item;
				Usuario.Set_Inventory(item);
			}
			else if (opcionInv == "ver")
			{
				Usuario.Get_Inventory();
			}
			else if (opcionInv == "no")
			{

				cout << "Escribe la accion que quieras realizar:" << endl;
				cout << "> ";
				cin >> opcion;
			}
		}
		// Fondos
		if (Accion == "ver" && instruccion == "fondos")
		{
			//Usuario.dinero -= 100; Prueba de fondos
			cout << "------  LAGUNAS LEGALES  ------" << endl;
			cout << "/* TUS FONDOS ACTUALES SON: " << dinero_Jugador << " */" << endl;
			cout << "POPULARIDAD: " << popularidad << endl;
			cout << "SEGUIDORES: " << seguidores << endl;
			cout << "VOTOS: " << votos << endl;
			cout << "POLITICOS COMPRADOS: " << politicos << endl;
			cout << "DESPENSAS: " << despensas << endl;
			cout << "CANCIONES: " << Canciones << endl;
			cout << "CUMPLIDOS: " << cumplidos << endl;
			cout << endl;
			cout << endl;
		}
		// Promocion - se gana .5 centavos
		if (Accion == "hacer" && instruccion == "promocion")
		{
			dinero_Jugador += .5;
			cout << "Locutor: A los millones que buscan un alivio a los precios," << endl;
			cout << "la huida de impuestos, que buscan acabar con la guerra de naciones," << endl;
			cout << "a esos millones la respuesta es el hombre del momento." << endl;
			cout << "¡Es tiempo de un cambio : Vota Eisenhower el 4 de noviembre!" << endl;
			cout << endl;
			cout << "/* SE HAN AGREGADO $.5 CENTAVOS A TUS FONDOS */" << endl;
			cout << endl;
		}
		// Cumplido - Se agrega 1 al contador de cumplidos
		if (Accion == "hacer" && instruccion == "cumplido" && Mapa_Escuela[fila_X][columna_Y] == 7)
		{
			cumplidos += 1;
			cout << endl;
			cout << "/* Basta porfavor me sonrojo. */" << endl;
			cout << "/* De esta manera no obtendras nada de mi. */" << endl;
			cout << endl;
		}
		if (Accion == "hacer" && instruccion == "cumplido" && Mapa_Escuela[fila_X][columna_Y] != 7)
		{
			cout << endl;
			cout << "/*Aunque estes muy guapo aqui no hay nadie a quien poder hacerle un cumplido.*/" << endl;
			cout << endl;
		}
		// Salir
		if (Accion == "guardar" && instruccion == "partida")
		{
			cout << "/* SE HA GUARDADO EXITOSAMENTE LA PARTIDA */" << endl;
			break;
		}

		// Logro Margarita
		if (cumplidos == 50)
		{
			cout << endl;
			cout << "/* LOGRO DESBLOQUEADO: CONQUISTADOR DE POLITICOS. */" << endl;
			cout << endl;
		}
		// GANAR
		if (Mapa_Escuela[fila_X][columna_Y] == 13 && Accion == "convencer" && instruccion == "publico" && popularidad >= 15 && seguidores >= 3) // El contador de ganar sera el que almacenara los puntos para ganar
		{
			Cuartos Pasillo_8(string("Pasillo 8"), string("Casilleros alrededor"), string("Este"), string("examinar salon, intentar hablar"), NumSalones::SALON_TRECE, objetos_Cuarto::PISTA_VACIO, personas_Cuarto::NINGUNA_PERSONA);
			cout << "/* HAS SIDO ELEGIDO PARA GOBERNAR */" << endl;
			cout << "/* GRACIAS POR JUGAR */" << endl;
			break;
		}
		// PERDER
		if (dinero_Jugador <= 0)
		{
			cout << endl;
			cout << "     /* TE QUEDASTE SIN FONDOS */" << endl;
			cout << "/* ALGUIEN MAS GANO LAS ELECCIONES */" << endl;
			cout << endl;

			cout << "Fondos: " << dinero_Jugador << endl;
			cout << "Puntos alcanzados: " << popularidad << endl;
			cout << endl;
			break;
		}

	}
}

/* Funcion de cargar partida */
void cargar_partida()
{
	cout << "Aqui se cargara la partida." << endl;
}

/* Comandos de comandos menu*/
void Menu_Principal()
{
	if (opcionesMenu == "0" || opcionesMenu == "salir")
	{ // Se sale del juego (programa)
		cout << "/* GRACIAS POR JUGAR */" << endl;
		exit(1);
	}
	else if (opcionesMenu == "1" || opcionesMenu == "nueva_partida")
	{ // Se creara una nueva partida
		Historia();
		cout << endl;
		nueva_Partida();

	}
	else if (opcionesMenu == "2" || opcionesMenu == "cargar_partida")
	{ // En esta seccion se abrira el nuevo archivo creado con la nueva informacion que se almaceno
		cout << "/* ESPERE MIENTRAS SE CARGA LA PARTIDA... */" << endl;
		cout << endl;
	}
	else if (opcionesMenu == "3" || opcionesMenu == "como_jugar")
	{ // Se muestran las instrucciones
		Como_Jugar();
	}
	else if (opcionesMenu == "4" || opcionesMenu == "instrucciones")
	{ // Se muestran las instrucciones
		Instrucciones();
	}
	else if (opcionesMenu == "5" || opcionesMenu == "creditos")
	{ // Se muestran los creditos
		cout << "Hecho por Roberto Charreton Kaplun." << endl;
		cout << "Tiempo invertido: 20 dias y 19 horas." << endl;
		cout << endl;
	}
	else
	{
		cout << "Comando incorrecto, favor de verificar." << endl;
	}

}

/* MAIN */
int main()
{
	while (true) // Si un comando es incorrecto se vuelve a preguntar, si se guarda partida se regresa al lobbie
	{
		Menu();
		Menu_Principal();
	}
	cin.ignore();
	cin.get();
	return 0;
}