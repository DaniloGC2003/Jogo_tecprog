#include "../headers/Animacao.h"
namespace Animation
{
    Animation::Animacao::Animacao(coordenadas::vetorfloat posicao, const char* caminho, Gerenciadores::Gerenciador_grafico* pGraf) :
        pGraf(pGraf), textura(pGraf->carregaTextura(caminho)), corpo()
         
    {
        //inicializa origem, textura, tamanho e posicao
        corpo.setTexture(textura);
        corpo.setSize(sf::Vector2f(textura->getSize().x, textura->getSize().y));
        corpo.setOrigin(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f);
        corpo.setPosition(posicao.getX(), posicao.getY());
    }

    Animacao::Animacao() : pGraf(nullptr), corpo(), textura(nullptr)
    {
    }

    Animacao::~Animacao() 
    {
        pGraf = nullptr;
    }

    void Animacao::render() {
        pGraf->desenhar(&corpo);
    }

    coordenadas::vetorfloat Animacao::getTam()
    {
        return coordenadas::vetorfloat(corpo.getSize().x, corpo.getSize().y);
    }

    void Animacao::mudaEscala(float mult_x, float mult_y)
    {
        corpo.setSize(sf::Vector2f(getTam().getX() * mult_x, getTam().getY() * mult_y));
        corpo.setOrigin(corpo.getSize().x / 2, corpo.getSize().y / 2);
    }
}
