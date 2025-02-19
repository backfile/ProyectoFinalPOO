#ifndef ENVIDO_H
#define ENVIDO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class Envido {
public:
	Envido(bool turno_player_1);
	void dibujar(RenderWindow &w, bool statusRound);
	void actualizar();
	void cantar_envido();
	void cantar_envido_envido();
	void cantar_real_envido();
	void cantar_falta_envido();
	void rechazar(int aux);
	void aceptar();
	bool ver_turno_player_1();
	bool ver_finalizado();
	bool ver_tiro_carta_player1();
	bool ver_tiro_carta_player2();
	void modificar_tiro_carta_player1();
	void modificar_tiro_carta_player2();
	int ver_generated_by();
	void modificar_turno_player(bool aux);
	int ver_status();
	int ver_tipo_en_juego();
	void finalizarEnvido();
	void cambiarGanador(bool aux);
	bool obtenerGanador();
	int obtenerValor();
	int obtenerPrev();
	int obtenerRechazado_by();
	
	
private:
	
	bool m_turno_player_1;
	bool tiro_carta_player1 = false;
	bool tiro_carta_player2 = false;
	bool ganadorplayer1;
	int m_generated_by;
	bool finalizado = false;
	int status = 0; // 0 no iniciado // 1 request // 2 rechazado // 3 aceptado
	int tipo_en_juego; // 1 envido // 2 real envido // 3 envido envido // 4 falta envido;
	int prev = 1;
	int valor = 1;
	int rechazado_by;
	
	
	//Botones
	Texture t_envido;
	Sprite s_envido;
	
	Texture t_envidoenvido;
	Sprite s_envidoenvido;
	
	Texture t_realenvido;
	Sprite s_realenvido;
	
	Texture t_faltaenvido;
	Sprite s_faltaenvido;
	
	Texture t_quiero;
	Sprite s_quiero;
	
	Texture t_noquiero;
	Sprite s_noquiero;
	
	int elementos_on[6];
	// 0-envido 1-envidoenvido 2-realenvido 3-faltaenvido 4-quiero -5noquiero
};

#endif

