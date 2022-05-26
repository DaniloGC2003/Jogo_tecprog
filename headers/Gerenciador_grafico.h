#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
class Gerenciador_grafico
{
private:
	sf::RenderWindow janela;
	std::map<const char*, sf::Texture*> mapaTexturas;
public:
	Gerenciador_grafico();
	~Gerenciador_grafico();
	Gerenciador_grafico* getInstance();
	sf::RenderWindow* getJanela();
	void desenhar(sf::RectangleShape* hitbox);
	sf::Texture* carregaTextura(const char* path);
	//void mostrar()
};

