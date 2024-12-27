#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

Carta::Carta(string imageFile, int power, int tipo, int numero, Vector2f posicion) {
	m_t.loadFromFile(imageFile);
	m_power = power;
	m_tipo = tipo;
	m_s.setTexture(m_t);
	m_s.setPosition(posicion);
	m_is_selected = false;
	m_en_mano = true;
	m_s.setOrigin(104, 159.5);
}

void Carta::actualizar(){
	if(m_en_mano){		
		if(m_is_selected){
			m_s.setScale(Vector2f(1.3, 1.3));
		}else{
			m_s.setScale(Vector2f(1, 1));
		}
	}else{
		m_s.setScale(Vector2f(0, 0));
	}
}

void Carta::actualizar_mesa(int i){
	m_s.setScale(Vector2f(0.7, 0.7));
	m_s.setPosition(Vector2f(400+i, 300));
}

void Carta::is_selected(bool aux){
	m_is_selected = aux;
}

void Carta::tirar(){
	m_en_mano = false;
}

void Carta::dibujar(RenderWindow &m){
	m.draw(m_s);
}
