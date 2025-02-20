#include "Player.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Round.h"

using namespace std;

Player::Player(bool turno, Mazo *mazo, Truco *truco, Envido *envido, Window *w) : m_turno(turno),  m_mazo(mazo), m_truco(truco), m_envido(envido), m_window(w){
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
	
	//ReTruco boton
	ReTrucoBoton.setSize(sf::Vector2f(74.6, 35));
	ReTrucoBoton.setPosition(x_base + anchoBoton, y_base);

	
	//Vale Cuatro boton
	ValeCuatroBoton.setSize(sf::Vector2f(74.6, 35));
	ValeCuatroBoton.setPosition(x_base, y_base + alturaBoton);
	
	//Quiero boton
	QuieroBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroBoton.setPosition(x_base + anchoBoton, y_base + alturaBoton);
	
	// NoQuiero boton
	NoQuieroBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroBoton.setPosition(x_base + anchoBoton * 2, y_base + alturaBoton);
	
	//Envido boton
	EnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoBoton.setPosition(x_base + 376.2, y_base);

	
	//RealEnvido boton
	RealEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	RealEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base);

	
	//EnvidoEnvido boton
	EnvidoEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoEnvidoBoton.setPosition(x_base + 376.2, y_base + alturaBoton);

	
	//FaltaEnvido boton
	FaltaEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	FaltaEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base + alturaBoton);
	
	//QuieroEnvidoBoton
	QuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base);
	
	
	//NoQuieroEnvidoBoton
	NoQuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base + alturaBoton);
	
	
	//ZonaTirarCartas
	ZonaTirarCartas.setSize(sf::Vector2f(600, 270));
	ZonaTirarCartas.setPosition(100, 160);
	ZonaTirarCartas.setFillColor(sf::Color::Red);
	
	
	
	
	
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
	cartas[0].actualizarTextura(Vector2f(205, 580), true);
	cartas[1].actualizarTextura(Vector2f(400, 580), true);
	cartas[2].actualizarTextura(Vector2f(595, 580), true);
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
void Player::actualizar(Round &round){	
	
	if(m_envido->ver_status() == 0 and en_mesa.size() == 0 and m_envido->ver_finalizado() == false){
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(EnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_envido();
				cederTurno();
				round.actualizarCantoEnPantalla(6);
				return;
			}
			if(RealEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_real_envido();
				cederTurno();
				round.actualizarCantoEnPantalla(8);
				return;
			}
			if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_envido->cantar_falta_envido();
				cederTurno();
				round.actualizarCantoEnPantalla(9);
				return;
			}
		}
	}
	
	
	if(m_envido->ver_status() == 1){
		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			
			mousePos = sf::Mouse::getPosition(*m_window);
			
			if(m_envido->ver_tipo_en_juego() == 1){
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					round.actualizarCantoEnPantalla(4);
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(1);
					cederTurno();
					round.actualizarCantoEnPantalla(5);
					return;
				}
				if(EnvidoEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_envido_envido();
					cederTurno();
					round.actualizarCantoEnPantalla(7);
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					round.actualizarCantoEnPantalla(9);
					return;
				}
				return;
			}
			
			//
			
			if(m_envido->ver_tipo_en_juego() == 2){
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					round.actualizarCantoEnPantalla(4);
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(1);
					cederTurno();
					round.actualizarCantoEnPantalla(5);
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					round.actualizarCantoEnPantalla(9);
					return;
				}
			}
			//
			if(m_envido->ver_tipo_en_juego() == 3){
				
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					round.actualizarCantoEnPantalla(4);
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(1);
					cederTurno();
					round.actualizarCantoEnPantalla(5);
					return;
				}
				if(FaltaEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->cantar_falta_envido();
					cederTurno();
					round.actualizarCantoEnPantalla(9);
					return;
				}
			}
			//
			if(m_envido->ver_tipo_en_juego() == 4){
				if(QuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->aceptar();
					cederTurno();
					round.actualizarCantoEnPantalla(4);
					return;
				}
				if(NoQuieroEnvidoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_envido->rechazar(1);
					cederTurno();
					round.actualizarCantoEnPantalla(5);
					return;
				}
			}
		}
		
		return;
	}
	
	if(m_truco->obtenerStatus() == 1){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(m_truco->obtenerGenerated_by() == 2){
				
				//Obtener cordenadas del mouse
				mousePos = sf::Mouse::getPosition(*m_window);
				
				if(QuieroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_truco->aceptar();
					m_envido->finalizarEnvido();
					cederTurno();
					round.actualizarCantoEnPantalla(4);
					return;
				}
				if(NoQuieroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
					m_truco->rechazar();
					round.actualizarCantoEnPantalla(5);
					return;
				}
				if(ReTrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 2) {
					m_truco->redisputar();
					m_truco->setGenerated_by(1);
					m_envido->finalizarEnvido();
					cederTurno();
					round.actualizarCantoEnPantalla(2);
					return;
				}
				if(ValeCuatroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 1) {
					m_truco->redisputar();
					m_truco->setGenerated_by(1);
					m_envido->finalizarEnvido();
					cederTurno();
					round.actualizarCantoEnPantalla(3);
					return;
				}
			}else{
				cederTurno();
			}
		}
		return;
	}
	
	
	
	if(m_truco->verUltimoEnTirar()==1 and m_truco->obtenerStatus() != 2){
		cederTurno();
	}

	
	
	if(m_truco->obtenerStatus() == 0){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(TrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
				m_truco->cantar();
				cederTurno();
				m_truco->setGenerated_by(1);
				round.actualizarCantoEnPantalla(1);
			}
		}
		
	}
	
	if((m_truco->obtenerStatus() == 3) and ((m_truco->obtenerRedisputar() == 2 or m_truco->obtenerRedisputar() == 1) and (m_truco->obtenerGenerated_by() == 2))){
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			mousePos = sf::Mouse::getPosition(*m_window);
			if(ReTrucoBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 2){			
				m_truco->redisputar();
				m_truco->setGenerated_by(1);
				cederTurno();
				round.actualizarCantoEnPantalla(2);
			}
			if(ValeCuatroBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) and m_truco->obtenerRedisputar() == 1){			
				m_truco->redisputar();
				m_truco->setGenerated_by(1);
				cederTurno();
				round.actualizarCantoEnPantalla(3);
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
