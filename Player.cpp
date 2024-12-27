#include "Player.h"

#define CARTA1 "./images/oro4.png", 1, 1, 2
#define CARTA2 "./images/espada2.png", 2, 2, 2
#define CARTA3 "./images/basto1.png", 2, 2, 2

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Player::Player() : carta1(CARTA1, Vector2f(180, 550)), carta2(CARTA2, Vector2f(400,550)), carta3(CARTA3, Vector2f(620, 550)), carta_selected(-1) {
	cartas.push_back(carta1);
	cartas.push_back(carta2);
	cartas.push_back(carta3);
}


void Player::dibujar(RenderWindow &m){
	for(Carta &x : cartas){
		x.actualizar(cartas_en_mano);
		x.dibujar(m);
	}
}
void Player::actualizar(){
	if(Keyboard::isKeyPressed(Keyboard::Num1)){
		carta_selected = 0;
		cartas[0].is_selected(true);
		cartas[1].is_selected(false);
		cartas[2].is_selected(false);
		return;
	}
	if(Keyboard::isKeyPressed(Keyboard::Num2)){
		carta_selected = 1;
		cartas[0].is_selected(false);
		cartas[1].is_selected(true);
		cartas[2].is_selected(false);
		return;
	}
	if(Keyboard::isKeyPressed(Keyboard::Num3)){
		carta_selected = 2;
		cartas[0].is_selected(false);
		cartas[1].is_selected(false);
		cartas[2].is_selected(true);
		return;
	} 
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		if(carta_selected != -1){	
			cartas[carta_selected].tirar();
			cartas_en_mano --;
			carta_selected = -1;
		}
	}
	
}
