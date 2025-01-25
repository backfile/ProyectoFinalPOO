#include "Player.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;

Player::Player(bool turno, Mazo *mazo, Truco *truco, Envido *envido) : m_turno(turno),  m_mazo(mazo), m_truco(truco), m_envido(envido){
	//Repartir cartas
	iniciar();
	
	//Definir tamaño de los botones
	float anchoBoton = 74.6;
	float alturaBoton = 35;
	
	//Definir posicion base
	float x_base = 100; 
	float y_base = 530;
	
	//Truco boton
	TrucoBoton.setSize(sf::Vector2f(74.6, 35));
	TrucoBoton.setPosition(x_base, y_base);
	TrucoBoton.setFillColor(sf::Color::Red);
	
	//ReTruco boton
	ReTrucoBoton.setSize(sf::Vector2f(74.6, 35));
	ReTrucoBoton.setPosition(x_base + anchoBoton, y_base);
	ReTrucoBoton.setFillColor(sf::Color::Red);
	
	//Vale Cuatro boton
	ValeCuatroBoton.setSize(sf::Vector2f(74.6, 35));
	ValeCuatroBoton.setPosition(x_base, y_base + alturaBoton);
	ValeCuatroBoton.setFillColor(sf::Color::Red);
	
	//Quiero boton
	QuieroBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroBoton.setPosition(x_base + anchoBoton, y_base + alturaBoton);
	QuieroBoton.setFillColor(sf::Color::Red);
	
	// NoQuiero boton
	NoQuieroBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroBoton.setPosition(x_base + anchoBoton * 2, y_base + alturaBoton);
	NoQuieroBoton.setFillColor(sf::Color::Red);
	
	//Envido boton
	EnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoBoton.setPosition(x_base + 376.2, y_base);
	EnvidoBoton.setFillColor(sf::Color::Red);
	
	//RealEnvido boton
	RealEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	RealEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base);
	RealEnvidoBoton.setFillColor(sf::Color::Red);
	
	//EnvidoEnvido boton
	EnvidoEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoEnvidoBoton.setPosition(x_base + 376.2, y_base + alturaBoton);
	EnvidoEnvidoBoton.setFillColor(sf::Color::Red);
	
	//FaltaEnvido boton
	FaltaEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	FaltaEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base + alturaBoton);
	FaltaEnvidoBoton.setFillColor(sf::Color::Red);
	
	//QuieroEnvidoBoton
	QuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base);
	QuieroEnvidoBoton.setFillColor(sf::Color::Red);
	
	//NoQuieroEnvidoBoton
	NoQuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base + alturaBoton);
	NoQuieroEnvidoBoton.setFillColor(sf::Color::Red);
	
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
	cartas[0].actualizarTextura(Vector2f(205, 580));
	cartas[1].actualizarTextura(Vector2f(400, 580));
	cartas[2].actualizarTextura(Vector2f(595, 580));
}

int Player::verCartasEnMano(){
	return cartas_en_mano;
}

void Player::restarCartasEnManoPlayer2(){
	cartas_en_mano_player2--;
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
			if((cartas_en_mano == 2 and cartas_en_mano_player2 == 2) or (cartas_en_mano == 1 and cartas_en_mano_player2 == 1)){return;}
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
	m.draw(TrucoBoton);
	m.draw(ReTrucoBoton);
	m.draw(ValeCuatroBoton);
	m.draw(QuieroBoton);
	m.draw(NoQuieroBoton);
	m.draw(EnvidoBoton);
	m.draw(RealEnvidoBoton);
	m.draw(EnvidoEnvidoBoton);
	m.draw(FaltaEnvidoBoton);
	m.draw(QuieroEnvidoBoton);
	m.draw(NoQuieroEnvidoBoton);
	i = 0;
}	
