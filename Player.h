#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "ValoresCartas.h"
#include "Mazo.h"
#include "Truco.h"
#include "Envido.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>

class Round;

using namespace std;
using namespace sf;

class Player {
public:
	Player(bool turno, Mazo *mazo, Truco *truco, Envido *envido, Window *w);
	
	void dibujar(RenderWindow &m);
	void actualizar(Round &round);
	void cederTurno();
	void seleccionarCarta();
	void iniciar();
	bool obtenerTurno();
	int verCartasEnMano();
	void cambiarTurno(bool aux);
	void restarCartasEnManoPlayer2();
	vector<Carta> obtener_en_mesa();
	vector<Carta> obtener_cartas();
	
	
private:
	bool m_turno;
	int carta_selected = -1;
	int cartas_en_mano = 3;
	bool tiene_responder = false;
	int cartas_en_mano_player2 = 3;
	int canto_actual; //Lo lee round
	
	
	//Se comparten
	Mazo *m_mazo;
	Truco *m_truco;
	Envido *m_envido;
	Window *m_window;

	
	vector<Carta>cartas;
	vector<Carta>en_mesa;
	vector<sf::RectangleShape> botonesAreas; //Unicacion de cada boton disponible
	
	//Botones Truco
	sf::RectangleShape TrucoBoton;
	sf::RectangleShape ReTrucoBoton;
	sf::RectangleShape ValeCuatroBoton;
	sf::RectangleShape QuieroBoton;
	sf::RectangleShape NoQuieroBoton;
	
	//Botones Envido
	sf::RectangleShape EnvidoBoton;
	sf::RectangleShape EnvidoEnvidoBoton;
	sf::RectangleShape RealEnvidoBoton;
	sf::RectangleShape FaltaEnvidoBoton;
	sf::RectangleShape QuieroEnvidoBoton;
	sf::RectangleShape NoQuieroEnvidoBoton;
	
	//Ubicacion del Mouse
	sf::Vector2i mousePos;
	
	//Rectangulo que simula la zona donde podes clickear para tirar la carta
	sf::RectangleShape ZonaTirarCartas;

};

#endif

