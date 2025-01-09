#include "Truco.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <atomic>
#include <iostream>

using namespace std;
using namespace sf;

Truco::Truco(bool turno_player_1) : m_turno_player_1(turno_player_1){
	t_truco.loadFromFile("./images/truco.png");
	s_truco.setTexture(t_truco);
	s_truco.setPosition(Vector2f(400, 300));
	font.loadFromFile("nueva.otf");
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
}

void Truco::actualizar(){
	
	if(m_turno_player_1 == true){
		text.setPosition(100, 500);
	}else{
		text.setPosition(100, 100);
	}
	
	if(status == 0){
		text.setString("Cantar truco");
		return;
	}
	
	if(status == 1){
		if(max_redisputar == 0){
			text.setString("Aceptar - Rechazar");
			return;
		}
		if(max_redisputar == 1){
			text.setString("Aceptar - Rechazar - Quiero vale 4");
			return;
		}
		text.setString("Aceptar - Rechazar - Quiero re truco");
		return;
	}
	
	
	if(status == 3 and max_redisputar == 2){
		if(m_generated_by == 1 and m_turno_player_1 == false){
			text.setString("Re-truco");
			return;
		}
		else if(m_generated_by == 2 and m_turno_player_1 == true){
			text.setString("Re-truco");
			return;
		}else{
			text.setString("");
		}
		
		return;
	}
	
	if(status == 3 and max_redisputar == 1){
		if(m_generated_by == 1 and m_turno_player_1 == false){
			text.setString("Vale cuatro");
			return;
		}
		else if(m_generated_by == 2 and m_turno_player_1 == true){
			text.setString("Vale cuatro");
			return;
		}else{
			text.setString("");
		}
		
		return;
	}
	
	if(status == 3 and max_redisputar == 0){
		text.setString(" ");
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
	w.draw(text);
}
