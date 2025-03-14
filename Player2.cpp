#include "Player2.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "ValoresCartas.h"
#include "Player.h"
#include "Round.h"
#include <SFML/System/Sleep.hpp>
using namespace std;

Player2::Player2(bool turno, Mazo *mazo, Truco *truco, Envido *envido, Player* rival, Window *w, int m_puntos_a_jugar, int puntosplayer1) : m_player1puntos(puntosplayer1), m_rival(rival), m_turno(turno), m_mazo(mazo), m_truco(truco), m_envido(envido), m_window(w), m_puntos_a_jugar(m_puntos_a_jugar){
	iniciar();
	
	//Definir tamaño de los botones
	float anchoBoton = 74.6;
	float alturaBoton = 35;
	
	//Definir posicion base
	float x_base = 100; 
	float y_base = 0;
	
	//Truco boton
	TrucoBoton.setSize(sf::Vector2f(74.6, 35));
	TrucoBoton.setPosition(x_base, y_base);
	TrucoBoton.setFillColor(sf::Color::Red);
	
	//ReTruco boton
	ReTrucoBoton.setSize(sf::Vector2f(74.6, 35));
	ReTrucoBoton.setPosition(x_base + anchoBoton, y_base);
	ReTrucoBoton.setFillColor(sf::Color::Red);
	
	//Vale Cuatro boton
	ValeCuatroBoton.setSize(sf::Vector2f(74.6, 35));
	ValeCuatroBoton.setPosition(x_base, y_base + alturaBoton);
	ValeCuatroBoton.setFillColor(sf::Color::Red);
	
	//Quiero boton
	QuieroBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroBoton.setPosition(x_base + anchoBoton, y_base + alturaBoton);
	QuieroBoton.setFillColor(sf::Color::Red);
	
	// NoQuiero boton
	NoQuieroBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroBoton.setPosition(x_base + anchoBoton * 2, y_base + alturaBoton);
	NoQuieroBoton.setFillColor(sf::Color::Red);
	
	//Envido boton
	EnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoBoton.setPosition(x_base + 376.2, y_base);
	EnvidoBoton.setFillColor(sf::Color::Red);
	
	//RealEnvido boton
	RealEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	RealEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base);
	RealEnvidoBoton.setFillColor(sf::Color::Red);
	
	//EnvidoEnvido boton
	EnvidoEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	EnvidoEnvidoBoton.setPosition(x_base + 376.2, y_base + alturaBoton);
	EnvidoEnvidoBoton.setFillColor(sf::Color::Red);
	
	//FaltaEnvido boton
	FaltaEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	FaltaEnvidoBoton.setPosition(x_base + 376.2 + anchoBoton, y_base + alturaBoton);
	FaltaEnvidoBoton.setFillColor(sf::Color::Red);
	
	//QuieroEnvidoBoton
	QuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	QuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base);
	QuieroEnvidoBoton.setFillColor(sf::Color::Red);
	
	//NoQuieroEnvidoBoton
	NoQuieroEnvidoBoton.setSize(sf::Vector2f(74.6, 35));
	NoQuieroEnvidoBoton.setPosition(x_base + anchoBoton*2 + 376.2, y_base + alturaBoton);
	NoQuieroEnvidoBoton.setFillColor(sf::Color::Red);
	
	//ZonaTirarCartas
	ZonaTirarCartas.setSize(sf::Vector2f(600, 270));
	ZonaTirarCartas.setPosition(100, 160);
	ZonaTirarCartas.setFillColor(sf::Color::Red);
}


vector<Carta> Player2::obtener_en_mesa(){
	return en_mesa;
}


vector<Carta> Player2::obtener_cartas(){
	return cartas;
};


void Player2::iniciar(){
	cartas = m_mazo->Obtener3cartas();
	cartas[0].actualizarTextura(Vector2f(205, 10), false);
	cartas[1].actualizarTextura(Vector2f(400, 10), false);
	cartas[2].actualizarTextura(Vector2f(595, 10), false);
}


void Player2::cederTurno(){
	m_rival->cambiarTurno(true);
	m_truco->modificar_turno_player(true);
	m_envido->modificar_turno_player(true);

};


int Player2::verCartasEnMano(){
	return cartas_en_mano;
}

bool Player2::obtenerTurno(){
	return m_turno;
}

void Player2::cambiarTurno(bool aux){
	m_turno = aux;
}

void Player2::setPuntosEnvido(int aux){
	puntos_envido = aux;
}

void Player2::jugar(){
	vector<Carta>aux = m_rival->obtener_en_mesa();
	

	//Si es parda tirar la mas alta
	if(!aux.empty() and !en_mesa.empty()){
		if(aux[0].verPoder() == en_mesa[0].verPoder()){
			int menor = 9999;
			int indice_aux;
			
			for(size_t i=0;i<cartas.size();i++) { 
				if(cartas[i].verPoder() < menor and cartas[i].obtenerEnMano() == true){
					menor = cartas[i].verPoder();
					indice_aux = i;
				}
			}
			m_rival->restarCartasEnManoPlayer2();
			cartas[indice_aux].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[indice_aux]);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player2();
			}
			m_truco->cambiarUltimoEnTirar(2);
			if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
			cederTurno();
			return;
		}
	}
	
	//Si el otro tiro una carta mas, tirar la mejor mas baja, o en caso de no tener mejor, hacerla parda y en el peor de los casos, tirar la mas baja
	if(!aux.empty() and cartas_en_mano > m_rival->verCartasEnMano()){
		int power_rival = aux[aux.size()-1].verPoder();
		int aux2 = 0;
		int min = 0;
		int indice = -1;
		int indice2;
		
		for(int i=0;i<cartas.size();i++){
			if(cartas[i].verPoder() < power_rival and cartas[i].obtenerEnMano() == true and cartas[i].verPoder() > aux2){
				indice = i;
				aux2 = cartas[i].verPoder();
			}else{
				//En caso de que sea parda
				if(indice == -1 and cartas[i].verPoder() == power_rival and cartas[i].obtenerEnMano() == true){
					indice = i;
				}
			}
		}
		
		//Encontrar la mas baja si no se encontró la menos mejor
		if(indice == -1){

			for(int i=0;i<cartas.size();i++) { 
				if(cartas[i].verPoder() > min and cartas[i].obtenerEnMano() == true){
					indice2 = i;
					min = cartas[i].verPoder();
				}
			}
			// tirar la mas baja
			m_rival->restarCartasEnManoPlayer2();
			cartas[indice2].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[indice2]);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player2();
			}
			m_truco->cambiarUltimoEnTirar(2);
			if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
			cederTurno();
		}else{
			// tirar la menos mejor
			m_rival->restarCartasEnManoPlayer2();
			cartas[indice].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[indice]);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player2();
			}
			m_truco->cambiarUltimoEnTirar(2);
			if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
			cederTurno();
		}
		return;
	}
	
	//Si tenes que jugar primero
	if(aux.empty()){
		//Encontrar las dos mayores y luego decidir cual jugar segun los valores
		int min1 = 9999;
		int min2 = 9999;
		int indice1 = -1;
		int indice2 = -1;
		
		for(size_t i=0;i<cartas.size();i++) { 
			if(cartas[i].verPoder() < min1 and cartas[i].obtenerEnMano() == true){
				min2 = min1;
				min1 = cartas[i].verPoder();
				indice2 = indice1;
				indice1 = i;
			}else{
				if(cartas[i].verPoder() < min2 and cartas[i].obtenerEnMano() == true){
					min2 = cartas[i].verPoder();
					indice2 = i;
				}
			}
		}
		if(min1 <= 4){
			m_rival->restarCartasEnManoPlayer2();
			cartas[indice2].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[indice2]);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player2();
			}
			m_truco->cambiarUltimoEnTirar(2);
			if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
			cederTurno();
		}else{
			m_rival->restarCartasEnManoPlayer2();
			cartas[indice1].tirar();
			cartas_en_mano --;
			en_mesa.push_back(cartas[indice1]);
			if(m_envido->ver_finalizado() == false){
				m_envido->modificar_tiro_carta_player2();
			}
			m_truco->cambiarUltimoEnTirar(2);
			if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
			cederTurno();
		}
		return;
	}
	
	//En caso de haber ganado la mano y toca jugar primero, tirar la mas baja
	int indice3 = 0;
	int min3 = 0;
	if(!aux.empty() and cartas_en_mano == m_rival->verCartasEnMano()){
		for(int i=0;i<cartas.size();i++) { 
			if(cartas[i].verPoder() > min3 and cartas[i].obtenerEnMano() == true){
				indice3 = i;
				min3 = cartas[i].verPoder();
			}
		}
		// tirar la mas baja
		m_rival->restarCartasEnManoPlayer2();
		cartas[indice3].tirar();
		cartas_en_mano --;
		en_mesa.push_back(cartas[indice3]);
		if(m_envido->ver_finalizado() == false){
			m_envido->modificar_tiro_carta_player2();
		}
		m_truco->cambiarUltimoEnTirar(2);
		if(cartas_en_mano == 2 and m_rival->verCartasEnMano() == 2 or cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){return;}
		cederTurno();
		return;
	}
	
}

void Player2::definirBotJuego(){
	int sum = 0;
	int cont_cartas_buenas = 0; // Identificar cuantas cartas >= que un 3 el bot tiene
	for(auto carta : cartas){
		sum  += carta.verPoder();
		if(carta.verPoder() <= 5){
			cont_cartas_buenas++;
		}
	}
	
	//Definir el estilo de juego para el "truco"
	if(sum > 26){
		botjuego.truco = 0;
	}
	if(sum >= 17 and sum <= 26){
		botjuego.truco = 1;
	}
	if(sum < 17){
		botjuego.truco = 2;
	}
	
	//Cambiar el modo de juego en caso de que este en modo 0 y tenga al menos una buena carta
	if(botjuego.truco == 0 and cont_cartas_buenas > 0){
		botjuego.truco = 1;
	}
	
	//Definir el estilo de juego para el "envido"
	
	if(puntos_envido < 25){
		botjuego.envido = 0;
	}
	if(puntos_envido >= 25 and puntos_envido <= 30){
		botjuego.envido = 1;
	}
	if(puntos_envido > 30){
		botjuego.envido = 2;
	}
}

bool Player2::Exepcion(){
	bool aux2 = false;
	vector<Carta>aux = m_rival->obtener_en_mesa();
	
	//Busco el poder de mi ultima cartas
	int aux_poder;
	for(auto carta : cartas){
		if(carta.obtenerEnMano() == true){
			aux_poder = carta.verPoder();
		}
	}
	
	//Jugar agresivo si mi ultima carta es mas alta que la de el, o la de el es muy baja (mentir para asustarlo)
	if(m_rival->verCartasEnMano() == 0 and cartas_en_mano == 1){
		if(aux[2].verPoder() >= 11){
			aux2 = true;
		}
		if(aux[2].verPoder() > aux_poder){
			aux2 = true;
		}
		if(aux[0].verPoder() > en_mesa[0].verPoder() and aux[2].verPoder() == aux_poder){
			aux2 = true;
		}
	}
	return aux2;
}

bool Player2::Exepcion2(){
	if(m_puntos_a_jugar - m_player1puntos == 1){
		return true;
	}
	return false;
}

void Player2::actualizar(Round &round){
	if(aux){
		puntos_envido = round.calcularPuntosEnvidoP2();
		definirBotJuego();
		aux = false;
	}
	
	//Juego de la maquina
	sf::sleep(sf::seconds(2));
	
	//Cantos y excepciones
	
	
	if(Exepcion2()){
		if(m_envido->ver_finalizado() == false){
			if(m_envido->ver_status() == Envido::EN_ESPERA){
				m_envido->aceptar();
				cederTurno();
				round.actualizarCantoEnPantalla(NADA);
				return;
			}
		}
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA and m_truco->obtenerGenerated_by() == 1){
			m_truco->aceptar();
			round.actualizarCantoEnPantalla(P2_QUIERO);
			return;
		}
		
	}
	
	
	//Envido en caso 0
	if(botjuego.envido == 0 and m_envido->ver_finalizado() == false){
		if(m_envido->ver_status() == Envido::EN_ESPERA){
			m_envido->rechazar(2);
			cederTurno();
			round.actualizarCantoEnPantalla(P2_NOQUIERO);
			return;
		}
	}
	
	//Envido en caso 1
	if(botjuego.envido == 1 and m_envido->ver_finalizado() == false){
		if(m_envido->ver_status() == Envido::EN_ESPERA){
			if(m_envido->ver_tipo_en_juego() != Envido::Envido){
				m_envido->rechazar(2);
				cederTurno();
				round.actualizarCantoEnPantalla(P2_NOQUIERO);
			}else{
				m_envido->aceptar();
				cederTurno();
				round.actualizarCantoEnPantalla(NADA);
			}
		}
		if(m_envido->ver_status() == Envido::NO_INICIADO){
			m_envido->cantar_envido();
			cederTurno();
			round.actualizarCantoEnPantalla(P2_ENVIDO);
			return;
		}
		return;
	}
	
	//Envido en caso 2
	if(botjuego.envido == 2 and m_envido->ver_finalizado() == false){
		if(m_envido->ver_status() == Envido::NO_INICIADO){
			m_envido->cantar_envido();
			cederTurno();
			round.actualizarCantoEnPantalla(P2_ENVIDO);
			return;
		}
		if(m_envido->ver_status() == Envido::EN_ESPERA){
			if(m_envido->ver_tipo_en_juego() == Envido::ENVIDO){
				m_envido->cantar_envido_envido();
				cederTurno();
				round.actualizarCantoEnPantalla(P2_ENVIDOENVIDO);
				return;
			}
			if(m_envido->ver_tipo_en_juego() == Envido::ENVIDOENVIDO){
				m_envido->cantar_falta_envido();
				cederTurno();
				round.actualizarCantoEnPantalla(P2_FALTAENVIDO);
				return;
			}
			if(m_envido->ver_tipo_en_juego() == Envido::FALTAENVIDO){
				m_envido->aceptar();
				cederTurno();
				round.actualizarCantoEnPantalla(NADA);
			}
		}
	}
	
	
	
	//Truco en caso 2 o exepcion
	if(botjuego.truco == 2 or Exepcion()){
		if(m_truco->obtenerStatus() == Truco::NO_INICIADO){
			m_truco->cantar();
			m_truco->setGenerated_by(2);
			cederTurno();
			round.actualizarCantoEnPantalla(P2_TRUCO);
			return;
		}
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA and m_truco->obtenerRedisputar() == 2 and m_truco->obtenerGenerated_by() == 1){
			m_truco->redisputar();
			round.actualizarCantoEnPantalla(P2_RETRUCO);
			m_truco->setGenerated_by(2);
			cederTurno();
			return;
		}
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA and m_truco->obtenerRedisputar() == 1  and m_truco->obtenerGenerated_by() == 1){
			m_truco->redisputar();
			round.actualizarCantoEnPantalla(P2_VALECUATRO);
			m_truco->setGenerated_by(2);
			cederTurno();
			return;
		}
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA and m_truco->obtenerRedisputar() == 0  and m_truco->obtenerGenerated_by() == 1){
			m_truco->aceptar();
			cederTurno();
			round.actualizarCantoEnPantalla(P2_QUIERO);
			return;
		}
		if(Exepcion()){
			if(m_truco->obtenerStatus() == Truco::ACEPTADO and m_truco->obtenerRedisputar() == 2  and m_truco->obtenerGenerated_by() == 1){
				m_truco->redisputar();
				round.actualizarCantoEnPantalla(P2_RETRUCO);
				m_truco->setGenerated_by(2);
				cederTurno();
				return;
			}
			if(m_truco->obtenerStatus() == Truco::ACEPTADO and m_truco->obtenerRedisputar() == 1  and m_truco->obtenerGenerated_by() == 1){
				m_truco->redisputar();
				round.actualizarCantoEnPantalla(P2_VALECUATRO);
				m_truco->setGenerated_by(2);
				cederTurno();
				return;
			}
		}
	}
	//Truco en caso 0
	if(botjuego.truco == 0){
		//Excepcion a las reglas en caso de que tu ultima carta sea muy buena
		if(cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){
			for(auto carta : cartas){
				if(carta.obtenerEnMano() == true){
					if(carta.verPoder() <= 6){
						m_truco->aceptar();
						m_envido->finalizarEnvido();
						round.actualizarCantoEnPantalla(P2_QUIERO);
						cederTurno();
						return;
					}
				}
			}
		}
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA){
			m_truco->rechazar();
			round.actualizarCantoEnPantalla(P2_NOQUIERO);
			return;
		}
	}
	
	//Truco en caso 1
	if(botjuego.truco == 1){
		if(m_truco->obtenerStatus() == Truco::EN_ESPERA){
			//Excepcion a las reglas en caso de que tu ultima carta sea muy mala
			if(cartas_en_mano == 1 and m_rival->verCartasEnMano() == 1){
				for(auto carta : cartas){
					if(carta.obtenerEnMano() == true){
						if(carta.verPoder() > 8){
							m_truco->rechazar();
							round.actualizarCantoEnPantalla(P2_NOQUIERO);
							return;
						}
					}
				}
			}
			if(cartas_en_mano == 0 and m_rival->verCartasEnMano() == 1){
				if(en_mesa[2].verPoder() > 8){
					m_truco->rechazar();
					round.actualizarCantoEnPantalla(P2_NOQUIERO);
					return;
				}
			}
			m_truco->aceptar();
			m_envido->finalizarEnvido();
			round.actualizarCantoEnPantalla(P2_QUIERO);
			cederTurno();
			return;
		}
	}
	
	
	
	if(m_truco->verUltimoEnTirar()==2 and m_truco->obtenerStatus() != 2){
		cederTurno();
	}
	
	//Tirar carta correspondiente a la situacion
	jugar();
	


}
void Player2::dibujar(RenderWindow &m){
		
		for(Carta &x : cartas){
			x.actualizar();
			x.dibujar(m);
		}
		int i = -230;
		for(Carta &x : en_mesa){
			i+=45;
			x.actualizar_mesa(i);
			x.dibujar(m);
		}
		i = 0;
}


