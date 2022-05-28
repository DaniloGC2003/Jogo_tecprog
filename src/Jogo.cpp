#include "../headers/Jogo.h"

Jogo::Jogo() : window(graficos.getJanela()), graficos(), colisoes(),
jogador(coordenadas::vetorfloat(101.f, 110.f), graficos.getInstance(), "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/TheUndying.png", coordenadas::vetorfloat(0.1f, 0.1f)),
lago(coordenadas::vetorfloat(300.f, 300.f), graficos.getInstance(), "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/Water.png"),
background(coordenadas::vetorfloat(0.f, 0.f), graficos.getInstance(), "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/Ball.png")
{
    background.getAnimacao()->mudaEscala(25.f, 25.f);

    personagens.pushEntidade(static_cast<Entities::Entidade*>(& jogador));

    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));
    lago.getAnimacao()->mudaEscala(10.0f, 1.0f);
    estaticas.pushEntidade(&lago);

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

