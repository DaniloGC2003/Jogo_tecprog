#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), graficos(), colisoes(), jogador(), plataforma()
{
    jogador.setVelocidade(coordenadas::vetorfloat(0.1f,0.1f)); 
    //jogador.getHitbox()->setOrigin(20.0f, 20.0f);
    personagens.pushEntidade(&jogador);
    //jogador.getHitbox()->setFillColor(sf::Color::Blue);
    jogador.getAnimacao()->inicializaTextura("TheUndying.png",coordenadas::vetorfloat(-10.f,-100.f));

    //plataforma.getHitbox()->setFillColor(sf::Color::Red);
    //plataforma.getHitbox()->setOrigin(25.0f, 25.0f);
    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));

    estaticas.pushEntidade(&plataforma);
    plataforma.getAnimacao()->inicializaTextura("Ball.png",coordenadas::vetorfloat(-50.f,-250.f));
    
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

        /*for (int i = 0; i < personagens.getTamanho(); i++)
        {
            graficos.desenhar(personagens.getEntidade(i)->getHitbox());
        }
        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
            graficos.desenhar(estaticas.getEntidade(i)->getHitbox());
        }*/
        
        for (int i = 0; i < personagens.getTamanho(); i++)
        {
           sf::RectangleShape auxi = personagens.getEntidade(i)->getAnimacao()->getCorpo();
           graficos.desenhar(&auxi);
        }
        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
           sf::RectangleShape aux = estaticas.getEntidade(i)->getAnimacao()->getCorpo();
           graficos.desenhar(&aux);
        }
        window->display();//fazer loop p lista tbm
    }
}

