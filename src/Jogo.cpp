#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), graficos(), colisoes(),
jogador(coordenadas::vetorfloat(101.f, 110.f), graficos.getInstance(), "preview.png", coordenadas::vetorfloat(0.1f, 0.1f)),
plataforma(coordenadas::vetorfloat(300.f, 300.f), graficos.getInstance(), "preview.png"),
background(coordenadas::vetorfloat(0.f, 0.f), graficos.getInstance(), "tile15.png")
{
    std::cout << background.getAnimacao()->getTam().getX() << " " << background.getAnimacao()->getTam().getY() << std::endl;
    background.getAnimacao()->mudaEscala(25.f, 25.f);
    std::cout << background.getAnimacao()->getTam().getX() << " " << background.getAnimacao()->getTam().getY() << std::endl;


    personagens.pushEntidade(static_cast<Entities::Entidade*>(& jogador));

    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));
    plataforma.getAnimacao()->mudaEscala(10.0f, 1.0f);
    estaticas.pushEntidade(&plataforma);

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
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

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

        window->display();//fazer loop p lista tbm
    }
}

