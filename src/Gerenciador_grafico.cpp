#include "../headers/Gerenciador_grafico.h"
namespace Gerenciadores
{
    Gerenciador_grafico::Gerenciador_grafico() : janela(sf::VideoMode(600, 600), "SFML works!"), mapaTexturas(),
    mapaFontes() 
    {

    }

    Gerenciador_grafico::~Gerenciador_grafico()
    {
        std::map<const char*, sf::Texture*>::iterator it;

        for (it = mapaTexturas.begin(); it != mapaTexturas.end(); ++it) {
            delete (it->second);
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
    {
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

