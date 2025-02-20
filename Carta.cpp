#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

Carta::Carta(string imageFile, int power, int tipo, int numero) {
	m_power = power;
	m_tipo = tipo;
	m_numero = numero;
	m_is_selected = false;
	m_en_mano = true;
	m_textureFile = imageFile;
	m_s.setOrigin(104, 159.5);
	
}

void Carta::actualizarTextura(Vector2f posicion, bool player1){
	if(player1){
		//Parte de adelante de la carta
		m_t.loadFromFile(m_textureFile);
	}else{
		//Parte trasera de la carta
		m_t.loadFromFile(path_trasera);
	}
	
	m_s.setTexture(m_t);
	m_s.setPosition(posicion);
}

Sprite Carta::obtenerSprite(){
	return m_s;
}

void Carta::actualizar(){
	
	if(m_en_mano){		
		if(m_is_selected){
			m_s.setScale(Vector2f(1, 1));
		}else{
			m_s.setScale(Vector2f(0.9, 0.9));
		}
	}else{
		m_s.setScale(Vector2f(0, 0));
	}
}


Texture Carta::obtenerTextura(){
	return m_t;
}

int Carta::verTipo(){
	return m_tipo;
}

int Carta::verNumero(){
	return m_numero;
}

int Carta::verPoder(){
	return m_power;
}

void Carta::actualizar_mesa(int i){
	//Al tirarla a la mesa, mostrar siempre la parte de adelante
	m_t.loadFromFile(m_textureFile);
	m_s.setTexture(m_t);
	//Cambiar la escala y la posicion segun la cantidad de cartas tiradas previamente
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
