#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>




using namespace std;

class Player {
public:
	Player(bool turno);
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
	bool obtenerTurno();
	void cambiarTurno(bool aux);
	
private:
	Carta carta1;
	Carta carta2;
	Carta carta3;
	bool m_turno;
	int carta_selected;
	int cartas_en_mano = 3;
	vector<Carta>cartas;
	vector<Carta>en_mesa;
};

#endif

