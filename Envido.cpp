#include "Envido.h"
#include <iostream>

Envido::Envido(bool turno_player1) : m_turno_player_1(turno_player1) {
	font.loadFromFile("rara.ttf");
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
}

void Envido::actualizar(){
//	std::cout << valor << " <- Valor" << std::endl;
//	std::cout << prev << "  <- Previo" << std::endl;
	if(!finalizado){
		if(m_turno_player_1 == true){
			text.setPosition(400, 500);
		}else{
			text.setPosition(400, 100);
		}
		
		
		if(tiro_carta_player1 == false and m_turno_player_1 and status == 0){
			text.setString("Envido - Real Envido - Falta Envido");
			return;
		}
		
		if(tiro_carta_player2 == false and m_turno_player_1 == false and status == 0){
			text.setString("Envido - Real Envido - Falta Envido");
			return;
		}
		
		if(status == 1){
			if(tipo_en_juego == 1){
				text.setString("Aceptar Envido - Envido envido - Real Envido - Falta envido");
				return;
			}
			if(tipo_en_juego == 2){
				text.setString("Aceptar Real envido - Quiero Falta envido");
				return;
			}
			if(tipo_en_juego == 3){
				text.setString("Aceptar Envido Envido - Quiero Falta envido");
				return;
			}
			if(tipo_en_juego == 4){
				text.setString("Aceptar falta envido - Rechazar falta envido");
				return;
			}
		}
	}else{
		text.setString(" ");
	}
	
}

bool Envido::obtenerGanador(){
	return ganadorplayer1;
}


int Envido::obtenerValor(){
	return valor;
}

int Envido::obtenerPrev(){
	return prev;
}

void Envido::cambiarGanador(bool aux){
	ganadorplayer1 = aux;
}

void Envido::modificar_tiro_carta_player1(){
	tiro_carta_player1 = true;
	if(tiro_carta_player2 == true){
		finalizado = true;
	}
}

void Envido::modificar_tiro_carta_player2(){
	tiro_carta_player2 = true;
	if(tiro_carta_player1 == true){
		finalizado = true;
	}
}

void Envido::finalizarEnvido(){
	finalizado = true;
}

void Envido::modificar_turno_player(bool aux){
	m_turno_player_1 = aux;
}

void Envido::dibujar(RenderWindow &w){
	w.draw(text);
}

void Envido::cantar_envido(){
	status = 1;
	valor = 2;
	tipo_en_juego = 1;
}

void Envido::cantar_envido_envido(){
	status = 1;
	tipo_en_juego = 3;
	prev = 2;
	valor = 4;
}

void Envido::cantar_real_envido(){
	status = 1;
	tipo_en_juego = 2;
	valor = 3;
}

void Envido::cantar_falta_envido(){
	status = 1;
	tipo_en_juego = 4;
	prev = valor;
	valor = -1;
}

void Envido::aceptar(){
	status = 3;
	finalizado = true;
}

void Envido::rechazar(int aux){
	status = 2;
	finalizado = true;
	rechazado_by = aux;
}

int Envido::obtenerRechazado_by(){
	return rechazado_by;
}

bool Envido::ver_turno_player_1(){
	return m_turno_player_1;
}

bool Envido::ver_finalizado(){
	return finalizado;
}

bool Envido::ver_tiro_carta_player1(){
	return tiro_carta_player1;
}

bool Envido::ver_tiro_carta_player2(){
	return tiro_carta_player2;
}

int Envido::ver_generated_by(){
	return m_generated_by;
}

int Envido::ver_status(){
	return status;
}

int Envido::ver_tipo_en_juego(){
	return tipo_en_juego;
}
