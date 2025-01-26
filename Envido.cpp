#include "Envido.h"
#include <iostream>

Envido::Envido(bool turno_player1) : m_turno_player_1(turno_player1) {
	font.loadFromFile("rara.ttf");
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
	
	t_envido.loadFromFile("./images/botones/envido.png");
	s_envido.setTexture(t_envido);
	s_envido.setPosition(Vector2f(100, 530));
	
	t_envidoenvido.loadFromFile("./images/botones/envidoenvido.png");
	s_envidoenvido.setTexture(t_envidoenvido);
	s_envidoenvido.setPosition(Vector2f(100, 530));
	
	
	t_realenvido.loadFromFile("./images/botones/realenvido.png");
	s_realenvido.setTexture(t_realenvido);
	s_realenvido.setPosition(Vector2f(100, 530));
	
	
	t_faltaenvido.loadFromFile("./images/botones/faltaenvido.png");
	s_faltaenvido.setTexture(t_faltaenvido);
	s_faltaenvido.setPosition(Vector2f(100, 530));
	
	
	t_quiero.loadFromFile("./images/botones/quiero2.png");
	s_quiero.setTexture(t_quiero);
	s_quiero.setPosition(Vector2f(100, 530));
	
	t_noquiero.loadFromFile("./images/botones/noquiero2.png");
	s_noquiero.setTexture(t_noquiero);
	s_noquiero.setPosition(Vector2f(100, 530));
	
}

void Envido::actualizar(){
	if(!finalizado){
		if(m_turno_player_1 == true){
			text.setPosition(400, 500);
			s_envido.setPosition(Vector2f(100, 530));
			s_envidoenvido.setPosition(Vector2f(100, 530));
			s_realenvido.setPosition(Vector2f(100, 530));
			s_faltaenvido.setPosition(Vector2f(100, 530));
			s_quiero.setPosition(Vector2f(100, 530));
			s_noquiero.setPosition(Vector2f(100, 530));
		}else{
			text.setPosition(400, 100);
			s_envido.setPosition(Vector2f(100, 0));
			s_envidoenvido.setPosition(Vector2f(100, 0));
			s_realenvido.setPosition(Vector2f(100, 0));
			s_faltaenvido.setPosition(Vector2f(100, 0));
			s_quiero.setPosition(Vector2f(100, 0));
			s_noquiero.setPosition(Vector2f(100, 0));
		}
		
		
		if(tiro_carta_player1 == false and m_turno_player_1 and status == 0){
			text.setString("Envido - Real Envido - Falta Envido");
			elementos_on[0] = 1;
			elementos_on[1] = 0;
			elementos_on[2] = 1;
			elementos_on[3] = 1;
			elementos_on[4] = 0;
			elementos_on[5] = 0;
			return;
		}
		
		if(tiro_carta_player2 == false and m_turno_player_1 == false and status == 0){
			text.setString("Envido - Real Envido - Falta Envido");
			elementos_on[0] = 1;
			elementos_on[1] = 0;
			elementos_on[2] = 1;
			elementos_on[3] = 1;
			elementos_on[4] = 0;
			elementos_on[5] = 0;
			return;
		}
		elementos_on[0] = 0;
		elementos_on[1] = 0;
		elementos_on[2] = 0;
		elementos_on[3] = 0;
		elementos_on[4] = 0;
		elementos_on[5] = 0;
		
		if(status == 1){
			if(tipo_en_juego == 1){
				text.setString("Aceptar Envido - Envido envido - Real Envido - Falta envido");
				elementos_on[0] = 0;
				elementos_on[1] = 1;
				elementos_on[2] = 1;
				elementos_on[3] = 1;
				elementos_on[4] = 1;
				elementos_on[5] = 1;
				return;
			}
			if(tipo_en_juego == 2){
				text.setString("Aceptar Real envido - Quiero Falta envido");
				elementos_on[0] = 0;
				elementos_on[1] = 0;
				elementos_on[2] = 0;
				elementos_on[3] = 1;
				elementos_on[4] = 1;
				elementos_on[5] = 0;
				return;
			}
			if(tipo_en_juego == 3){
				text.setString("Aceptar Envido Envido - Quiero Falta envido");
				elementos_on[0] = 0;
				elementos_on[1] = 0;
				elementos_on[2] = 0;
				elementos_on[3] = 1;
				elementos_on[4] = 1;
				elementos_on[5] = 0;
				return;
			}
			if(tipo_en_juego == 4){
				text.setString("Aceptar falta envido - Rechazar falta envido");
				elementos_on[0] = 0;
				elementos_on[1] = 0;
				elementos_on[2] = 0;
				elementos_on[3] = 0;
				elementos_on[4] = 1;
				elementos_on[5] = 1;
				return;
			}
			
		}
	}else{
		text.setString(" ");
		elementos_on[0] = 0;
		elementos_on[1] = 0;
		elementos_on[2] = 0;
		elementos_on[3] = 0;
		elementos_on[4] = 0;
		elementos_on[5] = 0;
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
	/*w.draw(text);*/
	if(elementos_on[0]){
		w.draw(s_envido);
	}
	if(elementos_on[1]){
		w.draw(s_envidoenvido);
	}
	if(elementos_on[2]){
		w.draw(s_realenvido);
	}
	if(elementos_on[3]){
		w.draw(s_faltaenvido);
	}
	if(elementos_on[4]){
		w.draw(s_quiero);
	}
	if(elementos_on[5]){
		w.draw(s_noquiero);
	}
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
