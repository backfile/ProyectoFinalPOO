#ifndef MATCH_H
#define MATCH_H
#include "Match.h"
#include "Round.h"

class Match {
public:
	Match(Window *w);
	void actualizar(); //Se ejecuta siempre
	void dibujar(RenderWindow &w);   //Se ejecuta siempre
	void obtener_puntos();
	
private:
	Round *round;
	int player1_puntos = 0;
	int player2_puntos = 0;
	bool jugar_primero = true;
	int cont = 0;
	bool aux = true;
	Window *m_window;
	
	//Texturas
	Text text_player1;
	Text text_player2;
	Font font;
	Texture t_background;
	Sprite s_background;
	
	Texture t_repartiendo;
	Sprite s_repartiendo;
	
};

#endif

