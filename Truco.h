#ifndef ROUNDLOGIC_H
#define ROUNDLOGIC_H
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


#include <iostream>
using namespace std;
using namespace sf;


//Una misma instancia interactua con los players

class Truco{
public:
	Truco(bool turno_player_1);
	
	void actualizar();
	void dibujar(RenderWindow &w);
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
	int status = 0; // 0 no iniciado // 1 en espera de respuesta  // 2 rechazado // 3 aceptado
	
	Text text;
	Font font;
	Texture t_truco;
	Sprite s_truco;
};




#endif

