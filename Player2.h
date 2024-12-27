#ifndef PLAYER2_H
#define PLAYER2_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Carta.h"
#include "Player.h"


using namespace std;

class Player2 {
public:
	Player2(bool turno, Mazo *mazo);
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
	bool obtenerTurno();
	void obtener3cartas();
	int verCartasEnMano();
	void cambiarTurno(bool aux);
	void setRival(Player *aux);
	
private:
	
	bool m_turno;
	Player* rival;
	Mazo* m_mazo;
	int carta_selected = -1;
	int cartas_en_mano = 3;
	vector<Carta>cartas;
	vector<Carta>en_mesa;
};

#endif

