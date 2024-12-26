#include <SFML/Graphics.hpp>
#include "Carta.h"
#include "Mazo.h"
#include "Game.h"

using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(800,600),"Ejemplo de SFML");
	w.setFramerateLimit(60);
	
	//Fondo
    Game game;
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		
		game.Dibujar(w);
		w.display();
		
	}
	return 0;
}

