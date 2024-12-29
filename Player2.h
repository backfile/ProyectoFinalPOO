#ifndef PLAYER2_H
#define PLAYER2_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Carta.h"
#include "Player.h"


using namespace std;

class Player2 {
public:
	Player2(bool turno, Mazo *mazo, Truco *truco, Player *rival);
	void dibujar(RenderWindow &m);
	void actualizar();
	void seleccionarCarta();
	bool obtenerTurno();
	void iniciar();
	int verCartasEnMano();
	void cambiarTurno(bool aux);
	void setRival(Player *aux);
	vector<Carta> obtener_en_mesa();
	
private:
	
	bool m_turno;
	int carta_selected = -1;
	int cartas_en_mano = 3;
	Player* m_rival;
	
	//Se comparten	
	Mazo *m_mazo;
	Truco *m_truco;
	
	vector<Carta>cartas;
	vector<Carta>en_mesa;
	

};

#endif

