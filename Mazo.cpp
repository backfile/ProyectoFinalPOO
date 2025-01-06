#include "Mazo.h"
#include <iostream>
using namespace std;



Mazo::Mazo(): m_mazo{TODAS} {  
	
}

vector<Carta>Mazo::Obtener3cartas(){
	int carta1 = -1;
	int carta2 = -1;
	int carta3 = -1;
	
	while(carta1 == carta2 or carta1 == carta3 or carta2 == carta3){
		carta1 = rand()%m_mazo.size();  
		carta2 = rand()%m_mazo.size(); 	
		carta3 = rand()%m_mazo.size();	
	}
	
	vector<Carta> cartas3{m_mazo[carta1], m_mazo[carta2], m_mazo[carta3]};
	m_mazo.erase(m_mazo.begin() + carta1);
	m_mazo.erase(m_mazo.begin() + carta2);
	m_mazo.erase(m_mazo.begin() + carta3);
	return cartas3;
}

void Mazo::reiniciar_mazo(){
	m_mazo = m_mazo_respaldo;
}

