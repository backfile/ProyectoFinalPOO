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
	void verificar_estado();
	void actualizar();
	void dibujar(RenderWindow &w);
	bool getStatus();
	int getStatusTruco();
	int getPuntosPlayer1();
	int getPuntosPlayer2();
	int getPuntosGanador();
	bool getPlayer1ganador();
	
private:
	
	//generales
	bool status = true;
	bool player1ganador;
	Mazo mazo;
	
	int puntos_ganador = 0;
	int player1puntos = 0;
	int player2puntos = 0;
	
	Envido envido;
	Truco truco;
	Player player1;
	Player2 player2;
	
};

#endif

