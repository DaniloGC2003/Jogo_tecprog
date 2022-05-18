#pragma once

#include "Gerenciador_grafico.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Vetor.h"

namespace Animation
{

class Animacao {
private:
    Gerenciador_grafico* pGraf;
    coordenadas::vetoru imagemCount;
    sf::Texture* textura;
    coordenadas::vetoru imagemAtual;
    sf::RectangleShape corpo;
    sf::IntRect uvRect;
    float TempoTotal;
    static const float switchTime; // tempo para mudar o frame da imagem

public:
    Animacao();
    ~Animacao();

    void inicializaTextura(const char* caminho, coordenadas::vetoru imagemCount);
    void setimagemCount(const sf::Vector2u imagemCount);
    void render();
    void Update(int row, float deltatime, bool faceRight, coordenadas::vetorfloat position);
    void setGerenciadorGrafico (Gerenciador_grafico* pGrafM) { pGraf = pGrafM; }

    sf::RectangleShape* getCorpo() { return &corpo; }

};

}
