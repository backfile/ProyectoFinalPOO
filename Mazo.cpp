#include "Mazo.h"
#include <iostream>
using namespace std;



Mazo::Mazo(): m_mazo{TODAS} {  
	
}

vector<Carta> Mazo::Obtener3cartas(){
	
	int cont = 0;
	vector<Carta> cartas3;
	while(cont < 3){
		cont ++;
		int carta = rand()%m_mazo.size();  
		cartas3.push_back(m_mazo[carta]);
		m_mazo.erase(m_mazo.begin() + carta);
	}
	
	return cartas3;
	
}


