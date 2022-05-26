#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), graficos(), colisoes(),
jogador(coordenadas::vetorfloat(101.f, 110.f), graficos.getInstance(), "Woodcutter.png"),
plataforma(coordenadas::vetorfloat(300.f, 300.f), graficos.getInstance(), "Woodcutter.png")
{
    jogador.setVelocidade(coordenadas::vetorfloat(0.1f,0.1f)); 
    //jogador.getAnimacao()->getCorpo()->setFillColor(sf::Color::Green);
    personagens.pushEntidade(&jogador);
    
    plataforma.getHitbox()->setFillColor(sf::Color::Green);
    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));
    estaticas.pushEntidade(&plataforma);
    Executar();
}

Jogo::~Jogo()
{
}

ListaEntidades* Jogo::getPersonagens()
{
    return &personagens;
}

ListaEntidades* Jogo::getEstaticas()
{
    return &estaticas;
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

       colisoes.colidir(&personagens, &estaticas);

        for (int i = 0; i < personagens.getTamanho(); i++)
        {
            graficos.desenhar(personagens.getEntidade(i)->getHitbox());
        }
        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
            graficos.desenhar(estaticas.getEntidade(i)->getHitbox());
        }
        window->display();//fazer loop p lista tbm
    }
}

