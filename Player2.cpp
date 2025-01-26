#include "Player2.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "ValoresCartas.h"
#include "Player.h"
using namespace std;

Player2::Player2(bool turno, Mazo *mazo, Truco *truco, Envido *envido, Player* rival, Window *w) : m_rival(rival), m_turno(turno), m_mazo(mazo), m_truco(truco), m_envido(envido), m_window(w){
	iniciar();
	
	//Definir tamaño de los botones
	float anchoBoton = 74.6;
	float alturaBoton = 35;
	
	//Definir posicion base
	float x_base = 100; 
	float y_base = 0;
	
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
	
	//ZonaTirarCartas
	ZonaTirarCartas.setSize(sf::Vector2f(600, 270));
	ZonaTirarCartas.setPosition(100, 160);
	ZonaTirarCartas.setFillColor(sf::Color::Red);
}


vector<Carta> Player2::obtener_en_mesa(){
	return en_mesa;
}


vector<Carta> Player2::obtener_cartas(){
	return cartas;
};


void Player2::iniciar(){
	cartas = m_mazo->Obtener3cartas();
	cartas[0].actualizarTextura(Vector2f(205, 10));
	cartas[1].actualizarTextura(Vector2f(400, 10));
	cartas[2].actualizarTextura(Vector2f(595, 10));
}


void Player2::cederTurno(){
	m_rival->cambiarTurno(true);
	m_truco->modificar_turno_player(true);
	m_envido->modificar_turno_player(true);
};


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
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(m_truco->obtenerGenerated_by() == 1){
				if(QuieroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_truco->aceptar();
					m_rival->cambiarTurno(true);
					m_truco->modificar_turno_player(true);
					m_envido->finalizarEnvido();
					return;
				}
				if(NoQuieroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_truco->rechazar();
					m_rival->cambiarTurno(true);
					m_truco->modificar_turno_player(true);
					return;
				}
				if(ReTrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 2){
					m_truco->redisputar();
					m_truco->setGenerated_by(2);
					m_rival->cambiarTurno(true);
					m_truco->modificar_turno_player(true);
					m_envido->finalizarEnvido();
					return;
				}
				if(ValeCuatroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 1){
					m_truco->redisputar();
					m_truco->setGenerated_by(2);
					m_rival->cambiarTurno(true);
					m_truco->modificar_turno_player(true);
					m_envido->finalizarEnvido();
					return;
				}
			}
		}
		return;
	}
	
	
	if(m_envido->ver_status() == 1){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(m_envido->ver_tipo_en_juego() == 1){
				mousePos = sf::Mouse::getPosition(*m_window);
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(2);
					cederTurno();
					return;
				}
				if(EnvidoEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_envido_envido();
					cederTurno();
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					return;
				}
				if(RealEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_real_envido();
					cederTurno();
					return;
				}
			}
			if(m_envido->ver_tipo_en_juego() == 2){
				mousePos = sf::Mouse::getPosition(*m_window);
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(2);
					cederTurno();
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					return;
				}
			}
			//
			if(m_envido->ver_tipo_en_juego() == 3){
				mousePos = sf::Mouse::getPosition(*m_window);
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(2);
					cederTurno();
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					return;
				}
			}
			//
			if(m_envido->ver_tipo_en_juego() == 4){
				mousePos = sf::Mouse::getPosition(*m_window);
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(2);
					cederTurno();
					return;
				}
			}
			
		}
			
		return;
	}


	
	if(m_truco->verUltimoEnTirar()==2){
		cederTurno();
	}
	
	if(m_envido->ver_status() == 0){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(EnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_envido();
				cederTurno();
				return;
			}
			if(RealEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_real_envido();
				cederTurno();
				return;
			}
			if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_falta_envido();
				cederTurno();
				return;
			}
		}
	}
	
	
	if(m_truco->obtenerStatus() == 3 and (m_truco->obtenerRedisputar() == 2 or m_truco->obtenerRedisputar() == 1)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) and m_truco->obtenerRedisputar() == 2){
			if(ReTrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_truco->redisputar();
				
				m_truco->setGenerated_by(2);
				cederTurno();
			}
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) and m_truco->obtenerRedisputar() == 1){
			if(ValeCuatroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_truco->redisputar();
				
				m_truco->setGenerated_by(2);
				cederTurno();
			}
		}
	}
	
	if(m_truco->obtenerStatus() == 0){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(TrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_truco->cantar();
				m_truco->setGenerated_by(2);
				cederTurno();
			}
		}
		
	}
	
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(cartas[0].obtenerSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			carta_selected = 0;
			cartas[0].is_selected(true);
			cartas[1].is_selected(false);
			cartas[2].is_selected(false);
			return;
		}
		if(cartas[1].obtenerSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			carta_selected = 1;
			cartas[0].is_selected(false);
			cartas[1].is_selected(true);
			cartas[2].is_selected(false);
			return;
		}
		if(cartas[2].obtenerSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			carta_selected = 2;
			cartas[0].is_selected(false);
			cartas[1].is_selected(false);
			cartas[2].is_selected(true);
			return;
		} 
		if(ZonaTirarCartas.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			if(carta_selected != -1 and cartas[carta_selected].obtenerEnMano() == true){	
				m_rival->restarCartasEnManoPlayer2();
				cartas[carta_selected].tirar();
				cartas_en_mano --;
				en_mesa.push_back(cartas[carta_selected]);
				carta_selected = -1;
				if(m_envido->ver_finalizado() == false){
					m_envido->modificar_tiro_carta_player2();
				}
				m_truco->cambiarUltimoEnTirar(2);
				if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
				cederTurno();
			}
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


