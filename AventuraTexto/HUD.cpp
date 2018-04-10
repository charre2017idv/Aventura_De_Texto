#include "HUD.h"


// En esta seccion esta todo el HUD del jugador
HUD::HUD(float money, int popularity, int followers, int votes, int storeroom, int politicians, int compliments, int songs)
{
	dinero_Jugador = money;
	popularidad = popularity;
	seguidores = followers;
	votos = votes;
	despensas = storeroom;
	politicos = politicians;
	cumplidos = compliments;
	Canciones = songs;
}


HUD::~HUD()
{
}
