#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Juego.h"
#include "Historial.h"

Menu::Menu(Window *w) : m_window(w) {
	t_fondo.loadFromFile("images/fondomenu.png");
	s_fondo.setTexture(t_fondo);
	
	t_NuevaPartidaBoton_porEncima.loadFromFile("images/nuevapartida_porencima.png");
	s_NuevaPartidaBoton_porEncima.setTexture(t_NuevaPartidaBoton_porEncima);
	NuevaPartidaBoton.setSize(Vector2f(196, 152));
	NuevaPartidaBoton.setPosition(301, 85);
	
	t_HistorialBoton_porEncima.loadFromFile("images/historial_porencima.png");
	s_HistorialBoton_porEncima.setTexture(t_HistorialBoton_porEncima);
	HistorialBoton.setSize(Vector2f(230, 120));
	HistorialBoton.setPosition(292, 388);
	
}

void Menu::actualizar(Juego &j){
	
	mousePos = sf::Mouse::getPosition(*m_window);
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(NuevaPartidaBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Match(m_window));
		}
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(HistorialBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Historial(m_window));
		}
	}
	
	if(NuevaPartidaBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		NuevaPartidaBoton_porEncima = true;
	}else{
		NuevaPartidaBoton_porEncima = false;
	}
	
	
	if(HistorialBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		HistorialBoton_porEncima = true;
	}else{
		HistorialBoton_porEncima = false;
	}
}

void Menu::dibujar(RenderWindow &w){
	w.draw(s_fondo);
	if(NuevaPartidaBoton_porEncima){
		w.draw(s_NuevaPartidaBoton_porEncima);
	}
	if(HistorialBoton_porEncima){
		w.draw(s_HistorialBoton_porEncima);
	}
}
