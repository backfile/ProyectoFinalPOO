#include "Truco.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <atomic>
#include <iostream>

using namespace std;
using namespace sf;

Truco::Truco(bool turno_player_1) : m_turno_player_1(turno_player_1){
	
	t_truco.loadFromFile("./images/botones/truco.png");
	s_truco.setTexture(t_truco);
	s_truco.setPosition(Vector2f(100, 530));
	
	t_retruco.loadFromFile("./images/botones/retruco.png");
	s_retruco.setTexture(t_retruco);
	s_retruco.setPosition(Vector2f(100, 530));
	
	t_valecuatro.loadFromFile("./images/botones/valecuatro.png");
	s_valecuatro.setTexture(t_valecuatro);
	s_valecuatro.setPosition(Vector2f(100, 530));
	
	t_quiero.loadFromFile("./images/botones/quiero1.png");
	s_quiero.setTexture(t_quiero);
	s_quiero.setPosition(Vector2f(100, 530));
	

	t_noquiero.loadFromFile("./images/botones/noquiero1.png");
	s_noquiero.setTexture(t_noquiero);
	s_noquiero.setPosition(Vector2f(100, 530));
	
	
	font.loadFromFile("rara.ttf");
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
	if(turno_player_1){
		ultimo_en_tirar = 2;
	}else{
		ultimo_en_tirar = 1;
	}
}

void Truco::actualizar(){
	
	if(m_turno_player_1 == true){
		text.setPosition(100, 500);
		s_truco.setPosition(Vector2f(100, 530));
		s_retruco.setPosition(Vector2f(100, 530));
		s_valecuatro.setPosition(Vector2f(100, 530));
		s_quiero.setPosition(Vector2f(100, 530));
		s_noquiero.setPosition(Vector2f(100, 530));
	}else{
		text.setPosition(100, 100);
		s_truco.setPosition(Vector2f(100, 0));
		s_retruco.setPosition(Vector2f(100, 0));
		s_valecuatro.setPosition(Vector2f(100, 0));
		s_quiero.setPosition(Vector2f(100, 0));
		s_noquiero.setPosition(Vector2f(100, 0));
		
	}
	
	if(status == 0){
		text.setString("Cantar truco");
		elementos_on[0] = 1;
		elementos_on[1] = 0;
		elementos_on[2] = 0;
		elementos_on[3] = 0;
		elementos_on[4] = 0;	
		return;
	}
	
	if(status == 1){
		if(max_redisputar == 0){
			text.setString("Aceptar - Rechazar");
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 0;
			elementos_on[3] = 1;
			elementos_on[4] = 1;	
			return;
		}
		if(max_redisputar == 1){
			text.setString("Aceptar - Rechazar - Quiero vale 4");
			
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 1;
			elementos_on[3] = 1;
			elementos_on[4] = 1;	
			return;
		}
		text.setString("Aceptar - Rechazar - Quiero re truco");

		elementos_on[0] = 0;
		elementos_on[1] = 1;
		elementos_on[2] = 0;
		elementos_on[3] = 1;
		elementos_on[4] = 1;	
		return;
	}
	
	
	if(status == 3 and max_redisputar == 2){
		if(m_generated_by == 1 and m_turno_player_1 == false){
			text.setString("Re-truco");
			
			elementos_on[0] = 0;
			elementos_on[1] = 1;
			elementos_on[2] = 0;
			elementos_on[3] = 0;
			elementos_on[4] = 0;	
			return;
		}
		else if(m_generated_by == 2 and m_turno_player_1 == true){
			
			elementos_on[0] = 0;
			elementos_on[1] = 1;
			elementos_on[2] = 0;
			elementos_on[3] = 0;
			elementos_on[4] = 0;
			return;
		}else{
			text.setString("");
			
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 0;
			elementos_on[3] = 0;
			elementos_on[4] = 0;
		}
		
		return;
	}
	
	if(status == 3 and max_redisputar == 1){
		if(m_generated_by == 1 and m_turno_player_1 == false){
			text.setString("Vale cuatro");
			
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 1;
			elementos_on[3] = 0;
			elementos_on[4] = 0;
			return;
		}
		else if(m_generated_by == 2 and m_turno_player_1 == true){
			text.setString("Vale cuatro");
			
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 1;
			elementos_on[3] = 0;
			elementos_on[4] = 0;
			return;
		}else{
			text.setString("");
			elementos_on[0] = 0;
			elementos_on[1] = 0;
			elementos_on[2] = 0;
			elementos_on[3] = 0;
			elementos_on[4] = 0;
		}
		
		return;
	}
	
	if(status == 3 and max_redisputar == 0){
		text.setString(" ");
		elementos_on[0] = 0;
		elementos_on[1] = 0;
		elementos_on[2] = 0;
		elementos_on[3] = 0;
		elementos_on[4] = 0;
	}
	

}

int Truco::obtenerGenerated_by(){
	return m_generated_by;
}
	

void Truco::redisputar(){
	if(max_redisputar > 0){	
		status = 1;
		castigo = valor;	
		valor+=1;
	}
	max_redisputar --;
}

void Truco::modificar_turno_player(bool turno_player_1){
	m_turno_player_1 = turno_player_1;
}

int Truco::obtenerRedisputar(){
	return max_redisputar;
}

int Truco::obtenerValor(){
	return valor;
}	

int Truco::obtenerCastigo(){
	return castigo;
}	

void Truco::cambiarUltimoEnTirar(int aux){
	ultimo_en_tirar = aux;
}

int Truco::verUltimoEnTirar(){
	return ultimo_en_tirar;
}


void Truco::setGenerated_by(int generated_by){
	m_generated_by = generated_by;
}
	
int Truco::obtenerStatus(){
	return status;
}

void Truco::aceptar(){
	status = 3;
}

void Truco::rechazar(){
	status = 2;
}

void Truco::cantar(){
	status = 1; 
	valor = 2;
	castigo = 1;
}
void Truco::dibujar(RenderWindow &w){
/*	w.draw(text);*/
	if(elementos_on[0] == 1){
		w.draw(s_truco);
	}
	if(elementos_on[1] == 1){
		w.draw(s_retruco);
	}
	if(elementos_on[2] == 1){
		w.draw(s_valecuatro);
	}
	if(elementos_on[3] == 1){
		w.draw(s_quiero);
	}
	if(elementos_on[4] == 1){
		w.draw(s_noquiero);
	}
	
}
