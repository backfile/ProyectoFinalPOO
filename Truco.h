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
	void redisputar(){
	  if(max_redisputar > 0){	
		  status = 1;
		  castigo = valor;	
		  valor+=valor;
	   }
	  max_redisputar --;
	}
	  
	void setGenerated_by(int generated_by){
		m_generated_by = generated_by;
	}
	  
	int obtenerGenerated_by(){
		return m_generated_by;
	}
	
	int obtenerStatus(){
		return status;
	}
		
	int obtenerCastigo(){
		return castigo;
	}	
	
	int obtenerValor(){
		return valor;
	}	
	
	int obtenerRedisputar(){
		return max_redisputar;
	}
		
	void modificar_turno_player(bool turno_player_1){
		m_turno_player_1 = turno_player_1;
	}
		
private:
	
	bool m_turno_player_1;
	int max_redisputar = 2;
	int valor = 2;
	int castigo = 1;
	int m_generated_by;	
	int status = 0; // 0 no iniciado // 1 en espera de respuesta  // 2 rechazado // 3 aceptado
	
	Text text;
	Font font;
	Texture t_truco;
	Sprite s_truco;
};




#endif

