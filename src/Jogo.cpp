#include "../headers/Jogo.h"

Jogo::Jogo() : camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(960.f, 540.f)), grafico(), colisoes(&personagens, &estaticas),
jogador(coordenadas::vetorfloat(101.f, 110.f), grafico.getInstance(), colisoes.getInstance(), "texturas_e_fontes/Woodcutter.png"),
agua(coordenadas::vetorfloat(300.f, 300.f), grafico.getInstance(), colisoes.getInstance(), "texturas_e_fontes/preview.png"),
background(coordenadas::vetorfloat(0.f, 0.f), grafico.getInstance(), "texturas_e_fontes/tile15.png"),
barril(coordenadas::vetorfloat(150.f, 265.f), grafico.getInstance(), colisoes.getInstance(), "texturas_e_fontes/Fishbarrel4.png"),
mostraVida(), fonte()
{

    background.getAnimacao()->mudaEscala(500.f, 500.f);

    personagens.pushEntidade(static_cast<Entities::Entidade*>(& jogador));

    agua.getAnimacao()->mudaEscala(50.0f, 1.0f);
    estaticas.pushEntidade(&agua);

    estaticas.pushEntidade(&barril);

    //Entities::Entidade* pEnt = static_cast<Entities::Entidade*>(new Entities::Tartaruga(coordenadas::vetorfloat(600.f, 110.f), grafico.getInstance(), "texturas_e_fontes/Battle_turtle.png", &jogador, &colisoes));
    //personagens.pushEntidade(pEnt);
   // pEnt = static_cast<Entities::Entidade*>(new Entities::Monstro(coordenadas::vetorfloat(550.f, 110.f), grafico.getInstance(), "texturas_e_fontes/Monstro.png", &jogador, &colisoes));
    //personagens.pushEntidade(pEnt);


    fonte = grafico.carregaFonte("texturas_e_fontes/Pixellari.ttf");
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

