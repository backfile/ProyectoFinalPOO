#include "Historial.h"
#include <iostream>
using namespace std;

Historial::Historial(Window *w) : m_window(w){
	t_background.loadFromFile("./images/fondohistorial.png");
	s_background.setTexture(t_background);
	font.loadFromFile("rara.ttf");
	
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
		texts[i].setFillColor(sf::Color::Black);
		texts[i].setFont(font);
		texts[i].setPosition(140, 50);
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
			texts[i].move(0, aux*100);
			texts[i].setString("Tus puntos: "+ puntos + "                 " + "Puntos del rival: " + puntos2);
			
		}
	}
	
}

void Historial::dibujar(RenderWindow &w){
	w.draw(s_background);
	for(size_t i=0;i<v.size();i++) { 
		w.draw(texts[i]);
	}
}
