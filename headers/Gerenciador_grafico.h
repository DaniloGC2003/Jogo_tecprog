#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
//referencia para construir essa classe: https://www.youtube.com/watch?v=RFSOXXsm4Ug&ab_channel=BurdaCanal
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
	};


}
