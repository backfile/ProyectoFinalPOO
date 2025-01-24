#include "Player.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;

Player::Player(bool turno, Mazo *mazo, Truco *truco, Envido *envido) : m_turno(turno),  m_mazo(mazo), m_truco(truco), m_envido(envido){
	iniciar();
}


bool Player::obtenerTurno(){
	return m_turno;
}

void Player::cambiarTurno(bool aux){
	m_turno = aux;
}


vector<Carta> Player::obtener_en_mesa(){
	return en_mesa;
}

vector<Carta> Player::obtener_cartas(){
	return cartas;
};

void Player::iniciar(){
	cartas = m_mazo->Obtener3cartas();
	cartas[0].actualizarTextura(Vector2f(180, 600));
	cartas[1].actualizarTextura(Vector2f(400, 600));
	cartas[2].actualizarTextura(Vector2f(620, 600));
}

int Player::verCartasEnMano(){
	return cartas_en_mano;
}


void Player::cederTurno(){
	m_turno = false;
	m_truco->modificar_turno_player(false);
	m_envido->modificar_turno_player(false);
};


//Escuchar inputs
void Player::actualizar(){
	if(m_truco->obtenerStatus() == 1){
		if(m_truco->obtenerGenerated_by() == 2){
			if(Keyboard::isKeyPressed(Keyboard::Num7)){
				m_truco->aceptar();
				m_envido->finalizarEnvido();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::Num8)){
				m_truco->rechazar();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::Num9) and m_truco->obtenerRedisputar() > 0) {
				m_truco->redisputar();
				m_truco->setGenerated_by(1);
				m_envido->finalizarEnvido();
				cederTurno();
				return;
			}
		}
		return;
	}
	
	if(m_envido->ver_status() == 1){
		
		//
		if(m_envido->ver_tipo_en_juego() == 1){
			if(Keyboard::isKeyPressed(Keyboard::Z)){
				m_envido->aceptar();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::X)){
				m_envido->rechazar(1);
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::C)){
				m_envido->cantar_envido_envido();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::V)){
				m_envido->cantar_falta_envido();
				cederTurno();
				return;
			}
			return;
		}
		
		//
		
		if(m_envido->ver_tipo_en_juego() == 2){
			if(Keyboard::isKeyPressed(Keyboard::Z)){
				m_envido->aceptar();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::X)){
				m_envido->rechazar(1);
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::V)){
				m_envido->cantar_falta_envido();
				cederTurno();
				return;
			}
		}
		//
		if(m_envido->ver_tipo_en_juego() == 3){
			
			if(Keyboard::isKeyPressed(Keyboard::Z)){
				m_envido->aceptar();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::X)){
				m_envido->rechazar(1);
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::V)){
				m_envido->cantar_falta_envido();
				cederTurno();
				return;
			}
		}
		//
		if(m_envido->ver_tipo_en_juego() == 4){
			if(Keyboard::isKeyPressed(Keyboard::Z)){
				m_envido->aceptar();
				cederTurno();
				return;
			}
			if(Keyboard::isKeyPressed(Keyboard::X)){
				m_envido->rechazar(1);
				cederTurno();
				return;
			}
		}
		return;
	}
	
	if(m_truco->verUltimoEnTirar()==1){
		cederTurno();
	}

	if(m_envido->ver_status() == 0){
		if(Keyboard::isKeyPressed(Keyboard::Z)){
			m_envido->cantar_envido();
			cederTurno();
			return;
		}
		if(Keyboard::isKeyPressed(Keyboard::X)){
			m_envido->cantar_real_envido();
			cederTurno();
			return;
		}
		if(Keyboard::isKeyPressed(Keyboard::C)){
			m_envido->cantar_falta_envido();
			cederTurno();
			return;
		}
	}
	
	if(m_truco->obtenerStatus() == 0){
		if(Keyboard::isKeyPressed(Keyboard::Num6)){
			m_truco->cantar();
			cederTurno();
			m_truco->setGenerated_by(1);
		}
		
	}
	
	if(m_truco->obtenerStatus() == 3 and (m_truco->obtenerRedisputar() == 2 or m_truco->obtenerRedisputar() == 1)){
		if(Keyboard::isKeyPressed(Keyboard::Num6)){			
			m_truco->redisputar();
			m_truco->setGenerated_by(1);
			cederTurno();
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
		if(carta_selected != -1 and cartas[carta_selected].obtenerEnMano() == true){	
			cartas[carta_selected].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[carta_selected]);
			carta_selected = -1;
			m_truco->cambiarUltimoEnTirar(1);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player1();
			}
			cederTurno();
		}
	}
	
}

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
}	
