#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Player.h"
#include "Player2.h"
#include "Mazo.h"
#include "Envido.h"

using namespace sf;


class Round {
public:
	//Empezar partida en el constructor
	
	Round(bool turn_player1);
	void actualizarStatus();
	void actualizar();
	void dibujar(RenderWindow &w);
	bool getStatus();
	int getStatusTruco();
	
private:
	
	//generales
	bool status = true;
	Mazo mazo;
	
	int puntos_ganador;
	int player1puntos;
	int player2puntos;
	
	Envido envido;
	Truco truco;
	Player player1;
	Player2 player2;
	
};

#endif

