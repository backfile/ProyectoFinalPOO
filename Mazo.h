#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"
#include "ValoresCartas.h"

using namespace std;

class Mazo {
public:
	Mazo();
	vector<Carta> Obtener3cartas();
private:
	vector<Carta>m_mazo;
	vector<Carta>m_mazo_respaldo;
	void reiniciar_mazo();
};

#endif

