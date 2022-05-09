#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_grafico.h"
class Entidade
{
private:
	sf::RectangleShape hitbox;
	Gerenciador_grafico* graficos;
public:
	Entidade();
	Entidade(sf::Vector2f tamanho);
	~Entidade();
	void setTamanho(sf::Vector2f tam);
	sf::RectangleShape* getHitbox();
};

