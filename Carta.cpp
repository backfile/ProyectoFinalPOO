#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>

Carta::Carta(string imageFile, int power, int tipo, int numero, Vector2f posicion) {
	m_t.loadFromFile(imageFile);
	m_power = power;
	m_tipo = tipo;
	m_s.setTexture(m_t);
	m_s.setPosition(posicion);
}



void Carta::dibujar(RenderWindow &m){
	m.draw(m_s);
}
