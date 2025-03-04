#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "Escena.h"
#include "Juego.h"


class Historial : public Escena{
public:
	Historial(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
private:
	bool primera_vez = true;
	bool flecha_porEncima = false;
	
	vector<Partida>v;
	Window *m_window;
	sf::Vector2i mousePos;
	
	Texture t_background;
	Sprite s_background;
	
	Text vacio;
	
	vector<Text>texts;
	Font font;
	
	Texture t_flecha;
	Sprite s_flecha;
	
	Texture t_flecha_encima;
	Sprite s_flecha_encima;
	
	sf::RectangleShape flechaBoton;
};

#endif

