#include "Truco.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <atomic>
#include <iostream>
using namespace std;

Truco::Truco(bool turno_player_1) : m_turno_player_1(turno_player_1){
	t_truco.loadFromFile("./images/truco.png");
	s_truco.setTexture(t_truco);
	s_truco.setPosition(Vector2f(400, 300));
	font.loadFromFile("fast99.ttf");
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
	
	
	if(status == 3){
		text.setString("Truco en juego!!!!");
		return;
	}

}

void Truco::aceptar(){
	status = 3;
	cout << status << "Este es el status";
}

void Truco::rechazar(){
	status = 2;
	cout << status << "Este es el status";
}

void Truco::cantar(){
	status = 1; 
}
void Truco::dibujar(RenderWindow &w){
	w.draw(text);
}
