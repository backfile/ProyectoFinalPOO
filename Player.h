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
private:
	Carta carta1;
	Carta carta2;
	Carta carta3;
	vector<Carta>cartas;
};

#endif

