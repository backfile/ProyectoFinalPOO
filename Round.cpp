#include "Round.h"

Round::Round(bool turn_player1) : player1(turn_player1, &mazo, &truco, &envido), player2(!turn_player1, &mazo, &truco, &envido, &player1), truco(turn_player1), envido(turn_player1){
	
}


int Round::getStatusTruco(){
	return truco.obtenerStatus();
}

bool Round::getPlayer1ganador(){
	return player1ganador;
}

int Round::getPuntosGanador(){
	return puntos_ganador;
}


void Round::verificar_estado(){
	vector<Carta>player1tiradas = player1.obtener_en_mesa();
	vector<Carta>player2tiradas = player2.obtener_en_mesa();
	
	
	if(truco.obtenerStatus() == 2){
		if(truco.obtenerGenerated_by() == 1){
			player1puntos = truco.obtenerCastigo();
			status = false;
			return;
		}else{
			player2puntos = truco.obtenerCastigo();
			status = false;
			return;
		}
	}
	
	
	
	if(player1tiradas.size() == 2 and player2tiradas.size() == 2 and player1tiradas[0].verPoder() != player2tiradas[0].verPoder()){
		
		if(player1tiradas[0].verPoder() < player2tiradas[0].verPoder()){
			if(player1tiradas[1].verPoder() <= player2tiradas[1].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = true;
				return;
			}
		}else{
			if(player2tiradas[1].verPoder() <= player1tiradas[1].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = false;
				return;
			}
		}
		
		return;
	}
	
	if(player1tiradas.size() == 3 and player2tiradas.size() == 3 and player1tiradas[0].verPoder() != player2tiradas[0].verPoder()){
		
		if(player1tiradas[0].verPoder() < player2tiradas[0].verPoder()){
			if(player1tiradas[2].verPoder() <= player2tiradas[2].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = true;
				return;
			}else{
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = false;
				return;
			}
		}else{
			if(player2tiradas[2].verPoder() <= player1tiradas[2].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = false;
				return;
			}else{
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = true;
				return;
			}
		}
		
		return;
	}
	
}

void Round::actualizar(){
	
	
	// Analizar truco
	verificar_estado();
	
	
	
	if(player1.obtenerTurno()){
		player1.actualizar();
	}else{
		player2.actualizar();
	}
	
	truco.actualizar();
	envido.actualizar();
}

int Round::getPuntosPlayer1(){
	return player1puntos;
}

int Round::getPuntosPlayer2(){
	return player2puntos;
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

