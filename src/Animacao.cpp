#include "../headers/Animacao.h"
namespace Animation
{
    const float Animacao::switchTime = 0.3;

    Animation::Animacao::Animacao() :
        pGraf(nullptr),
        imagemCount(coordenadas::vetoru(0, 0)),
        textura(NULL),
        imagemAtual(coordenadas::vetoru(0, 0)) {
        corpo.setSize(sf::Vector2f(50.f, 50.f));
        TempoTotal = 0.0f;
    }

    Animacao::~Animacao() {
    }

    void Animacao::inicializaTextura(const char* caminho, coordenadas::vetorfloat pos) {
        //this->imagemCount = imagemCount;
        //textura = pGraf->carregartextura(caminho);
        
        if (caminho) {

            textura = new sf::Texture;
            textura->loadFromFile(caminho);
        }
        //uvRect.width = textura->getSize().x / float(imagemCount.x);
        //uvRect.height = textura->getSize().y / float(imagemCount.y);
        //corpo.setSize(sf::Vector2f(uvRect.width, uvRect.height));
        //corpo.setOrigin(sf::Vector2f(uvRect.width, uvRect.height) / 2.0f);
        corpo.setOrigin(pos.x, pos.y);
        corpo.setTexture(textura);
        corpo.setSize(sf::Vector2f(150.0f, 150.0f));
    }
    
    /*
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
     

}
