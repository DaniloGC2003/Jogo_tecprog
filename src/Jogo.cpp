#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), jogador()
{
    //jogador.setTamanho(sf::Vector2f(100.f, 50.f));
    //jogador.
    //jogador.getAnimacao()->
    jogador.setVelocidade(coordenadas::vetorfloat(0.1f,0.1f)); 
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            jogador.Move(coordenadas::vetorfloat(jogador.getVelocidade().getX(), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            jogador.Move(coordenadas::vetorfloat (-jogador.getVelocidade().getX(), 0.f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            jogador.Move(coordenadas::vetorfloat(0.f, jogador.getVelocidade().getY()));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            jogador.Move(coordenadas::vetorfloat(0.f, -jogador.getVelocidade().getY()));
        }
        for (int i = 0; i < entidades.getTamanho(); i++)
        {
            graficos.desenhar(entidades.getEntidade(i)->getHitbox());
        }
  
        window->display();//fazer loop p lista tbm
    }
}

