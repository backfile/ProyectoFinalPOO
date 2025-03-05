#include "Match.h"
#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "Menu.h"
#include "Juego.h"
#include "Ganador.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <fstream>
using namespace std;


Match::Match(Window *w, int puntos_a_jugar) : puntos_para_ganar(puntos_a_jugar) {
	m_window = w;
	round = new Round(jugar_primero, w);
	t_background.loadFromFile("./images/fondo.png");
	s_background.setTexture(t_background);

	
	t_repartiendo.loadFromFile("./images/repartiendo.png");
	s_repartiendo.setTexture(t_repartiendo);
	s_repartiendo.setOrigin(100, 50);
	s_repartiendo.setPosition(400, 300);
	

	
	font.loadFromFile("./utils/rara.ttf");
	
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
	
	//Palitos
	t_madera.loadFromFile("./images/texturamadera.jpg");
	s_madera.setTexture(t_madera);
	
	//Player1
	
	sf::RectangleShape palito1;
	sf::RectangleShape palito2;
	sf::RectangleShape palito3;
	sf::RectangleShape palito4;
	sf::RectangleShape palito5;
	sf::RectangleShape palito6;
	sf::RectangleShape palito7;
	sf::RectangleShape palito8;
	sf::RectangleShape palito9;
	sf::RectangleShape palito10;
	sf::RectangleShape palito11;
	sf::RectangleShape palito12;
	sf::RectangleShape palito13;
	sf::RectangleShape palito14;
	sf::RectangleShape palito15;
	sf::RectangleShape palito16;
	sf::RectangleShape palito17;
	sf::RectangleShape palito18;
	sf::RectangleShape palito19;
	sf::RectangleShape palito20;
	sf::RectangleShape palito21;
	sf::RectangleShape palito22;
	sf::RectangleShape palito23;
	sf::RectangleShape palito24;
	sf::RectangleShape palito25;
	sf::RectangleShape palito26;
	sf::RectangleShape palito27;
	sf::RectangleShape palito28;
	sf::RectangleShape palito29;
	sf::RectangleShape palito30;
	
	
	sf::RectangleShape Apalito1;
	sf::RectangleShape Apalito2;
	sf::RectangleShape Apalito3;
	sf::RectangleShape Apalito4;
	sf::RectangleShape Apalito5;
	sf::RectangleShape Apalito6;
	sf::RectangleShape Apalito7;
	sf::RectangleShape Apalito8;
	sf::RectangleShape Apalito9;
	sf::RectangleShape Apalito10;
	sf::RectangleShape Apalito11;
	sf::RectangleShape Apalito12;
	sf::RectangleShape Apalito13;
	sf::RectangleShape Apalito14;
	sf::RectangleShape Apalito15;
	sf::RectangleShape Apalito16;
	sf::RectangleShape Apalito17;
	sf::RectangleShape Apalito18;
	sf::RectangleShape Apalito19;
	sf::RectangleShape Apalito20;
	sf::RectangleShape Apalito21;
	sf::RectangleShape Apalito22;
	sf::RectangleShape Apalito23;
	sf::RectangleShape Apalito24;
	sf::RectangleShape Apalito25;
	sf::RectangleShape Apalito26;
	sf::RectangleShape Apalito27;
	sf::RectangleShape Apalito28;
	sf::RectangleShape Apalito29;
	sf::RectangleShape Apalito30;
	
	palito1.setSize(Vector2f(50, 4));
	palito1.setPosition(Vector2f(9, 550));
	palito1.setOrigin(Vector2f(0, 4));
	palito1.setFillColor(sf::Color::White);
	palitos.push_back(palito1);
	
	palito2.setSize(Vector2f(4, 50));
	palito2.setPosition(Vector2f(9, 550));
	palito2.setOrigin(Vector2f(0, 50));
	palito2.setFillColor(sf::Color::White);
	palitos.push_back(palito2);
	
	palito3.setSize(Vector2f(50, 4));
	palito3.setPosition(Vector2f(9, 500));
	palito3.setOrigin(Vector2f(0, 4));
	palito3.setFillColor(sf::Color::White);
	palitos.push_back(palito3);
	
	palito4.setSize(Vector2f(4, 50));
	palito4.setPosition(Vector2f(59, 550));
	palito4.setOrigin(Vector2f(0, 50));
	palito4.setFillColor(sf::Color::White);
	palitos.push_back(palito4);
	
	palito5.setSize(Vector2f(4, 75));
	palito5.setPosition(Vector2f(9, 550));
	palito5.setOrigin(Vector2f(0, 75));
	palito5.setRotation(45);
	palito5.setFillColor(sf::Color::White);
	
	palitos.push_back(palito5);
	
	
	
	
	palito6.setSize(Vector2f(50, 4));
	palito6.setPosition(Vector2f(9, 490));
	palito6.setOrigin(Vector2f(0, 4));
	palito6.setFillColor(sf::Color::White);
	palitos.push_back(palito6);
	
	palito7.setSize(Vector2f(4, 50));
	palito7.setPosition(Vector2f(9, 490));
	palito7.setOrigin(Vector2f(0, 50));
	palito7.setFillColor(sf::Color::White);
	palitos.push_back(palito7);
	
	palito8.setSize(Vector2f(50, 4));
	palito8.setPosition(Vector2f(9, 440));
	palito8.setOrigin(Vector2f(0, 4));
	palito8.setFillColor(sf::Color::White);
	palitos.push_back(palito8);
	
	palito9.setSize(Vector2f(4, 50));
	palito9.setPosition(Vector2f(59, 490));
	palito9.setOrigin(Vector2f(0, 50));
	palito9.setFillColor(sf::Color::White);
	palitos.push_back(palito9);
	
	palito10.setSize(Vector2f(4, 75));
	palito10.setPosition(Vector2f(9, 490));
	palito10.setOrigin(Vector2f(0, 75));
	palito10.setFillColor(sf::Color::White);
	palito10.setRotation(45);
	palitos.push_back(palito10);
	
	
	
	
	palito11.setSize(Vector2f(50, 4));
	palito11.setPosition(Vector2f(9, 430));
	palito11.setOrigin(Vector2f(0, 4));
	palito11.setFillColor(sf::Color::White);
	palitos.push_back(palito11);
	
	palito12.setSize(Vector2f(4, 50));
	palito12.setPosition(Vector2f(9, 430));
	palito12.setOrigin(Vector2f(0, 50));
	palito12.setFillColor(sf::Color::White);
	palitos.push_back(palito12);
	
	palito13.setSize(Vector2f(50, 4));
	palito13.setPosition(Vector2f(9, 380));
	palito13.setOrigin(Vector2f(0, 4));
	palito13.setFillColor(sf::Color::White);
	palitos.push_back(palito13);
	
	palito14.setSize(Vector2f(4, 50));
	palito14.setPosition(Vector2f(59, 430));
	palito14.setOrigin(Vector2f(0, 50));
	palito14.setFillColor(sf::Color::White);
	palitos.push_back(palito14);
	
	palito15.setSize(Vector2f(4, 75));
	palito15.setPosition(Vector2f(9, 430));
	palito15.setOrigin(Vector2f(0, 75));
	palito15.setFillColor(sf::Color::White);
	palito15.setRotation(45);
	palitos.push_back(palito15);
	
	
	
	palito16.setSize(Vector2f(50, 4));
	palito16.setPosition(Vector2f(9, 370));
	palito16.setOrigin(Vector2f(0, 4));
	palito16.setFillColor(sf::Color::White);
	palitos.push_back(palito16);
	
	palito17.setSize(Vector2f(4, 50));
	palito17.setPosition(Vector2f(9, 370));
	palito17.setOrigin(Vector2f(0, 50));
	palito17.setFillColor(sf::Color::White);
	palitos.push_back(palito17);
	
	palito18.setSize(Vector2f(50, 4));
	palito18.setPosition(Vector2f(9, 320));
	palito18.setOrigin(Vector2f(0, 4));
	palito18.setFillColor(sf::Color::White);
	palitos.push_back(palito18);
	
	palito19.setSize(Vector2f(4, 50));
	palito19.setPosition(Vector2f(59, 370));
	palito19.setOrigin(Vector2f(0, 50));
	palito19.setFillColor(sf::Color::White);
	palitos.push_back(palito19);
	
	palito20.setSize(Vector2f(4, 75));
	palito20.setPosition(Vector2f(9, 370));
	palito20.setOrigin(Vector2f(0, 75));
	palito20.setFillColor(sf::Color::White);
	palito20.setRotation(45);
	palitos.push_back(palito20);
	
	
	
	palito21.setSize(Vector2f(50, 4));
	palito21.setPosition(Vector2f(9, 310));
	palito21.setOrigin(Vector2f(0, 4));
	palito21.setFillColor(sf::Color::White);
	palitos.push_back(palito21);
	
	palito22.setSize(Vector2f(4, 50));
	palito22.setPosition(Vector2f(9, 310));
	palito22.setOrigin(Vector2f(0, 50));
	palito22.setFillColor(sf::Color::White);
	palitos.push_back(palito22);
	
	palito23.setSize(Vector2f(50, 4));
	palito23.setPosition(Vector2f(9, 260));
	palito23.setOrigin(Vector2f(0, 4));
	palito23.setFillColor(sf::Color::White);
	palitos.push_back(palito23);
	
	palito24.setSize(Vector2f(4, 50));
	palito24.setPosition(Vector2f(59, 310));
	palito24.setOrigin(Vector2f(0, 50));
	palito24.setFillColor(sf::Color::White);
	palitos.push_back(palito24);
	
	palito25.setSize(Vector2f(4, 75));
	palito25.setPosition(Vector2f(9, 310));
	palito25.setOrigin(Vector2f(0, 75));
	palito25.setFillColor(sf::Color::White);
	palito25.setRotation(45);
	palitos.push_back(palito25);
	
	
	
	palito26.setSize(Vector2f(50, 4));
	palito26.setPosition(Vector2f(9, 250));
	palito26.setOrigin(Vector2f(0, 4));
	palito26.setFillColor(sf::Color::White);
	palitos.push_back(palito26);
	
	palito27.setSize(Vector2f(4, 50));
	palito27.setPosition(Vector2f(9, 250));
	palito27.setOrigin(Vector2f(0, 50));
	palito27.setFillColor(sf::Color::White);
	palitos.push_back(palito27);
	
	palito28.setSize(Vector2f(50, 4));
	palito28.setPosition(Vector2f(9, 200));
	palito28.setOrigin(Vector2f(0, 4));
	palito28.setFillColor(sf::Color::White);
	palitos.push_back(palito28);
	
	palito29.setSize(Vector2f(4, 50));
	palito29.setPosition(Vector2f(59, 250));
	palito29.setOrigin(Vector2f(0, 50));
	palito29.setFillColor(sf::Color::White);
	palitos.push_back(palito29);
	
	palito30.setSize(Vector2f(4, 75));
	palito30.setPosition(Vector2f(9, 250));
	palito30.setOrigin(Vector2f(0, 75));
	palito30.setFillColor(sf::Color::White);
	palito30.setRotation(45);
	palitos.push_back(palito30);
	
	
	
	
	
	
	
	
	Apalito1.setSize(Vector2f(50, 4));
	Apalito1.setPosition(Vector2f(740, 50));
	Apalito1.setOrigin(Vector2f(0, 4));
	Apalito1.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito1);
	
	Apalito2.setSize(Vector2f(4, 50));
	Apalito2.setPosition(Vector2f(790, 100));
	Apalito2.setOrigin(Vector2f(0, 50));
	Apalito2.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito2);
	
	Apalito3.setSize(Vector2f(50, 4));
	Apalito3.setPosition(Vector2f(740, 100));
	Apalito3.setOrigin(Vector2f(0, 4));
	Apalito3.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito3);
	
	Apalito4.setSize(Vector2f(4, 50));
	Apalito4.setPosition(Vector2f(740, 100));
	Apalito4.setOrigin(Vector2f(0, 50));
	Apalito4.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito4);
	
	Apalito5.setSize(Vector2f(4, 75));
	Apalito5.setPosition(Vector2f(740, 100));
	Apalito5.setOrigin(Vector2f(0, 75));
	Apalito5.setFillColor(sf::Color::White);
	Apalito5.setRotation(45);
	Apalitos.push_back(Apalito5);
	
	
	
	Apalito6.setSize(Vector2f(50, 4));
	Apalito6.setPosition(Vector2f(740, 110));
	Apalito6.setOrigin(Vector2f(0, 4));
	Apalito6.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito6);
	
	Apalito7.setSize(Vector2f(4, 50));
	Apalito7.setPosition(Vector2f(790, 160));
	Apalito7.setOrigin(Vector2f(0, 50));
	Apalito7.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito7);
	
	Apalito8.setSize(Vector2f(50, 4));
	Apalito8.setPosition(Vector2f(740, 160));
	Apalito8.setOrigin(Vector2f(0, 4));
	Apalito8.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito8);
	
	Apalito9.setSize(Vector2f(4, 50));
	Apalito9.setPosition(Vector2f(740, 160));
	Apalito9.setOrigin(Vector2f(0, 50));
	Apalito9.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito9);
	
	Apalito10.setSize(Vector2f(4, 75));
	Apalito10.setPosition(Vector2f(740, 160));
	Apalito10.setOrigin(Vector2f(0, 75));
	Apalito10.setFillColor(sf::Color::White);
	Apalito10.setRotation(45);
	Apalitos.push_back(Apalito10);
	
	
	Apalito11.setSize(Vector2f(50, 4));
	Apalito11.setPosition(Vector2f(740, 170));
	Apalito11.setOrigin(Vector2f(0, 4));
	Apalito11.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito11);
	
	Apalito12.setSize(Vector2f(4, 50));
	Apalito12.setPosition(Vector2f(790, 220));
	Apalito12.setOrigin(Vector2f(0, 50));
	Apalito12.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito12);
	
	Apalito13.setSize(Vector2f(50, 4));
	Apalito13.setPosition(Vector2f(740, 220));
	Apalito13.setOrigin(Vector2f(0, 4));
	Apalito13.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito13);
	
	Apalito14.setSize(Vector2f(4, 50));
	Apalito14.setPosition(Vector2f(740, 220));
	Apalito14.setOrigin(Vector2f(0, 50));
	Apalito14.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito14);
	
	Apalito15.setSize(Vector2f(4, 75));
	Apalito15.setPosition(Vector2f(740, 220));
	Apalito15.setOrigin(Vector2f(0, 75));
	Apalito15.setFillColor(sf::Color::White);
	Apalito15.setRotation(45);
	Apalitos.push_back(Apalito15);
	
	
	
	
	
	Apalito16.setSize(Vector2f(50, 4));
	Apalito16.setPosition(Vector2f(740, 230));
	Apalito16.setOrigin(Vector2f(0, 4));
	Apalito16.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito16);
	
	Apalito17.setSize(Vector2f(4, 50));
	Apalito17.setPosition(Vector2f(790, 280));
	Apalito17.setOrigin(Vector2f(0, 50));
	Apalito17.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito17);
	
	Apalito18.setSize(Vector2f(50, 4));
	Apalito18.setPosition(Vector2f(740, 280));
	Apalito18.setOrigin(Vector2f(0, 4));
	Apalito18.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito18);
	
	Apalito19.setSize(Vector2f(4, 50));
	Apalito19.setPosition(Vector2f(740, 280));
	Apalito19.setOrigin(Vector2f(0, 50));
	Apalito19.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito19);
	
	Apalito20.setSize(Vector2f(4, 75));
	Apalito20.setPosition(Vector2f(740, 280));
	Apalito20.setOrigin(Vector2f(0, 75));
	Apalito20.setFillColor(sf::Color::White);
	Apalito20.setRotation(45);
	Apalitos.push_back(Apalito20);
	
	
	
	Apalito21.setSize(Vector2f(50, 4));
	Apalito21.setPosition(Vector2f(740, 290));
	Apalito21.setOrigin(Vector2f(0, 4));
	Apalito21.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito21);
	
	Apalito22.setSize(Vector2f(4, 50));
	Apalito22.setPosition(Vector2f(790, 340));
	Apalito22.setOrigin(Vector2f(0, 50));
	Apalito22.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito22);
	
	Apalito23.setSize(Vector2f(50, 4));
	Apalito23.setPosition(Vector2f(740, 340));
	Apalito23.setOrigin(Vector2f(0, 4));
	Apalito23.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito23);
	
	Apalito24.setSize(Vector2f(4, 50));
	Apalito24.setPosition(Vector2f(740, 340));
	Apalito24.setOrigin(Vector2f(0, 50));
	Apalito24.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito24);
	
	Apalito25.setSize(Vector2f(4, 75));
	Apalito25.setPosition(Vector2f(740, 340));
	Apalito25.setOrigin(Vector2f(0, 75));
	Apalito25.setFillColor(sf::Color::White);
	Apalito25.setRotation(45);
	Apalitos.push_back(Apalito25);
	
	
	
	
	Apalito26.setSize(Vector2f(50, 4));
	Apalito26.setPosition(Vector2f(740, 350));
	Apalito26.setOrigin(Vector2f(0, 4));
	Apalito26.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito26);
	
	Apalito27.setSize(Vector2f(4, 50));
	Apalito27.setPosition(Vector2f(790, 400));
	Apalito27.setOrigin(Vector2f(0, 50));
	Apalito27.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito27);
	
	Apalito28.setSize(Vector2f(50, 4));
	Apalito28.setPosition(Vector2f(740, 400));
	Apalito28.setOrigin(Vector2f(0, 4));
	Apalito28.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito28);
	
	Apalito29.setSize(Vector2f(4, 50));
	Apalito29.setPosition(Vector2f(740, 400));
	Apalito29.setOrigin(Vector2f(0, 50));
	Apalito29.setFillColor(sf::Color::White);
	Apalitos.push_back(Apalito29);
	
	Apalito30.setSize(Vector2f(4, 75));
	Apalito30.setPosition(Vector2f(740, 400));
	Apalito30.setOrigin(Vector2f(0, 75));
	Apalito30.setFillColor(sf::Color::White);
	Apalito30.setRotation(45);
	Apalitos.push_back(Apalito30);
	
	
	for(auto &palitos : Apalitos){
		palitos.setTexture(&t_madera);
	}
	for(auto &palitos : palitos){
		palitos.setTexture(&t_madera);
	}
}


void Match::actualizar(Juego &j){
	
	
	if(player1_puntos >= puntos_para_ganar or player2_puntos >= puntos_para_ganar){
		
		Partida partida;
		
		if(player1_puntos >= puntos_para_ganar){
			sf::sleep(sf::seconds(3));
			j.actualizarEscena(new Ganador(m_window, true));
			partida.player1win = true;
		}
		if(player2_puntos >= puntos_para_ganar){
			sf::sleep(sf::seconds(3));
			j.actualizarEscena(new Ganador(m_window, false));
			partida.player1win = false;
		}
		
		/*GuardarPartida();*/
		if(partida.player1win){			
			partida.player1puntos = puntos_para_ganar;
			partida.player2puntos = player2_puntos;
		}else{
			partida.player1puntos = player1_puntos;
			partida.player2puntos = puntos_para_ganar;
		}
		
		j.agregarPartida(partida);
	}
	
	cont ++;
	if(cont < 100){
		return;
	}
	
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
		
		if(player1_puntos >= puntos_para_ganar or player2_puntos >= puntos_para_ganar){
			
			Partida partida;
			
			if(player1_puntos >= puntos_para_ganar){
				sf::sleep(sf::seconds(1));
				j.actualizarEscena(new Ganador(m_window, true));
				partida.player1win = true;
			}
			if(player2_puntos >= puntos_para_ganar){
				sf::sleep(sf::seconds(1));
				j.actualizarEscena(new Ganador(m_window, false));
				partida.player1win = false;
			}
			
			/*GuardarPartida();*/
			if(partida.player1win){			
				partida.player1puntos = puntos_para_ganar;
				partida.player2puntos = player2_puntos;
			}else{
				partida.player1puntos = player1_puntos;
				partida.player2puntos = puntos_para_ganar;
			}
			
			j.agregarPartida(partida);
		}
		
		string puntos_player1 = to_string(player1_puntos);
		string puntos_player2 = to_string(player2_puntos);
		text_player1.setString(puntos_player1);
		text_player2.setString(puntos_player2);
		
		jugar_primero = !jugar_primero;
		round->actualizarCantoEnPantalla(0);
		
		
		delete round;
		round = new Round(jugar_primero, m_window);
		
	}
	
	

	
	
	if(round->obtener_envido_listo_para_sumar() == true and aux == true){
		aux = false;
		if(round->obtenerGanadorEnvido() == true){
			//Gano player 1
			if(round->obtenerPuntosEnvidoPlayer1() == -1){
				player1_puntos += puntos_para_ganar - player2_puntos;
			}else{
				player1_puntos += round->obtenerPuntosEnvidoPlayer1();
			}

		}else{
			if(round->obtenerPuntosEnvidoPlayer2() == -1){
				player2_puntos += puntos_para_ganar - player1_puntos;
			}else{
				player2_puntos += round->obtenerPuntosEnvidoPlayer2();
			}
	
		}
		//borrar creo
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
	
	
	// Mostrar todos los puntos con transparencia baja segun a cuanto se juega

	
	for(size_t i=0;i<palitos.size();i++) { 
		if(i < puntos_para_ganar){
			palitos[i].setFillColor(sf::Color(255, 255, 255, 50)); // Inicia con transparencia baja
			w.draw(palitos[i]);
		}
	}
	
	for(size_t i=0;i<Apalitos.size();i++) { 
		if(i < puntos_para_ganar){
			Apalitos[i].setFillColor(sf::Color(255, 255, 255, 50)); // Inicia con transparencia baja
			w.draw(Apalitos[i]);
		}
	}
	
	
	//Mostrar puntos ganados sin transparencia
	for(int i=0;i<player1_puntos;i++) { 
		if(i < puntos_para_ganar){
			palitos[i].setFillColor(sf::Color(255, 255, 255));
			w.draw(palitos[i]);
		}
	}	
	
	for(int i=0;i<player2_puntos;i++) { 
		if(i < puntos_para_ganar){
			Apalitos[i].setFillColor(sf::Color(255, 255, 255));
			w.draw(Apalitos[i]);
		}
	}	

	round->dibujar(w);
}
