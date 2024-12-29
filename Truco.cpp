#include "Truco.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <atomic>

Truco::Truco(bool turno_player_1) : m_turno_player_1(turno_player_1){
	t_truco.loadFromFile("./images/truco.png");
	s_truco.setTexture(t_truco);
	s_truco.setPosition(Vector2f(400, 300));
	font.loadFromFile("fast99.ttf");
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setFillColor(sf::Color::Blue);
	text.setFont(font);
}

void Truco::actualizar(){
	
	if(status == 0){
		text.setString("Cantar truco");
		if(m_turno_player_1 == true){
			text.setPosition(100, 500);
		}else{
			text.setPosition(100, 100);
		}
	}
}

void Truco::dibujar(RenderWindow &w){
	w.draw(text);
}
