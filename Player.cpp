#include "Player.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;

Player::Player(bool turno, Mazo *mazo, Truco *truco) : m_turno(turno),  m_mazo(mazo), m_truco(truco){
	iniciar();
}


bool Player::obtenerTurno(){
	return m_turno;
}

void Player::cambiarTurno(bool aux){
	m_turno = aux;
}

//void Player::set_tiene_responder(bool aux){
//	tiene_responder = true;
//}
//	
vector<Carta> Player::obtener_en_mesa(){
	return en_mesa;
}

void Player::iniciar(){
	cartas = m_mazo->Obtener3cartas();
	cartas[0].actualizarTextura(Vector2f(180, 600));
	cartas[1].actualizarTextura(Vector2f(400, 600));
	cartas[2].actualizarTextura(Vector2f(620, 600));
}

int Player::verCartasEnMano(){
	return cartas_en_mano;
}




//Escuchar inputs
void Player::actualizar(){
	if(m_truco->obtenerStatus() == 1){
		if(m_truco->obtenerGenerated_by() == 2){
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
			
			m_turno = false;
			m_truco->modificar_turno_player(false);
			
		}
	}
	
}

//Dibuja segun los inputs
void Player::dibujar(RenderWindow &m){
	for(Carta &x : cartas){
		x.actualizar();
		x.dibujar(m);
	}
	int i = 230;
	for(Carta &x : en_mesa){
		i-=45;
		x.actualizar_mesa(i);
		x.dibujar(m);
	}
	i = 0;
	
//	if(/*logic_puedo_cantar_algo*/){
//		m_logic_ese_algo.dibujar();
//	}
//	if(logic_debo_aceptar_algo){
//		m_logic
//	}
}
