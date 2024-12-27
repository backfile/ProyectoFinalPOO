#include "Game.h"

#include <iostream>
using namespace std;
using namespace sf;
Game::Game() : player1(true, &mazo), player2(false, &mazo) {
	//Fondo
	background.loadFromFile("./images/fondo.png");
	background_s.setTexture(background);
	
	//Inicializar players con sus valores
	player2.setRival(&player1);
	player2.obtener3cartas();
	player1.obtener3cartas();

}

void Game::actualizar(){
	if(player1.obtenerTurno()){
		player1.actualizar();
	}else{
		player2.actualizar();
	}
}

void Game::Dibujar(RenderWindow &w) {
	w.clear(Color(255,255,255,255));
	w.draw(background_s);
	player1.dibujar(w);
	player2.dibujar(w);
}

void Game::getTurno(){
	m_turno_player = !m_turno_player;
}
