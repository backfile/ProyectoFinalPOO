#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;
using namespace sf;

class Juego;

class Escena {
public:
	Escena();
	virtual void ProcessEvent(Juego &j, Event &event) {}
	virtual void actualizar(Juego &j) = 0;
	virtual void dibujar(RenderWindow &w) = 0;
private:
};

#endif

