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
	bool NuevaPartidaBoton_porEncima = false;
	bool HistorialBoton_porEncima = false;
	
	
	Window *m_window;
	Texture t_fondo;
	Sprite s_fondo; 
	
	Texture t_NuevaPartidaBoton_porEncima;
	Sprite s_NuevaPartidaBoton_porEncima;
	
	Texture t_HistorialBoton_porEncima;
	Sprite s_HistorialBoton_porEncima;
	
	sf::RectangleShape NuevaPartidaBoton;
	sf::RectangleShape HistorialBoton;
	
	
	sf::Vector2i mousePos;
};

#endif

