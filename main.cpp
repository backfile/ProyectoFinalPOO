#include <SFML/Graphics.hpp>
#include "Carta.h"
#include "Mazo.h"
#include "Match.h"

#include <iostream>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(800,600),"Truco");
	w.setFramerateLimit(60);
	
	//Fondo
    Match match;
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}

		
		match.actualizar();
		match.dibujar(w);
		w.display();
		
	}
	return 0;
}

