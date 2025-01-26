#include "Round.h"
#include <iostream>

Round::Round(bool turn_player1, Window *w) : player1(turn_player1, &mazo, &truco, &envido, w), player2(!turn_player1, &mazo, &truco, &envido, &player1, w), truco(turn_player1), envido(turn_player1){
  calcularPuntosEnvidoP1();
  calcularPuntosEnvidoP2();
  font.loadFromFile("rara.ttf");
  text.setStyle(sf::Text::Bold);
  text.setFillColor(sf::Color::Black);
  text.setFont(font);
  text.setPosition(200, 300);
  mano_player1 = turn_player1;
  t_botones.loadFromFile("./images/botones/todos.png");
  s_botones.setTexture(t_botones);
  
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
	
	
}

int Round::obtenerPuntosEnvidoPlayer1(){
	return puntos_ganados_envido_player1;
}

int Round::obtenerPuntosEnvidoPlayer2(){
	return puntos_ganados_envido_player2;
}

bool Round::obtenerGanadorEnvido(){
	return envido.obtenerGanador();
}

bool Round::obtenerFinalizadoEnvido(){
	return envido.ver_finalizado();
}

void Round::verificar_estado_envido(){
	if(envido.ver_status() == 3 and aux_envido_stats > 0){
		aux_envido_stats--;
		if(puntos_envido_player1 > puntos_envido_player2){
			text.setString("Gana el jugador 1 con: " + to_string(puntos_envido_player1) + " sobre: " + to_string(puntos_envido_player2));
			envido.cambiarGanador(true);
			envido_listo_para_sumar = true;
		}else if(puntos_envido_player1 < puntos_envido_player2){
			text.setString("Gana el jugador 2 con: " + to_string(puntos_envido_player2) + " sobre: " + to_string(puntos_envido_player1));
			envido.cambiarGanador(false);
			envido_listo_para_sumar = true;
		}else{
			if(mano_player1){
				text.setString("Gana el jugador 1 con: " + to_string(puntos_envido_player1) + " sobre: " + to_string(puntos_envido_player2)+ " por ser mano");
				envido.cambiarGanador(true);
				envido_listo_para_sumar = true;
			}else{
				text.setString("Gana el jugador 2 con: " + to_string(puntos_envido_player2) + " sobre: " + to_string(puntos_envido_player1)+ " por ser mano");
				envido.cambiarGanador(false);
				envido_listo_para_sumar = false;
			}
		}
	}else{
		text.setString(" ");
	}
	//Repartir puntos
	
	
	if(envido.ver_status() == 3){
		if(envido.obtenerGanador() == true){
			puntos_ganados_envido_player1 = envido.obtenerValor();
			return;
		}
		if(envido.obtenerGanador() == false){
			puntos_ganados_envido_player2 = envido.obtenerValor();
			return;
			
		}
	}
	
	if(envido.ver_status() == 2){
		if(envido.obtenerRechazado_by()==1){
			puntos_ganados_envido_player2 = envido.obtenerPrev();
			envido_listo_para_sumar = true;
			envido.cambiarGanador(false);
		}else{
			puntos_ganados_envido_player1 = envido.obtenerPrev();
			envido_listo_para_sumar = true;
			envido.cambiarGanador(true);
		}
	}
	
	
}

bool Round::obtener_envido_listo_para_sumar(){
	return envido_listo_para_sumar;
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
	
	if(envido.ver_status() != 1 and truco.obtenerStatus() != 1){
		if((player1.verCartasEnMano() == 2 and player2.verCartasEnMano() == 2)){
			vector<Carta>player1cart = player1.obtener_en_mesa();
			vector<Carta>player2cart = player2.obtener_en_mesa();
			
			if(player1cart[0].verPoder() < player2cart[0].verPoder()){
				player2.cederTurno();
				truco.cambiarUltimoEnTirar(2);
				turnoaux = false;
			}
			if(player1cart[0].verPoder() > player2cart[0].verPoder() and turnoaux == true){
				player1.cederTurno();
				truco.cambiarUltimoEnTirar(1);
				turnoaux = false;
			}
			
		}
		
		if((player1.verCartasEnMano() == 1 and player2.verCartasEnMano() == 1)){
			vector<Carta>player1cart = player1.obtener_en_mesa();
			vector<Carta>player2cart = player2.obtener_en_mesa();
			
			if(player1cart[1].verPoder() < player2cart[1].verPoder()){
				player2.cederTurno();
				truco.cambiarUltimoEnTirar(2);
				turno2aux = false;
			}
			if(player1cart[1].verPoder() > player2cart[1].verPoder() and turno2aux == true){
				player1.cederTurno();
				truco.cambiarUltimoEnTirar(1);
				turno2aux = false;
			}
			
		}
	}
	if(player1.obtenerTurno()){
		player1.actualizar();
	}else{
		player2.actualizar();
	}
	if(player1.obtenerTurno()){
		s_botones.setPosition(Vector2f(100, 530));
	}else{
		s_botones.setPosition(Vector2f(100, 0));
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
	w.draw(s_botones);
	truco.dibujar(w);
	envido.dibujar(w);
	w.draw(text);
	

}

