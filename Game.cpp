#include "Game.h"

using namespace std;
using namespace sf;
Game::Game() : player1(true), player2(false) {
	//Fondo
	background.loadFromFile("./images/fondo.png");
	background_s.setTexture(background);
	player2.setRival(&player1);
//	player1.setOponente(&player2);
//	player2.setOponente(&player1);
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
