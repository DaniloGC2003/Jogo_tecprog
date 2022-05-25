#include "../headers/Animacao.h"
namespace Animation
{

    Animacao::Animacao() :
        
        pGraf(new Gerenciador_grafico()),
        textura(nullptr)
         {
        
    }

    Animacao::~Animacao() {
        delete textura;
        delete pGraf;
    }

    void Animacao::inicializaTextura(const char* caminho, coordenadas::vetorfloat pos) {
        
        
        if (caminho) {

            textura = new sf::Texture;
            textura->loadFromFile(caminho);
        }
        
        
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
    void Animacao::desenhar() {
        pGraf->desenhar(&corpo);
    }

}
