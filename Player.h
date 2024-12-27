#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "ValoresCartas.h"
#include "Mazo.h"



using namespace std;

class Player {
public:
	Player(bool turno, Mazo *mazo);
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
	void obtener3cartas();
	bool obtenerTurno();
	int verCartasEnMano();
	void cambiarTurno(bool aux);
	
private:
	bool m_turno;
	int carta_selected = -1;
	int cartas_en_mano = 3;
	Mazo *m_mazo;
	vector<Carta>cartas;
	vector<Carta>en_mesa;
};

#endif

