#include "Player2.h"

#define CARTA1 "./images/oro4.png", 1, 1, 2
#define CARTA2 "./images/espada2.png", 2, 2, 2
#define CARTA3 "./images/basto2.png", 2, 2, 2

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
using namespace std;

Player2::Player2(bool turno) : m_turno(turno), carta1(CARTA1, Vector2f(180, 50)), carta2(CARTA2, Vector2f(400,50)), carta3(CARTA3, Vector2f(620, 50)), carta_selected(-1) {
	cartas.push_back(carta1);
	cartas.push_back(carta2);
	cartas.push_back(carta3);
	
}


void Player2::dibujar(RenderWindow &m){
	for(Carta &x : cartas){
		x.actualizar();
		x.dibujar(m);
	}
	int i = -230;
	for(Carta &x : en_mesa){
		i+=45;
		x.actualizar_mesa(i);
		x.dibujar(m);
	}
	
	i = 0;
}

void Player2::setRival(Player *aux){
	rival = aux;
}


bool Player2::obtenerTurno(){
	return m_turno;
}

void Player2::cambiarTurno(bool aux){
	m_turno = aux;
}

void Player2::actualizar(){
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
			en_mesa.push_back(cartas[carta_selected]);
			carta_selected = -1;
			rival->cambiarTurno(true);
		}
	}
	
}
