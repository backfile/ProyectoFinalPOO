#include "Match.h"


Match::Match() {
	round = new Round(jugar_primero);
	t_background.loadFromFile("./images/fondo.png");
	s_background.setTexture(t_background);
	
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
	
	
	espera.setStyle(sf::Text::Bold);
	espera.setFillColor(sf::Color::Green);
	espera.setFont(font);
	espera.setPosition(330, 300);
	espera.setString("Repartiendo");
}


void Match::actualizar(){
	cont ++;
	if(!round->getStatus())
	{	
		
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
		
		string puntos_player1 = to_string(player1_puntos);
		string puntos_player2 = to_string(player2_puntos);
		text_player1.setString(puntos_player1);
		text_player2.setString(puntos_player2);
		
		jugar_primero = !jugar_primero;
	
		
		delete round;
		round = new Round(jugar_primero);
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
		w.draw(espera);
		return;
	}
	w.draw(text_player1);
	w.draw(text_player2);
	round->dibujar(w);
}
