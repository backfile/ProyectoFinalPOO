#include "Match.h"
#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "Menu.h"
#include "Juego.h"
#include "Ganador.h"
using namespace std;


Match::Match(Window *w) {
	m_window = w;
	round = new Round(jugar_primero, w);
	t_background.loadFromFile("./images/fondo.png");
	s_background.setTexture(t_background);

	
	t_repartiendo.loadFromFile("./images/repartiendo.png");
	s_repartiendo.setTexture(t_repartiendo);
	s_repartiendo.setOrigin(100, 50);
	s_repartiendo.setPosition(400, 300);
	
	font.loadFromFile("rara.ttf");
	
	text_player1.setStyle(sf::Text::Bold);
	text_player1.setFillColor(sf::Color::White);
	text_player1.setFont(font);
	text_player1.setPosition(50, 550);
	text_player1.setString("0");
	
	text_player2.setStyle(sf::Text::Bold);
	text_player2.setFillColor(sf::Color::White);
	text_player2.setFont(font);
	text_player2.setPosition(750, 50);
	text_player2.setString("0");
	
}


void Match::actualizar(Juego &j){
	if(player1_puntos > 29){
		sf::sleep(sf::seconds(3));
		j.actualizarEscena(new Ganador(m_window, true, player1_puntos, player2_puntos));
	}
	if(player2_puntos > 29){
		sf::sleep(sf::seconds(3));
		j.actualizarEscena(new Ganador(m_window, false, player1_puntos, player2_puntos));
	}
	
	cont ++;
	if(!round->getStatus())
	{	
		sf::sleep(sf::seconds(2));
		aux = true;
		cont = 0;
		if(round->getStatusTruco() == 2){
			player1_puntos += round->getPuntosPlayer1();
			player2_puntos += round->getPuntosPlayer2();
		}
		
		if(round->getStatusTruco() == 3 or round->getStatusTruco() == 0){
			if(round->getPlayer1ganador() == true){
				player1_puntos += round->getPuntosGanador();
			}else{
				player2_puntos += round->getPuntosGanador();
			}
		}
		
		if(player1_puntos > 29){
			sf::sleep(sf::seconds(1));
			j.actualizarEscena(new Ganador(m_window, true, player1_puntos, player2_puntos));
		}
		if(player2_puntos > 29){
			sf::sleep(sf::seconds(1));
			j.actualizarEscena(new Ganador(m_window, false, player1_puntos, player2_puntos));
		}
		
		string puntos_player1 = to_string(player1_puntos);
		string puntos_player2 = to_string(player2_puntos);
		text_player1.setString(puntos_player1);
		text_player2.setString(puntos_player2);
		
		jugar_primero = !jugar_primero;
	
		
		delete round;
		round = new Round(jugar_primero, m_window);
		
	}
	
	
	
	if(cont < 100){
		return;
	}
	
	
	if(round->obtener_envido_listo_para_sumar() == true and aux == true){
		aux = false;
		if(round->obtenerGanadorEnvido() == true){
			//Gano player 1
			if(round->obtenerPuntosEnvidoPlayer1() == -1){
				player1_puntos += 30 - player2_puntos;
			}else{
				player1_puntos += round->obtenerPuntosEnvidoPlayer1();
			}

		}else{
			if(round->obtenerPuntosEnvidoPlayer2() == -1){
				player2_puntos += 30 - player1_puntos;
			}else{
				player2_puntos += round->obtenerPuntosEnvidoPlayer2();
			}
	
		}
		string puntos_player1 = to_string(player1_puntos);
		string puntos_player2 = to_string(player2_puntos);
		text_player1.setString(puntos_player1);
		text_player2.setString(puntos_player2);
		
	}
	
	round->actualizar();

};

void Match::obtener_puntos(){
	player1_puntos+=round->getPuntosPlayer1();
	player2_puntos+=round->getPuntosPlayer2();
}

void Match::dibujar(RenderWindow &w){

	w.clear(Color(255,255,255,255));
	w.draw(s_background);
	if(cont < 100){
		w.draw(s_repartiendo);
		return;
	}
	w.draw(text_player1);
	w.draw(text_player2);
	round->dibujar(w);
}
