#include "Jogo.h"

Jogo::Jogo() : window(sf::VideoMode(450, 450), "SFML works!")
{
    graficos.setWindow(&window);
    jogador.setTamanho(sf::Vector2f(100.f, 50.f));
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        graficos.desenhar(jogador.getHitbox());
        window.display();
    }
}

