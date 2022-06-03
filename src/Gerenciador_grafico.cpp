#include "../headers/Gerenciador_grafico.h"
namespace Gerenciadores
{
    Gerenciador_grafico::Gerenciador_grafico() : janela(sf::VideoMode(960, 540), "JOGO"), mapaTexturas(),
    mapaFontes() 
    {

    }

    Gerenciador_grafico::~Gerenciador_grafico()
    {//libera a memoria alocada para elementos graficos
        std::map<const char*, sf::Texture*>::iterator itT;
        std::map<const char*, sf::Font*>::iterator itF;

        for (itT = mapaTexturas.begin(); itT != mapaTexturas.end(); ++itT) {
            delete (itT->second);
        }

        for (itF = mapaFontes.begin(); itF != mapaFontes.end(); ++itF) {
            delete (itF->second);
        }

    }

    Gerenciador_grafico* Gerenciador_grafico::getInstance()
    {
        return this;
    }

    sf::RenderWindow* Gerenciador_grafico::getJanela()
    {
        return &janela;
    }

    void Gerenciador_grafico::desenhar(sf::RectangleShape* hitbox)
    {
        janela.draw(*hitbox);
    }

    void Gerenciador_grafico::desenhar(sf::Text* texto)
    {
        janela.draw(*texto);
    }

    sf::Texture* Gerenciador_grafico::carregaTextura(const char* path)
    {//textura somente sera carregada se ainda nao houver sido 
        std::map<const char*, sf::Texture*>::iterator it = mapaTexturas.begin();

        while (it != mapaTexturas.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            std::cout << "erro ao carregar " << path << std::endl;
            exit(1);
        }

        mapaTexturas.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }
    sf::Font* Gerenciador_grafico::carregaFonte(const char* path)
    {
        std::map<const char*, sf::Font*>::iterator it = mapaFontes.begin();
        while (it != mapaFontes.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        sf::Font* font = new sf::Font();

        if (!font->loadFromFile(path)) {
            std::cout << "erro ao carregar " << path << std::endl;
            exit(1);
        }

        mapaFontes.insert(std::pair<const char*, sf::Font*>(path, font));

        return font;
    }
}

