#include "../headers/Jogo.h"

Jogo::Jogo() : camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(600.f, 600.f)), graficos(), colisoes(),
jogador(coordenadas::vetorfloat(101.f, 110.f), graficos.getInstance(), "Woodcutter.png", coordenadas::vetorfloat(0.1f, 0.1f)),
lago(coordenadas::vetorfloat(300.f, 300.f), graficos.getInstance(), "drakejosh.jpg"),
background(coordenadas::vetorfloat(0.f, 0.f), graficos.getInstance(), "tile15.png")
{

    background.getAnimacao()->mudaEscala(25.f, 25.f);

    personagens.pushEntidade(static_cast<Entities::Entidade*>(& jogador));

    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));
    lago.getAnimacao()->mudaEscala(10.0f, 1.0f);
    estaticas.pushEntidade(&lago);

    Entities::Entidade* pEnt = static_cast<Entities::Entidade*>(new Entities::Inimigo(coordenadas::vetorfloat(201.f, 110.f), graficos.getInstance(), "alh.png", coordenadas::vetorfloat(0.1f, 0.1f), &jogador, &colisoes));
    personagens.pushEntidade(pEnt);

    //Entities::Personagem* pPers = new Entities::Personagem(coordenadas::vetorfloat(350.f, 350.f), graficos.getInstance(), "Woodcutter.png", coordenadas::vetorfloat(0.1f, 0.1f));
    //personagens.pushEntidade(static_cast<Entities::Entidade*>(pPers));

    Executar();
    

}

Jogo::~Jogo()
{
}

Lists::ListaEntidades* Jogo::getPersonagens()
{
    return &personagens;
}

Lists::ListaEntidades* Jogo::getEstaticas()
{
    return &estaticas;
}

void Jogo::Executar()
{
    float tempo = 0.f;
    while (graficos.getJanela()->isOpen())
    {
        sf::Event event;
        while (graficos.getJanela()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                graficos.getJanela()->close();
        }

        //tempo = relogio.getElapsedTime().asMilliseconds() - tempo;

        graficos.getJanela()->clear();

        background.render();

        colisoes.colidir(&personagens, &estaticas);

        for (int i = 0; i < personagens.getTamanho(); i++)
        {
            personagens.getEntidade(i)->executar();
        }

        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
            
            estaticas.getEntidade(i)->executar();
        }

        graficos.getJanela()->setView(camera);
        camera.setCenter(sf::Vector2f(jogador.getPosicao().getX(), jogador.getPosicao().getY()));

        graficos.getJanela()->display();//fazer loop p lista tbm
    }
}

