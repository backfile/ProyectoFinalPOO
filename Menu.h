#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace sf;

class Menu : public Escena {
public:
	Menu(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
private:
	Window *m_window;
	Texture t_fondo;
	Sprite s_fondo; 
};

#endif

