#ifndef GANADOR_H
#define GANADOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "InputText.hpp"
using namespace std;
using namespace sf;


class Ganador : public Escena {
public:
	Ganador(Window *w, bool player1ganador, int player1puntos, int player2puntos);
	void ProcessEvent(Juego &j, Event &event) override;
	void actualizar(Juego &j) override;
	void dibujar(RenderWindow &w) override;
private:
	//Input del nombre del usuario
	
	InputText m_input;
	Text texto_info;
	Text texto_info2;
	
	Font font;
	
	Window *m_window;
	bool m_player1ganador;
	int m_player1puntos;
	int m_player2puntos;
	string nombre;
	char nombredef[9];
	
	
	sf::Vector2i mousePos;
	
	Texture t_ganador1;
	Texture t_ganador2;
	
	Sprite s_ganador1;
	Sprite s_ganador2;
	
};

#endif

