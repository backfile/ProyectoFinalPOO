#include "Round.h"
#include <iostream>

Round::Round(bool turn_player1, Window *w, int puntos_a_jugar, int puntosplayer1) : player1(turn_player1, &mazo, &truco, &envido, w), player2(!turn_player1, &mazo, &truco, &envido, &player1, w, puntos_a_jugar, puntosplayer1), truco(turn_player1, &envido), envido(turn_player1){
  calcularPuntosEnvidoP1();
  calcularPuntosEnvidoP2();
  mano_player1 = turn_player1;
  
  
  font.loadFromFile("./utils/rara.ttf");
  text_player1.setStyle(sf::Text::Bold);
  text_player1.setFont(font);
  text_player1.setPosition(307, 290);
  
  text_player2.setStyle(sf::Text::Bold);
  text_player2.setFont(font);
  text_player2.setPosition(307, 347);
  
  
  
  t_envido_ganaste.loadFromFile("./images/envido_ganaste.png");
  s_envido_ganaste.setTexture(t_envido_ganaste);
  
  t_envido_perdiste.loadFromFile("./images/envido_perdiste.png");
  s_envido_perdiste.setTexture(t_envido_perdiste);
  
  t_botones.loadFromFile("./images/botones/todos.png");
  s_botones.setTexture(t_botones);
  s_botones.setPosition(Vector2f(100, 530));
  

  
  // Cantos en pantalla
  //player 1
  t_truco_pantalla.loadFromFile("./images/cantos/truco.png");
  s_truco_pantalla.setTexture(t_truco_pantalla);
  
  t_retruco_pantalla.loadFromFile("./images/cantos/retruco.png");
  s_retruco_pantalla.setTexture(t_retruco_pantalla);

  t_valecuatro_pantalla.loadFromFile("./images/cantos/valecuatro.png");
  s_valecuatro_pantalla.setTexture(t_valecuatro_pantalla);
  
  t_quiero_pantalla.loadFromFile("./images/cantos/quiero.png");
  s_quiero_pantalla.setTexture(t_quiero_pantalla);
  
  t_noquiero_pantalla.loadFromFile("./images/cantos/noquiero.png");
  s_noquiero_pantalla.setTexture(t_noquiero_pantalla);
  
  t_envido_pantalla.loadFromFile("./images/cantos/envido.png");
  s_envido_pantalla.setTexture(t_envido_pantalla);
  
  t_envidoenvido_pantalla.loadFromFile("./images/cantos/envidoenvido.png");
  s_envidoenvido_pantalla.setTexture(t_envidoenvido_pantalla);
  
  t_realenvido_pantalla.loadFromFile("./images/cantos/realenvido.png");
  s_realenvido_pantalla.setTexture(t_realenvido_pantalla);
  
  t_faltaenvido_pantalla.loadFromFile("./images/cantos/faltaenvido.png");
  s_faltaenvido_pantalla.setTexture(t_faltaenvido_pantalla);
  
  
  //player 2
  
  t_truco2_pantalla.loadFromFile("./images/cantos/truco2.png");
  s_truco2_pantalla.setTexture(t_truco2_pantalla);
  
  t_retruco2_pantalla.loadFromFile("./images/cantos/retruco2.png");
  s_retruco2_pantalla.setTexture(t_retruco2_pantalla);
  
  t_valecuatro2_pantalla.loadFromFile("./images/cantos/valecuatro2.png");
  s_valecuatro2_pantalla.setTexture(t_valecuatro2_pantalla);
  
  t_quiero2_pantalla.loadFromFile("./images/cantos/quiero2.png");
  s_quiero2_pantalla.setTexture(t_quiero2_pantalla);
  
  t_noquiero2_pantalla.loadFromFile("./images/cantos/noquiero2.png");
  s_noquiero2_pantalla.setTexture(t_noquiero2_pantalla);
  
  t_envido2_pantalla.loadFromFile("./images/cantos/envido2.png");
  s_envido2_pantalla.setTexture(t_envido2_pantalla);
  
  t_envidoenvido2_pantalla.loadFromFile("./images/cantos/envidoenvido2.png");
  s_envidoenvido2_pantalla.setTexture(t_envidoenvido2_pantalla);
  
  t_realenvido2_pantalla.loadFromFile("./images/cantos/realenvido2.png");
  s_realenvido2_pantalla.setTexture(t_realenvido2_pantalla);
  
  t_faltaenvido2_pantalla.loadFromFile("./images/cantos/faltaenvido2.png");
  s_faltaenvido2_pantalla.setTexture(t_faltaenvido2_pantalla);

  
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



int Round::calcularPuntosEnvidoP1(){
	
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

int Round::calcularPuntosEnvidoP2(){
	
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
	
	return puntos_envido_player2;
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
	if(envido.ver_status() == Envido::ACEPTADO and aux_envido_stats > 0){
		aux_envido_stats--;
		if(puntos_envido_player1 > puntos_envido_player2){
			envido_gano_player1 = true;
			envido.cambiarGanador(true);
			envido_listo_para_sumar = true;
			
		}else if(puntos_envido_player1 < puntos_envido_player2){
			//Depende quien lo canto mostrar una cosa u otra
			envido_gano_player1 = false;
			envido.cambiarGanador(false);
			envido_listo_para_sumar = true;
			
		}else{
			if(mano_player1){
				envido_gano_player1 = true;
				envido.cambiarGanador(true);
				envido_listo_para_sumar = true;
				
			}else{
				envido_gano_player1 = false;
				envido.cambiarGanador(false);
				envido_listo_para_sumar = false;
				
			}
		}
		text_player1.setString("Tus puntos: " + to_string(puntos_envido_player1));
		text_player2.setString("Sus puntos: " + to_string(puntos_envido_player2));
	}else{
		text_player1.setString(" ");
		text_player2.setString(" ");
	}
	
	//Repartir puntos
	if(envido.ver_status() == Envido::ACEPTADO){
		if(envido.obtenerGanador() == true){
			puntos_ganados_envido_player1 = envido.obtenerValor();
			return;
		}
		if(envido.obtenerGanador() == false){
			puntos_ganados_envido_player2 = envido.obtenerValor();
			return;
			
		}
	}
	
	if(envido.ver_status() == Envido::RECHAZADO){
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
	
void Round::forzar_turno(){
	if(envido.ver_status() != Envido::EN_ESPERA and truco.obtenerStatus() != Envido::EN_ESPERA){
		if((player1.verCartasEnMano() == 2 and player2.verCartasEnMano() == 2)){
			vector<Carta>player1cart = player1.obtener_en_mesa();
			vector<Carta>player2cart = player2.obtener_en_mesa();
			
			//Forzar ultimo en tirar
			if(player1cart[0].verPoder() < player2cart[0].verPoder()){
				player2.cederTurno();
				truco.cambiarUltimoEnTirar(2);
				return;
			}
			if(player1cart[0].verPoder() > player2cart[0].verPoder()){
				player1.cederTurno();
				truco.cambiarUltimoEnTirar(1);
				return;
			}
			if(player1cart[0].verPoder() == player2cart[0].verPoder()){
				if(mano_player1){
					player2.cederTurno();
					truco.cambiarUltimoEnTirar(2);
					return;
				}else{
					player1.cederTurno();
					truco.cambiarUltimoEnTirar(1);
					return;
				}
			}
			
		}
		
		if((player1.verCartasEnMano() == 1 and player2.verCartasEnMano() == 1)){
			vector<Carta>player1cart = player1.obtener_en_mesa();
			vector<Carta>player2cart = player2.obtener_en_mesa();
			
			if(player1cart[1].verPoder() < player2cart[1].verPoder()){
				player2.cederTurno();
				truco.cambiarUltimoEnTirar(2);
				return;
			}
			if(player1cart[1].verPoder() > player2cart[1].verPoder()){
				player1.cederTurno();
				truco.cambiarUltimoEnTirar(1);
				return;
			}
			if(player1cart[1].verPoder() == player2cart[1].verPoder()){
				if(mano_player1){
					player2.cederTurno();
					truco.cambiarUltimoEnTirar(2);
					return;
				}else{
					player1.cederTurno();
					truco.cambiarUltimoEnTirar(1);
					return;
				}
			}
		}
	}
}	


void Round::actualizar(){
	
	//Incrementar la variable auxiliar para mostrar cantos en pantalla
	contador_mostrar_canto_actual++;
	
	// Analizar truco Y envido para ver si hay que hacer alguna accion
	verificar_estado_truco();
	verificar_estado_envido();
	
	if(aux_envido_stats < 230 and aux_envido_stats > 0){return;} // Bloquea la ejecucion mientras se muestran los puntos del envido
	
	// Funcion de que no importa quien fue el ultimo en tirar, juegue el que gano la mano
	forzar_turno();
	
	//Tome el control el que tenga el turno
	if(status){
		if(player1.obtenerTurno()){
			player1.actualizar(*this);
		}else{
			player2.actualizar(*this);
		}
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

bool Round::actualizarCantoEnPantalla(int num){
	contador_mostrar_canto_actual = 0;
	canto_actual_en_pantalla = num;
}

void Round::dibujar(RenderWindow &w){
	player2.dibujar(w);
	player1.dibujar(w);
	
	//Cartel de ganaste o perdiste
	if(envido.ver_status() == 3 and aux_envido_stats > 0){
		if(envido_gano_player1){
			w.draw(s_envido_ganaste);
		}else{
			w.draw(s_envido_perdiste);
		}
		w.draw(text_player1);
		w.draw(text_player2);
	}
	
	if(status == true){
		w.draw(s_botones);
	}
	if(player1.obtenerTurno() == true and status == true){
		truco.dibujar(w, status);
		envido.dibujar(w, status);
	}
	
	
	
	if(contador_mostrar_canto_actual < 140 and status == true){		
		if(canto_actual_en_pantalla == P1_TRUCO){
			w.draw(s_truco_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_RETRUCO){
			w.draw(s_retruco_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_VALECUATRO){
			w.draw(s_valecuatro_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_QUIERO){
			w.draw(s_quiero_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_ENVIDO){
			w.draw(s_envido_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_ENVIDOENVIDO){
			w.draw(s_envidoenvido_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_REALENVIDO){
			w.draw(s_realenvido_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_FALTAENVIDO){
			w.draw(s_faltaenvido_pantalla);
			return;
		}
		
		
		
		if(canto_actual_en_pantalla == P2_TRUCO){
			w.draw(s_truco2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_RETRUCO){
			w.draw(s_retruco2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_VALECUATRO){
			w.draw(s_valecuatro2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_QUIERO){
			w.draw(s_quiero2_pantalla);
			return;
		}
		
		if(canto_actual_en_pantalla == P2_ENVIDO){
			w.draw(s_envido2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_ENVIDOENVIDO){
			w.draw(s_envidoenvido2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_REALENVIDO){
			w.draw(s_realenvido2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P2_FALTAENVIDO){
			w.draw(s_faltaenvido2_pantalla);
			return;
		}
		
	}
	if(contador_mostrar_canto_actual < 140){
		if(canto_actual_en_pantalla == P2_NOQUIERO){
			w.draw(s_noquiero2_pantalla);
			return;
		}
		if(canto_actual_en_pantalla == P1_NOQUIERO){
			w.draw(s_noquiero_pantalla);
			return;
		}
	}
	
}

