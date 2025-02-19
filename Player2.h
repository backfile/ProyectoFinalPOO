#ifndef PLAYER2_H
#define PLAYER2_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Carta.h"
#include "Player.h"

class Round;

struct BotJuego{
	int envido;
	int truco;
};


using namespace std;

class Player2 {
public:
	Player2(bool turno, Mazo *mazo, Truco *truco, Envido *envido, Player *rival, Window *w);
	void dibujar(RenderWindow &m);
	void actualizar(Round &round);
	void seleccionarCarta();
	bool obtenerTurno();
	void cederTurno();
	void iniciar();
	int verCartasEnMano();
	void definirBotJuego();
	void jugar();
	bool Exepcion();
	void setPuntosEnvido(int aux);
	void cambiarTurno(bool aux);
	void setRival(Player *aux);
	vector<Carta> obtener_en_mesa();
	vector<Carta> obtener_cartas();
	
private:
	
	bool m_turno;
	bool aux = true;
	int carta_selected = -1;
	int cartas_en_mano = 3;
	int puntos_envido;
	Player* m_rival;
	
	//Se comparten	
	Mazo *m_mazo;
	Truco *m_truco;
	Envido *m_envido;
	Window *m_window;
	
	vector<Carta>cartas;
	vector<Carta>en_mesa;
	
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
	
	//Datos de la jubilidad que el bot adaptará en la ronda
	BotJuego botjuego;
	
};

#endif

