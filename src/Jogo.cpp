#include "../headers/Jogo.h"

Jogo::Jogo() : camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(600.f, 600.f)), grafico(), colisoes(&personagens, &estaticas),
jogador(coordenadas::vetorfloat(101.f, 110.f), grafico.getInstance(), "Woodcutter.png"),
agua(coordenadas::vetorfloat(300.f, 300.f), grafico.getInstance(), "preview.png"),
background(coordenadas::vetorfloat(0.f, 0.f), grafico.getInstance(), "tile15.png"),
mostraVida(), fonte()
{

    background.getAnimacao()->mudaEscala(50.f, 25.f);

    personagens.pushEntidade(static_cast<Entities::Entidade*>(& jogador));

    //plataforma.mudarPos(coordenadas::vetorfloat(300.f, 300.f));
    agua.getAnimacao()->mudaEscala(10.0f, 1.0f);
    estaticas.pushEntidade(&agua);

    Entities::Entidade* pEnt = static_cast<Entities::Entidade*>(new Entities::Lesma(coordenadas::vetorfloat(400.f, 110.f), grafico.getInstance(), "preview.png", &jogador, &colisoes));
    personagens.pushEntidade(pEnt);

    fonte = grafico.carregaFonte("Pixellari.ttf");
    mostraVida.setFont(*fonte);
    mostraVida.setFillColor(sf::Color::Black);


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
    while (grafico.getJanela()->isOpen())
    {
        sf::Event event;
        while (grafico.getJanela()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                grafico.getJanela()->close();
        }

        //tempo = relogio.getElapsedTime().asMilliseconds() - tempo;

        grafico.getJanela()->clear();

        background.render();

        colisoes.colidir();//(&personagens, &estaticas);

        for (int i = 0; i < personagens.getTamanho(); i++)
        {
            personagens.getEntidade(i)->executar();
        }

        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
            
            estaticas.getEntidade(i)->executar();
        }

        char hp[15] = "HP: ";
        char vidaJogador[10];
        _itoa_s(jogador.getVida(), vidaJogador, 10);
        strcat_s(hp, vidaJogador);
        mostraVida.setPosition(jogador.getPos().getX()-250, jogador.getPos().getY()-250);
        mostraVida.setString(hp);
        grafico.desenhar(&mostraVida);

        grafico.getJanela()->setView(camera);
        camera.setCenter(sf::Vector2f(jogador.getPosicao().getX(), jogador.getPosicao().getY()));

        grafico.getJanela()->display();
    }
}

