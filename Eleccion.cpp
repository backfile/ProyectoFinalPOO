#include "Eleccion.h"
#include "Match.h"
#include "Juego.h"

Eleccion::Eleccion(Window *w) {
	m_window = w;
	t_background.loadFromFile("./images/fondoeleccion.png");
	s_background.setTexture(t_background);
	
	puntos5boton.setSize(Vector2f(164, 78));
	puntos5boton.setPosition(306, 179);
	
	puntos15boton.setSize(Vector2f(164, 78));
	puntos15boton.setPosition(311, 315);
	
	puntos30boton.setSize(Vector2f(164, 78));
	puntos30boton.setPosition(317, 441);
	
	t_flechaeleccion1.loadFromFile("./images/flechaeleccion1.png");
	s_flechaeleccion1.setTexture(t_flechaeleccion1);
		
	t_flechaeleccion2.loadFromFile("./images/flechaeleccion2.png");
	s_flechaeleccion2.setTexture(t_flechaeleccion2);
		
	t_flechaeleccion3.loadFromFile("./images/flechaeleccion3.png");
	s_flechaeleccion3.setTexture(t_flechaeleccion3);
}

void Eleccion::actualizar(Juego &j){
	mousePos = sf::Mouse::getPosition(*m_window);
	if(puntos5boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		puntos5Boton_porEncima = true;
	}else{
		puntos5Boton_porEncima = false;
	}
	
	if(puntos15boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		puntos15Boton_porEncima = true;
	}else{
		puntos15Boton_porEncima = false;
	}
	
	if(puntos30boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		puntos30Boton_porEncima = true;
	}else{
		puntos30Boton_porEncima = false;
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) and aux <= 0){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(puntos5boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Match(m_window, 5));
		}
		if(puntos15boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Match(m_window, 15));
		}
		if(puntos30boton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Match(m_window, 30));
		}
	}
	aux --;
}

void Eleccion::dibujar(RenderWindow &w){
	w.draw(s_background);
	if(puntos5Boton_porEncima){
		w.draw(s_flechaeleccion1);
	}
	if(puntos15Boton_porEncima){
		w.draw(s_flechaeleccion2);
	}
	if(puntos30Boton_porEncima){
		w.draw(s_flechaeleccion3);
	}
} 
