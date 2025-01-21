#include "Round.h"
#include <iostream>

Round::Round(bool turn_player1) : player1(turn_player1, &mazo, &truco, &envido), player2(!turn_player1, &mazo, &truco, &envido, &player1), truco(turn_player1), envido(turn_player1){
  calcularPuntosEnvidoP1();
  calcularPuntosEnvidoP2();
  font.loadFromFile("rara.ttf");
  text.setStyle(sf::Text::Bold);
  text.setFillColor(sf::Color::Black);
  text.setFont(font);
  text.setPosition(200, 300);
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



void Round::calcularPuntosEnvidoP1(){
	
	//Player 1 puntos
	
	vector<Carta>p1 = player1.obtener_cartas();
	std::map<int, int> frecuencia;
	int aux = 0;
	bool auxbool = true;
	
	for(auto carta : p1) {
		frecuencia[carta.verTipo()]++;
	}
	
	std::cout << frecuencia.size()<<endl;
	
	if(frecuencia.size() == 3){
		for(auto carta : p1){
			if(carta.verNumero() > aux and carta.verNumero() != -1){
				aux = carta.verNumero();
			}
		}
		puntos_envido_player1 = aux;
	}
	
	int valores[2];
	if(frecuencia.size() == 2){
		int tipo;
		for(auto par : frecuencia){
			if(par.second > 1){
				tipo = par.first;
			}
		}
		
		int aux2 = 0;
		for(auto carta : p1){
			if(carta.verTipo() == tipo){
				valores[aux2] = carta.verNumero();
				aux2++;
			}
		}
		
		
		if(valores[0] == -1 and valores[1] == -1){
			puntos_envido_player1 = 20;
			auxbool = false;
		}
		
		if(valores[0] != -1 and valores[1] != -1 ){
			puntos_envido_player1 = 20 + valores[0] + valores [1];
		}
		
		if((valores[0] == -1 or valores[1] == -1) and auxbool == true){
			puntos_envido_player1 = valores[0] + valores [1] + 21;
		}
		
	}
	
	if(frecuencia.size() == 1){
		int mayor = -2;
		int segundo = -2;
		for(auto carta : p1){
			if(carta.verNumero() > aux){
				segundo = aux;
				aux = carta.verNumero();				
			}else{
				if(carta.verNumero() > segundo){
					segundo = carta.verNumero(); 
				}
			}
		}
		
		valores[0] = aux;
		valores[1] = segundo;
		
		auxbool = true;
		if(valores[0] == -1 and valores[1] == -1){
			puntos_envido_player1 = 20;
			auxbool = false;
		}
		
		if(valores[0] != -1 and valores[1] != -1 ){
			puntos_envido_player1 = 20 + valores[0] + valores [1];
		}
		
		if(valores[0] == -1 or valores[1] == -1 and auxbool){
			puntos_envido_player1 = valores[0] + valores [1] + 10;
		}
	}
	
	std::cout << puntos_envido_player1 << " <-- Puntos player 1" <<endl;;
}

void Round::calcularPuntosEnvidoP2(){
	
	//Player 2 puntos
	
	vector<Carta>p2 = player2.obtener_cartas();
	std::map<int, int> frecuencia;
	int aux = 0;
	bool auxbool = true;
	
	for(auto carta : p2) {
		frecuencia[carta.verTipo()]++;
	}

	
	if(frecuencia.size() == 3){
		for(auto carta : p2){
			if(carta.verNumero() > aux and carta.verNumero() != -1){
				aux = carta.verNumero();
			}
		}
		puntos_envido_player2 = aux;
	}
	
	int valores[2];
	if(frecuencia.size() == 2){
		int tipo;
		for(auto par : frecuencia){
			if(par.second > 1){
				tipo = par.first;
			}
		}
		
		
		int aux2 = 0;
		for(auto carta : p2){
			if(carta.verTipo() == tipo){
				valores[aux2] = carta.verNumero();
				aux2++;
			}
		}
		
		
		if(valores[0] == -1 and valores[1] == -1){
			puntos_envido_player2 = 20;
			auxbool = false;
		}
		
		if(valores[0] != -1 and valores[1] != -1 ){
			puntos_envido_player2 = 20 + valores[0] + valores [1];
		}
		
		if((valores[0] == -1 or valores[1] == -1) and auxbool == true){
			puntos_envido_player2 = valores[0] + valores [1] + 21;
		}
		
	}
	
	if(frecuencia.size() == 1){
		int mayor = -2;
		int segundo = -2;
		for(auto carta : p2){
			if(carta.verNumero() > aux){
				segundo = aux;
				aux = carta.verNumero();				
			}else{
				if(carta.verNumero() > segundo){
					segundo = carta.verNumero(); 
				}
			}
		}
		
		valores[0] = aux;
		valores[1] = segundo;
		
		auxbool = true;
		if(valores[0] == -1 and valores[1] == -1){
			puntos_envido_player2 = 20;
			auxbool = false;
		}
		
		if(valores[0] != -1 and valores[1] != -1 ){
			puntos_envido_player2 = 20 + valores[0] + valores [1];
		}
		
		if(valores[0] == -1 or valores[1] == -1 and auxbool){
			puntos_envido_player2 = valores[0] + valores [1] + 10;
		}
	}
	
	std::cout << puntos_envido_player2 << " <-- Puntos player 2";
	
}


void Round::verificar_estado_envido(){
	if(envido.ver_status() == 3 and aux_envido_stats > 0){
		aux_envido_stats--;
		if(puntos_envido_player1 > puntos_envido_player2){
			text.setString("Gana el jugador 1 con: " + to_string(puntos_envido_player1) + " sobre: " + to_string(puntos_envido_player2));
		}else{
			text.setString("Gana el jugador 2 con: " + to_string(puntos_envido_player2) + " sobre: " + to_string(puntos_envido_player1));
		}
	}else{
		text.setString(" ");
	}
}

void Round::verificar_estado_truco(){
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
	
	
	if(player1tiradas.size() == 2 and player2tiradas.size() == 2 and player1tiradas[0].verPoder() == player2tiradas[0].verPoder()){
		
		if(player1tiradas[1].verPoder() < player2tiradas[1].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = true;
				return;
		}else{
			if(player2tiradas[1].verPoder() < player1tiradas[1].verPoder()){
				puntos_ganador = truco.obtenerValor();
				status = false;
				player1ganador = false;
				return;
			}
		}
		
		return;
	}
	
	if(player1tiradas.size() == 3 and player2tiradas.size() == 3 and player1tiradas[0].verPoder() == player2tiradas[0].verPoder() and player1tiradas[1].verPoder() == player2tiradas[1].verPoder()){
		
		if(player1tiradas[2].verPoder() < player2tiradas[2].verPoder()){
			puntos_ganador = truco.obtenerValor();
			status = false;
			player1ganador = true;
			return;
		}else if(player2tiradas[2].verPoder() < player1tiradas[2].verPoder()){
			puntos_ganador = truco.obtenerValor();
			status = false;
			player1ganador = false;
			return;
		}else{
			status = false;
		}
	}
	
}
	
	


void Round::actualizar(){
	
	
	// Analizar truco
	verificar_estado_truco();
	verificar_estado_envido();
	
	
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
	w.draw(text);

}

