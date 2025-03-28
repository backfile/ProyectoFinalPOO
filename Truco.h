#ifndef ROUNDLOGIC_H
#define ROUNDLOGIC_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


#include <iostream>
#include "Envido.h"
using namespace std;
using namespace sf;


//Una misma instancia interactua con los players

class Truco{
public:
	Truco(bool turno_player_1, Envido *envido);
	
	enum Status {NO_INICIADO, EN_ESPERA, RECHAZADO, ACEPTADO};
	
	void actualizar();
	void dibujar(RenderWindow &w, bool statusRound);
	void aceptar();
	void rechazar();
	void cantar();
	void redisputar();
	void setGenerated_by(int generated_by);
	int obtenerGenerated_by();
	int obtenerStatus();
	int obtenerCastigo();
	int obtenerValor();
	int obtenerRedisputar();
	void cambiarUltimoEnTirar(int aux);
	int verUltimoEnTirar();
	void modificar_turno_player(bool turno_player_1);
	
private:
	
	bool m_turno_player_1;
	int max_redisputar = 2;
	int valor = 1;
	int castigo = 0;
	int m_generated_by;	
	int ultimo_en_tirar;
	int status = NO_INICIADO; 
	
	Envido *m_envido;
	
	Text text;
	Font font;
	
	
	//Botones
	Texture t_truco;
	Sprite s_truco;
	
	Texture t_retruco;
	Sprite s_retruco;
		
	Texture t_valecuatro;
	Sprite s_valecuatro;
	
	Texture t_quiero;
	Sprite s_quiero;
	
	Texture t_noquiero;
	Sprite s_noquiero;
	
	
	int elementos_on[5]; //0 off  //1 on
	// 0-Truco 1-ReTruco 2-ValeCuatro 3-Quiero 4-NoQuiero
};




#endif

