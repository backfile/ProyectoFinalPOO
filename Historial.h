#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "Escena.h"

struct Partida{
	int ganadorplayer1;
	int puntos_player1;
	int puntos_player2;
};

class Historial : public Escena{
public:
	Historial(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
private:
	vector<Partida>v;
	
	Window *m_window;
	
	sf::Vector2i mousePos;
};

#endif

