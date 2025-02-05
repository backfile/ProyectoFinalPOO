#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
using namespace std;
using namespace sf;

class Juego {
public:
	Juego();
	void jugar();
	void actualizarEscena(Escena *nuevaEscena);
	~Juego();
private:
	Window *window;
	RenderWindow w;
	Escena *actual;
	Escena *siguiente = nullptr;
};

#endif

