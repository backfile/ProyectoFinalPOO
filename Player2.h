#ifndef PLAYER2_H
#define PLAYER2_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Carta.h"
#include "Player.h"


using namespace std;

class Player2 {
public:
	Player2(bool turno);
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
	bool obtenerTurno();
	void cambiarTurno(bool aux);
	void setRival(Player *aux);
private:
	Carta carta1;
	Carta carta2;
	Carta carta3;
	bool m_turno;
	Player* rival;
	int carta_selected;
	int cartas_en_mano = 3;
	vector<Carta>cartas;
	vector<Carta>en_mesa;
};

#endif

