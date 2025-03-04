#ifndef ELECCION_H
#define ELECCION_H
#include "Escena.h"

class Eleccion : public Escena{
public:
	Eleccion(Window *w);
	void actualizar(Juego &j) override; //Se ejecuta siempre
	void dibujar(RenderWindow &w) override;   //Se ejecuta siempre
private:
	Window *m_window;
	sf::Vector2i mousePos;
	int aux = 15; // Utilizado para que no se seleccione automaticamente por mala deteccion de clicks
	bool puntos5Boton_porEncima = false;
	bool puntos15Boton_porEncima = false;
	bool puntos30Boton_porEncima = false;
	
	Texture t_background;
	Sprite s_background;
	
	Texture t_flechaeleccion1;
	Sprite s_flechaeleccion1;
	
	Texture t_flechaeleccion2;
	Sprite s_flechaeleccion2;
	
	Texture t_flechaeleccion3;
	Sprite s_flechaeleccion3;
	
	
	sf::RectangleShape puntos5boton;
	sf::RectangleShape puntos15boton;
	sf::RectangleShape puntos30boton;
};

#endif

