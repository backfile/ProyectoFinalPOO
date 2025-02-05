#include "Ganador.h"
#include "Menu.h"


Ganador::Ganador(Window *w, bool player1ganador, int puntosplayer1, int puntosplayer2) : m_window(w), m_player1ganador(player1ganador), m_puntosplayer1(puntosplayer1), m_puntosplayer2(puntosplayer2) {
	t_ganador1.loadFromFile("./images/ganador1.png");
	s_ganador1.setTexture(t_ganador1);
	
	t_ganador2.loadFromFile("./images/ganador2.png");
	s_ganador2.setTexture(t_ganador2);
	
}

void Ganador::actualizar(Juego &j){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
		j.actualizarEscena(new Menu(m_window));
	}
}

void Ganador::dibujar(RenderWindow &w){
	if(m_player1ganador){
		w.draw(s_ganador1);
	}else{
		w.draw(s_ganador2);
	}
}
