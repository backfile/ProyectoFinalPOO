#ifndef MATCH_H
#define MATCH_H
#include "Match.h"
#include "Round.h"
#include "Escena.h"

class Match : public Escena {
public:
	Match(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
	void obtener_puntos();
	
private:
	Round *round;
	int player1_puntos = 0;
	int player2_puntos = 0;
	bool jugar_primero = true;
	int cont = 0;
	bool aux = true;
	Window *m_window;
	
	//Texturas
	Text text_player1;
	Text text_player2;
	
	Font font;
	
	Texture t_background;
	Sprite s_background;
	
	Texture t_repartiendo;
	Sprite s_repartiendo;
	
	//Palitos
	Texture t_madera;
	Sprite s_madera;
	
	sf::RectangleShape palito1;
	sf::RectangleShape palito2;
	sf::RectangleShape palito3;
	sf::RectangleShape palito4;
	sf::RectangleShape palito5;
	sf::RectangleShape palito6;
	sf::RectangleShape palito7;
	sf::RectangleShape palito8;
	sf::RectangleShape palito9;
	sf::RectangleShape palito10;
	sf::RectangleShape palito11;
	sf::RectangleShape palito12;
	sf::RectangleShape palito13;
	sf::RectangleShape palito14;
	sf::RectangleShape palito15;
	sf::RectangleShape palito16;
	sf::RectangleShape palito17;
	sf::RectangleShape palito18;
	sf::RectangleShape palito19;
	sf::RectangleShape palito20;
	sf::RectangleShape palito21;
	sf::RectangleShape palito22;
	sf::RectangleShape palito23;
	sf::RectangleShape palito24;
	sf::RectangleShape palito25;
	sf::RectangleShape palito26;
	sf::RectangleShape palito27;
	sf::RectangleShape palito28;
	sf::RectangleShape palito29;
	sf::RectangleShape palito30;
	
	
	sf::RectangleShape Apalito1;
	sf::RectangleShape Apalito2;
	sf::RectangleShape Apalito3;
	sf::RectangleShape Apalito4;
	sf::RectangleShape Apalito5;
	sf::RectangleShape Apalito6;
	sf::RectangleShape Apalito7;
	sf::RectangleShape Apalito8;
	sf::RectangleShape Apalito9;
	sf::RectangleShape Apalito10;
	sf::RectangleShape Apalito11;
	sf::RectangleShape Apalito12;
	sf::RectangleShape Apalito13;
	sf::RectangleShape Apalito14;
	sf::RectangleShape Apalito15;
	sf::RectangleShape Apalito16;
	sf::RectangleShape Apalito17;
	sf::RectangleShape Apalito18;
	sf::RectangleShape Apalito19;
	sf::RectangleShape Apalito20;
	sf::RectangleShape Apalito21;
	sf::RectangleShape Apalito22;
	sf::RectangleShape Apalito23;
	sf::RectangleShape Apalito24;
	sf::RectangleShape Apalito25;
	sf::RectangleShape Apalito26;
	sf::RectangleShape Apalito27;
	sf::RectangleShape Apalito28;
	sf::RectangleShape Apalito29;
	sf::RectangleShape Apalito30;
	
	vector<RectangleShape> palitos;
	vector<RectangleShape> Apalitos;
	
};

#endif

