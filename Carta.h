#ifndef CARTA_H
#define CARTA_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>


using namespace std;
using namespace sf;

class Carta {
public:
	Carta(string texureFile, int power, int tipo, int numero, Vector2f posicion);
	void dibujar(RenderWindow &m);
	void actualizar(int cartas);
	void tirar();
	void is_selected(bool aux);
private:
	int m_power;
	int m_tipo;
	int m_numero;
	bool m_is_selected;
	bool m_en_mano;
	Texture m_t;
	Sprite m_s;
};

#endif

