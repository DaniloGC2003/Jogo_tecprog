#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), jogador()
{
    //jogador.setTamanho(sf::Vector2f(100.f, 50.f));
    //jogador.
    //jogador.getAnimacao()->
    entidades.pushEntidade(&jogador);
    Executar();
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        for (int i = 0; i < entidades.getTamanho(); i++)
        {
            graficos.desenhar(entidades.getEntidade(i)->getHitbox());
        }
  
        window->display();//fazer loop p lista tbm
    }
}

