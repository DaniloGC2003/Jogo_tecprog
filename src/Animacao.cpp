#include "../headers/Animacao.h"
namespace Animation
{
    //const float Animacao::switchTime = 0.3;

    Animation::Animacao::Animacao(const char* caminho, Gerenciador_grafico* pGraf) :
        pGraf(pGraf), corpo(),
        textura(pGraf->carregaTextura(caminho))
    {
        corpo.setTexture(textura);
        corpo.setSize(sf::Vector2f(textura->getSize().x, textura->getSize().y));
        corpo.setOrigin(corpo.getSize().x / 2, corpo.getSize().y / 2);
    }

    Animacao::Animacao() : pGraf(nullptr), corpo(), textura(nullptr)
    {
    }

    Animacao::~Animacao() {
    }

    /*void Animacao::inicializaTextura(const char* caminho, coordenadas::vetoru imagemCount) {

        this->imagemCount = imagemCount;
        textura = pGraf->carregarTexture(caminho);

        uvRect.width = textura->getSize().x / float(imageCount.x);
        uvRect.height = textura->getSize().y / float(imageCount.y);

        corpo.setSize(coordenadas::vetorfloat(uvRect.width, uvRect.height));
        corpo.setOrigin(coordenadas::vetorfloat(uvRect.width, uvRect.height) / 2.0f);
        corpo.setTexture(textura);
    }


    void Animacao::Update(int row, float deltatime, bool faceRight, coordenadas::vetorfloat pos) {

        imagemAtual.x = 0;
        imagemAtual.y = row;

        totalTime += dt;

        if (totalTime >= switchTime) {
            totalTime -= switchTime;
            imagemAtual.x++;

            if (imagemAtual.x >= imagemCount.x) {
                imagemAtual.x = 0;
            }
        }
        uvRect.top = imagemAtual.y * uvRect.height;

        if (faceRight) {
            uvRect.left = imagemAtual.x * uvRect.width;
            uvRect.width = abs(uvRect.width);
        }
        else {
            uvRect.left = (imagemAtual.x + 1) * abs(uvRect.width);
            uvRect.width = -abs(uvRect.width);
        }

        body.setPosition(pos);
        body.setTextureRect(uvRect);
    }


    void Animacao::setimagemCount(coordenadas::vetoru imagemCount) {
        this->imagemCount = imagemCount;
    }
    */
    void Animacao::render() {
        pGraf->desenhar(&corpo);
    }

    coordenadas::vetorfloat Animacao::getTam()
    {
        return coordenadas::vetorfloat(corpo.getSize().x, corpo.getSize().y);
    }


}
