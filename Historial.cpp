#include "Historial.h"
#include <iostream>
#include "Menu.h"
using namespace std;

Historial::Historial(Window *w) : m_window(w){
	t_background.loadFromFile("./images/fondohistorial.png");
	s_background.setTexture(t_background);
	font.loadFromFile("rara.ttf");
	
	flechaBoton.setSize(Vector2f(137, 45));
	flechaBoton.setPosition(617, 505);
	
	t_flecha.loadFromFile("./images/retroceder.png");
	s_flecha.setTexture(t_flecha);
	
	t_flecha_encima.loadFromFile("./images/retroceder_encima.png");
	s_flecha_encima.setTexture(t_flecha_encima);
	
	Text text1;
	Text text2;
	Text text3;
	Text text4;
	Text text5;
	
	texts.push_back(text1);
	texts.push_back(text2);
	texts.push_back(text3);
	texts.push_back(text4);
	texts.push_back(text5);
	
	for(size_t i=0;i<texts.size();i++) { 
		texts[i].setStyle(sf::Text::Bold);
		texts[i].setFont(font);
		texts[i].setPosition(120, 120);
	}
}

void Historial::actualizar(Juego &j){
	if(primera_vez){
		int aux = -1;
		primera_vez = false;
		
		v = j.obtenerHistorial();
		if(v.empty()){return;}
		
		for(int i=v.size()-1;i>=0;i--) { 
			aux ++;
			string puntos = to_string(v[i].player1puntos);
			string puntos2 = to_string(v[i].player2puntos);
			if(v[i].player1win){
				texts[i].setFillColor(sf::Color::Green);
			}else{
				texts[i].setFillColor(sf::Color::Red);
			}
			texts[i].move(0, aux*80);
			texts[i].setString("#"+to_string(aux+1)+ "  Tus puntos: "+ puntos + "                 " + "Puntos del rival: " + puntos2);
			
		}
	}
	
	mousePos = sf::Mouse::getPosition(*m_window);
	if(flechaBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
		flecha_porEncima = true;
	}else{
		flecha_porEncima = false;
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		mousePos = sf::Mouse::getPosition(*m_window);
		if(flechaBoton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))){
			j.actualizarEscena(new Menu(m_window));
		}
	}
	
}

void Historial::dibujar(RenderWindow &w){
	w.draw(s_background);
	for(size_t i=0;i<v.size();i++) { 
		w.draw(texts[i]);
	}
	if(flecha_porEncima){
		w.draw(s_flecha_encima);
	}else{
		w.draw(s_flecha);
	}
	
	
}
