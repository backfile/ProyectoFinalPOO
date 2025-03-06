#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Player.h"
#include "Player2.h"
#include "Mazo.h"
#include "Envido.h"

using namespace sf;


class Round {
public:
	//Empezar partida en el constructor
	
	Round(bool turn_player1, Window *w, int puntos_a_jugar, int player1puntos);
	void verificar_estado_truco();
	void verificar_estado_envido();
	void actualizar();
	void dibujar(RenderWindow &w);
	bool getStatus();
	int getStatusTruco();
	int getPuntosPlayer1();
	int getPuntosPlayer2();
	int getPuntosGanador();
	bool getPlayer1ganador();
	int calcularPuntosEnvidoP1();
	int calcularPuntosEnvidoP2();
	bool obtenerGanadorEnvido();
	bool obtenerFinalizadoEnvido();
	int obtenerPuntosEnvidoPlayer1();
	int obtenerPuntosEnvidoPlayer2();
	bool obtener_envido_listo_para_sumar();
	bool actualizarCantoEnPantalla(int num);
private:
	
	//generales
	bool status = true;
	bool player1ganador;
	int aux_envido_stats = 230;
	bool turnoaux = true;
	bool turno2aux = true;
	bool envido_listo_para_sumar = false;
	bool mano_player1;
	bool envido_gano_player1;
	
	//Puntos del truco
	int puntos_ganador = 0;
	int player1puntos = 0;
	int player2puntos = 0;
	
	//Puntos del envido
	
	int puntos_envido_player1 = 0;
	int puntos_envido_player2 = 0;
	
	int puntos_ganados_envido_player1 = 0;
	int puntos_ganados_envido_player2 = 0;
	
	//Objetos
	Text text_player1;
	Text text_player2;
	Font font;
	Mazo mazo;
	Envido envido;
	Truco truco;
	Player player1;
	Player2 player2;
	Texture t_botones;
	Sprite s_botones;
	
	//variable que representa el canto actual en pantalla
	int canto_actual_en_pantalla;  
	int contador_mostrar_canto_actual = 0;
	
	//Texturas para mostrar los puntos del envido
	Texture t_envido_ganaste;
	Sprite s_envido_ganaste;
	
	Texture t_envido_perdiste;
	Sprite s_envido_perdiste;
	
	
	Texture t_stats_envido1;
	Sprite s_stats_envido1;
	
	//Texturas de los cantos en pantalla
	
	//Player1
	Texture t_truco_pantalla;
	Sprite s_truco_pantalla;
	
	Texture t_retruco_pantalla;
	Sprite s_retruco_pantalla;
	
	Texture t_valecuatro_pantalla;
	Sprite s_valecuatro_pantalla;
	
	Texture t_quiero_pantalla;
	Sprite s_quiero_pantalla;
	
	Texture t_noquiero_pantalla;
	Sprite s_noquiero_pantalla;
	
	Texture t_envido_pantalla;
	Sprite s_envido_pantalla;
	
	Texture t_envidoenvido_pantalla;
	Sprite s_envidoenvido_pantalla;
	
	Texture t_realenvido_pantalla;
	Sprite s_realenvido_pantalla;
	
	Texture t_faltaenvido_pantalla;
	Sprite s_faltaenvido_pantalla;
	
	//Player2
	
	Texture t_truco2_pantalla;
	Sprite s_truco2_pantalla;
	
	Texture t_retruco2_pantalla;
	Sprite s_retruco2_pantalla;

	Texture t_valecuatro2_pantalla;
	Sprite s_valecuatro2_pantalla;
	
	Texture t_quiero2_pantalla;
	Sprite s_quiero2_pantalla;
	
	Texture t_noquiero2_pantalla;
	Sprite s_noquiero2_pantalla;
	
	Texture t_envido2_pantalla;
	Sprite s_envido2_pantalla;
	
	Texture t_envidoenvido2_pantalla;
	Sprite s_envidoenvido2_pantalla;
	
	Texture t_realenvido2_pantalla;
	Sprite s_realenvido2_pantalla;
	
	Texture t_faltaenvido2_pantalla;
	Sprite s_faltaenvido2_pantalla;
};

#endif

