#include "../headers/Jogo.h"

Jogo::Jogo() : camera(sf::Vector2f(480.f, 270.f), sf::Vector2f(960.f, 540.f)), grafico(),
menu(coordenadas::vetorfloat(0.f,0.f),grafico.getInstance(),"texturas_e_fontes/game_background_4.png"),
noMenu(true), naPrimeiraFase(false), naSegundaFase(false),
fase1(coordenadas::vetorfloat(0.f, 0.f), grafico.getInstance(), "texturas_e_fontes/tile15.png")
{   
    Executar();
}

Jogo::~Jogo()
{
    
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

            if (noMenu)
            {
                menu.selecionaBaixo();
                menu.selecionaCima();
                if (menu.seleciona() == 0)
                {
                    noMenu = false;
                    naPrimeiraFase = true;
                    fase1.inicializaFase();
                }

                //fazer if pra fase 2 e leaderboard
            }

        }

        
        grafico.getJanela()->clear();
        if (noMenu)
        {
            menu.executar();
        }
        if (naPrimeiraFase)
        {
            fase1.executar();
            if (!fase1.jogoAtivo())
            {
                noMenu = true;
                naPrimeiraFase = false;
                grafico.getJanela()->setView(camera);
            }
        }
        //background.render();

        
       
        //colisoes.colidir();//(&personagens, &estaticas);
        /*
        for (int i = 0; i < personagens.getTamanho(); i++)
        {
            personagens.getEntidade(i)->executar();
        }

        for (int i = 0; i < estaticas.getTamanho(); i++)
        {
            
            estaticas.getEntidade(i)->executar();
        }

        for (int i = 0; i < projeteis.getTamanho(); i++)
        {
            projeteis.getEntidade(i)->executar();
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
        */
        grafico.getJanela()->display();
    }
}

