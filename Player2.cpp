#include "Player2.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "ValoresCartas.h"
#include "Player.h"
using namespace std;

Player2::Player2(bool turno, Mazo *mazo, Truco *truco, Player* rival) : m_rival(rival), m_turno(turno), m_mazo(mazo), m_truco(truco){
	iniciar();
}


vector<Carta> Player2::obtener_en_mesa(){
	return en_mesa;
}


void Player2::iniciar(){
	cartas = m_mazo->Obtener3cartas();
	cartas[0].actualizarTextura(Vector2f(180, -10));
	cartas[1].actualizarTextura(Vector2f(400, -10));
	cartas[2].actualizarTextura(Vector2f(620, -10));
}

int Player2::verCartasEnMano(){
	return cartas_en_mano;
}

bool Player2::obtenerTurno(){
	return m_turno;
}

void Player2::cambiarTurno(bool aux){
	m_turno = aux;
}

void Player2::actualizar(){
	
	if(m_truco->obtenerStatus() == 1){
		if(m_truco->obtenerGenerated_by() == 1){
			if(Keyboard::isKeyPressed(Keyboard::Num7)){
				m_truco->aceptar();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::Num8)){
				m_truco->rechazar();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::Num9)){
				m_truco->redisputar();
				return;
			}
			return;
		}
	}
	
	
	
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
			m_rival->cambiarTurno(true);
			m_truco->modificar_turno_player(true);
		}
	}
	
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
