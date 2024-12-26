#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

using namespace std;

class Mazo {
public:
	Mazo();
	vector<Carta> Obtener3cartas();
private:
	vector<Carta>mazo;
};

#endif

