#include "Juego.h"
#include "Match.h"
#include "Menu.h"

Juego::Juego(){
	w.create(sf::VideoMode(800, 600), "Truco");
	w.setFramerateLimit(60);
	window = &w;
	actual = new Menu(window);
}

void Juego::jugar(){
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		actual->actualizar(*this);
		actual->dibujar(w);
		w.display();
		
		if(siguiente){
			delete actual;
			actual = siguiente;
			siguiente = nullptr;
		}
	}
}

void Juego::actualizarEscena(Escena *nuevaEscena){
	siguiente = nuevaEscena;
}

Juego::~Juego(){
	delete actual;
}
