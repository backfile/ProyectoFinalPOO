#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Player.h"

using namespace sf;

class Game {
public:
	//Empezar partida en el constructor
	Game();
	
	//Cambiar turno
	void CambiarTurno();
	
	void Dibujar(RenderWindow &w);
	
private:
	Texture background;
	Sprite background_s;
	bool m_turno_player = true;
	Player player1; // Estos accede

};

#endif

