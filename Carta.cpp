#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

Carta::Carta(string imageFile, int power, int tipo, int numero) {
	m_power = power;
	m_tipo = tipo;
	m_is_selected = false;
	m_en_mano = true;
	m_textureFile = imageFile;
	m_s.setOrigin(104, 159.5);
}

void Carta::actualizarTextura(Vector2f posicion){
	m_t.loadFromFile(m_textureFile);
	m_s.setTexture(m_t);
	m_s.setPosition(posicion);
}

void Carta::actualizar(){
	if(m_en_mano){		
		if(m_is_selected){
			m_s.setScale(Vector2f(1.2, 1.2));
		}else{
			m_s.setScale(Vector2f(1, 1));
		}
	}else{
		m_s.setScale(Vector2f(0, 0));
	}
}


Texture Carta::obtenerTextura(){
	return m_t;
}

int Carta::verPoder(){
	return m_power;
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

bool Carta::obtenerEnMano(){
	return m_en_mano;
}

void Carta::dibujar(RenderWindow &m){
	m.draw(m_s);
}
