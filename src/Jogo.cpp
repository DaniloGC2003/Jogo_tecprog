#include "../headers/Jogo.h"

Jogo::Jogo() : camera(sf::Vector2f(480.f, 270.f), sf::Vector2f(960.f, 540.f)), grafico(),
menu(coordenadas::vetorfloat(0.f,0.f),grafico.getInstance(),"texturas_e_fontes/game_background_4.png"),
noMenu(true), naPrimeiraFase(false), naSegundaFase(false),
fase1(coordenadas::vetorfloat(0.f, 0.f), grafico.getInstance(), "texturas_e_fontes/tile15.png"),
fase2(coordenadas::vetorfloat(0.f, 0.f), grafico.getInstance(), "texturas_e_fontes/tile11.png")
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
                if (menu.seleciona() == 1)
                {
                    noMenu = false;
                    naSegundaFase = true;
                    fase2.inicializaFase();
                }
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
        if (naSegundaFase)
        {
            fase2.executar();
            if (!fase2.jogoAtivo())
            {
                noMenu = true;
                naSegundaFase = false;
                grafico.getJanela()->setView(camera);
            }
        }

        grafico.getJanela()->display();
    }
}

