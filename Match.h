#ifndef MATCH_H
#define MATCH_H
#include "Match.h"
#include "Round.h"

class Match {
public:
	Match();
	void actualizar(); //Se ejecuta siempre
	void dibujar(RenderWindow &w);   //Se ejecuta siempre
	
private:
	Round *round;
	int player1_puntos;
	int player2_puntos;
	bool jugar_primero = true;

	
	//Texturas
	Texture t_background;
	Sprite s_background;
};

#endif

