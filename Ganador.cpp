#include "Ganador.h"
#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include <cstring>
#include "Juego.h"


Ganador::Ganador(Window *w, bool player1ganador, int player1puntos, int player2puntos) : m_window(w), m_player1ganador(player1ganador), m_player1puntos(player1puntos), m_player2puntos(player2puntos) {
	font.loadFromFile("./utils/rara.ttf");
	
	
	
	m_input.setStyle(sf::Text::Bold);
	m_input.setFont(font);
	m_input.setPosition(280, 400);
	m_input.setCharacterSize(60);
	m_input.setMaxChars(8);
	
	texto_info.setStyle(sf::Text::Bold);
	texto_info.setFont(font);
	texto_info.setPosition(200, 510);
	texto_info.setCharacterSize(30);
	texto_info.setString("<Presiona Enter para continuar>");
	
	texto_info2.setStyle(sf::Text::Bold);
	texto_info2.setFont(font);
	texto_info2.setPosition(275, 380);
	texto_info2.setCharacterSize(30);
	texto_info2.setString("Ingrese su nombre: ");
	
	t_ganador1.loadFromFile("./images/ganador1.png");
	s_ganador1.setTexture(t_ganador1);
	
	t_ganador2.loadFromFile("./images/ganador2.png");
	s_ganador2.setTexture(t_ganador2);
	
	
}

void Ganador::actualizar(Juego &j){
	m_input.update();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		Partida partida;
		nombre = m_input.getValue();
		std::strncpy(nombredef, nombre.c_str(), sizeof(nombredef));
		partida.player1win = m_player1ganador;
		partida.player1puntos = m_player1puntos;
		partida.player2puntos = m_player2puntos;
		std::strncpy(nombredef, nombre.c_str(), 8); 
		nombredef[8] = '\0'; 
		std::strncpy(partida.nombre, nombredef, 8);
		partida.nombre[8] = '\0'; 
		j.agregarPartida(partida);
		j.actualizarEscena(new Menu(m_window));
	}
	
	
}

void Ganador::ProcessEvent(Juego &j, Event &event){
	m_input.processEvent(event);
}

void Ganador::dibujar(RenderWindow &w){
	if(m_player1ganador){
		w.draw(s_ganador1);
	}else{
		w.draw(s_ganador2);
	}
	
	w.draw(texto_info);
	w.draw(texto_info2);
	w.draw(m_input);

}
