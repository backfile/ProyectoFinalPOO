#include "Player.h"

#define CARTA1 "./images/oro4.png", 1, 1, 2
#define CARTA2 "./images/espada2.png", 2, 2, 2
#define CARTA3 "./images/basto1.png", 2, 2, 2

#include <SFML/System/Vector2.hpp>

Player::Player() : carta1(CARTA1, Vector2f(75, 400)), carta2(CARTA2, Vector2f(295,400)), carta3(CARTA3, Vector2f(515, 400)) {
	cartas.push_back(carta1);
	cartas.push_back(carta2);
	cartas.push_back(carta3);
}


void Player::dibujar(RenderWindow &m){
	for(Carta &x : cartas){
		x.dibujar(m);
	}
}
