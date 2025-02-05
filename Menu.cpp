#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Match.h"
#include "Juego.h"

Menu::Menu(Window *w) : m_window(w) {
	t_fondo.loadFromFile("images/fondomenu.png");
	s_fondo.setTexture(t_fondo);
}

void Menu::actualizar(Juego &j){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		j.actualizarEscena(new Match(m_window));
	}
}

void Menu::dibujar(RenderWindow &w){
	w.draw(s_fondo);
}
