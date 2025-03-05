#include "Ganador.h"
#include "Menu.h"


Ganador::Ganador(Window *w, bool player1ganador) : m_window(w), m_player1ganador(player1ganador) {
	t_ganador1.loadFromFile("./images/ganador1.png");
	s_ganador1.setTexture(t_ganador1);
	
	t_ganador2.loadFromFile("./images/ganador2.png");
	s_ganador2.setTexture(t_ganador2);
	
	MenuBoton.setSize(Vector2f(147, 75));
	MenuBoton.setPosition(326, 335);
	
	t_menuboton_encima.loadFromFile("./images/menuganador_porencima.png");
	s_menuboton_encima.setTexture(t_menuboton_encima);
	
}

void Ganador::actualizar(Juego &j){
	mousePos = sf::Mouse::getPosition(*m_window);
	if(MenuBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		menuboton_porEncima = true;
	}else{
		menuboton_porEncima = false;
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(MenuBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Menu(m_window));
		}
	}
}

void Ganador::dibujar(RenderWindow &w){
	if(m_player1ganador){
		w.draw(s_ganador1);
	}else{
		w.draw(s_ganador2);
	}
	
	if(menuboton_porEncima){
		w.draw(s_menuboton_encima);
	}
}
