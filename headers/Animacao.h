#pragma once

#include "Gerenciador_grafico.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Vetor.h"
#include <iostream>
//referencia usada para construir essa classe: https://www.youtube.com/watch?v=KJJo9QPY8kI&t=719s&ab_channel=BurdaCanal
namespace Animation
{

    class Animacao {
    private:
        Gerenciadores::Gerenciador_grafico* pGraf;
        sf::Texture* textura;
        sf::RectangleShape corpo;

    public:
        Animacao(coordenadas::vetorfloat posicao,const char* caminho, Gerenciadores::Gerenciador_grafico* pGraf);
        Animacao();
        ~Animacao();

        void render();
        void setGerenciadorGrafico(Gerenciadores::Gerenciador_grafico* pGrafM) { pGraf = pGrafM; }
        void setPosicao(coordenadas::vetorfloat v) { corpo.setPosition(v.getX(), v.getY()); }
        sf::RectangleShape* getCorpo() { return &corpo; }
        coordenadas::vetorfloat getTam();
        Gerenciadores::Gerenciador_grafico* getpGraf() { return pGraf; }

        void mudaEscala(float mult_x, float mult_y);
    };

}
