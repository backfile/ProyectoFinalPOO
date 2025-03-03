#ifndef MATCH_H
#define MATCH_H
#include "Match.h"
#include "Round.h"
#include "Escena.h"

class Match : public Escena {
public:
	Match(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
	void obtener_puntos();
	
private:
	Round *round;
	int player1_puntos = 0;
	int player2_puntos = 0;
	bool jugar_primero = true;
	int cont = 0;
	int puntos_para_ganar = 3;
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
	
	//Palitos
	Texture t_madera;
	Sprite s_madera;
	
	
	vector<RectangleShape> palitos;
	vector<RectangleShape> Apalitos;
	
};

#endif

