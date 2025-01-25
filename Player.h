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



using namespace std;


class Player {
public:
	Player(bool turno, Mazo *mazo, Truco *truco, Envido *envido);
	
	void dibujar(RenderWindow &m);
	void actualizar();
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
	//Se comparten
	Mazo *m_mazo;
	Truco *m_truco;
	Envido *m_envido;
	
	
	vector<Carta>cartas;
	vector<Carta>en_mesa;

};

#endif

