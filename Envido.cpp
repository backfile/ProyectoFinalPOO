#include "Envido.h"

Envido::Envido(bool turno_player1) : m_turno_player_1(turno_player1) {
	font.loadFromFile("nueva.otf");
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
}

void Envido::actualizar(){
	
	if(!finalizado){
		if(m_turno_player_1 == true){
			text.setPosition(600, 500);
		}else{
			text.setPosition(600, 100);
		}
		
		text.setString("envido");
	}
	
}

void Envido::dibujar(RenderWindow &w){
	w.draw(text);
}

void Envido::cantar_envido(){
	status = 0;
	valor = 2;
	tipo_en_juego = 1;
}

void Envido::cantar_envido_envido(){
	status = 0;
	tipo_en_juego = 3;
	prev = 2;
	valor = 4;
}

void Envido::cantar_real_envido(){
	status = 0;
	tipo_en_juego = 2;
	valor = 3;
}

void Envido::cantar_falta_envido(){
	status = 0;
	tipo_en_juego = 4;
	prev = valor;
	valor = -1;
}

void Envido::aceptar(){
	status = 3;
	finalizado = true;
}

void Envido::rechazar(){
	status = 2;
	finalizado = true;
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
