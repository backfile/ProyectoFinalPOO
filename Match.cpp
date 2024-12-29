#include "Match.h"

Match::Match() {
	round = new Round(jugar_primero);
	t_background.loadFromFile("./images/fondo.png");
	s_background.setTexture(t_background);
}


void Match::actualizar(){
	if(!round->getStatus())
	{
		// Obtener datos de la ronda antes de eliminarla
		
		if(round->getStatusTruco() == 3){
			
		}
	
		jugar_primero = !jugar_primero;
		
		/*pair<int, int>puntos round.obtenerPuntos();*/
		
		delete round;
		round = new Round(jugar_primero);
	}
	
	round->actualizar();
};

void Match::dibujar(RenderWindow &w){
	w.clear(Color(255,255,255,255));
	w.draw(s_background);
	round->dibujar(w);
}
