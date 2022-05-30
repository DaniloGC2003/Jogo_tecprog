#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
namespace Gerenciadores
{
	class Gerenciador_grafico
	{
	private:
		sf::RenderWindow janela;
		std::map<const char*, sf::Texture*> mapaTexturas;
		std::map<const char*, sf::Font*> mapaFontes;

	public:
		Gerenciador_grafico();
		~Gerenciador_grafico();
		Gerenciador_grafico* getInstance();
		sf::RenderWindow* getJanela();
		void desenhar(sf::RectangleShape* hitbox);
		void desenhar(sf::Text* texto);

		sf::Texture* carregaTextura(const char* path);
		sf::Font* carregaFonte(const char* path);
		//void mostrar()
	};


}
