#include "Juego.h"
#include "Match.h"
#include "Menu.h"

#include <fstream>
using namespace std;

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


vector<Partida> Juego::obtenerHistorial(){
	Partida partida;
	vector<Partida>aux;
	ifstream arch("./utils/historial.dat", ios::binary|ios::ate);
	if (not arch.is_open()) throw runtime_error("No se pudo abrir el archivo");
	int tam_bytes = arch.tellg();
	int cant_partidas = tam_bytes / sizeof(partida);
	arch.seekg(0);
	for(int i=0;i<cant_partidas;i++) { 
		arch.read(reinterpret_cast<char*>(&partida), sizeof(partida));
		aux.push_back(partida);
	}
	
	return aux;
}

void Juego::agregarPartida(Partida partida){
	vector<Partida>aux = obtenerHistorial();
	aux.push_back(partida);
	if(aux.size() > 5){
		aux.erase(aux.begin());
	}
	ofstream arch("./utils/historial.dat", ios::binary);
	if (not arch.is_open()) throw runtime_error("No se pudo abrir el archivo");

	for(int i=0;i<aux.size();i++) { 
		arch.write(reinterpret_cast<char*>(&aux[i]), sizeof(partida));
	}
}

Juego::~Juego(){
	delete actual;
}
