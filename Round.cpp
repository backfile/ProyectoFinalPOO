#include "Round.h"

Round::Round(bool turn_player1) : player1(turn_player1, &mazo, &truco, &envido), player2(!turn_player1, &mazo, &truco, &envido, &player1), truco(turn_player1), envido(turn_player1){
	
}


int Round::getStatusTruco(){
	return truco.obtenerStatus();
}

void Round::actualizar(){
	
	
	// Analizar truco
	if(truco.obtenerStatus() == 2){
		if(truco.obtenerGenerated_by() == 1){
			player1puntos = truco.obtenerCastigo();
			status = false;
		}else{
			player2puntos = truco.obtenerCastigo();
			status = false;
		}
	}
	
	
	if(truco.obtenerStatus() == 3){
		puntos_ganador = truco.obtenerValor();
	}

	if(player1.verCartasEnMano() == 0 and player2.verCartasEnMano() == 0){
		status = false;
	}
	
	
	if(player1.obtenerTurno()){
		player1.actualizar();
	}else{
		player2.actualizar();
	}
	
	truco.actualizar();
	envido.actualizar();
}

bool Round::getStatus(){
	return status;
}

void Round::dibujar(RenderWindow &w){
	player1.dibujar(w);
	player2.dibujar(w);
	truco.dibujar(w);
	envido.dibujar(w);
}

