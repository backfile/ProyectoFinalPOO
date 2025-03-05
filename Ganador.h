#ifndef GANADOR_H
#define GANADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace std;
using namespace sf;


class Ganador : public Escena {
public:
	Ganador(Window *w, bool player1ganador);
	void actualizar(Juego &j) override;
	void dibujar(RenderWindow &w) override;
private:
	Window *m_window;
	bool m_player1ganador;
	bool menuboton_porEncima = false;
	
	sf::Vector2i mousePos;
	
	Texture t_ganador1;
	Texture t_ganador2;
	
	Sprite s_ganador1;
	Sprite s_ganador2;
	
	Texture t_menuboton_encima;
	Sprite s_menuboton_encima;
	
	sf::RectangleShape MenuBoton;
};

#endif

