#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <fstream>

using namespace std;
using namespace sf;

struct Partida{
	bool player1win;
	int player1puntos;
	int player2puntos;
	char nombre[9];
};


class Juego {
public:
	Juego();
	void jugar();
	void actualizarEscena(Escena *nuevaEscena);
	vector<Partida> obtenerHistorial();
	void agregarPartida(Partida);
	
	~Juego();
private:
	Window *window;
	RenderWindow w;
	Escena *actual;
	Escena *siguiente = nullptr;
};

#endif

