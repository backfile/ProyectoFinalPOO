#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Carta.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
using namespace std;

class Player {
public:
	Player();
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
private:
	Carta carta1;
	Carta carta2;
	Carta carta3;
	int carta_selected;
	int cartas_en_mano = 3;
	vector<Carta>cartas;
	vector<Carta>cartas_tiradas;
};

#endif

