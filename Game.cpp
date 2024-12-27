#include "Game.h"


using namespace sf;
Game::Game() {
	//Fondo
	background.loadFromFile("./images/fondo.png");
	background_s.setTexture(background);
}

void Game::actualizar(){
	player1.actualizar();
}

void Game::Dibujar(RenderWindow &w) {
	w.clear(Color(255,255,255,255));
	w.draw(background_s);
	player1.dibujar(w);
}

void Game::CambiarTurno(){
	m_turno_player = !m_turno_player;
}
