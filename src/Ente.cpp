#include "../headers/Ente.h"

namespace Entities
{

    Ente::Ente(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
        RectangleShape(pos, caminho, pGraf), posicao(pos)
    {
        mudarPos(pos);
    }

    Ente::Ente() : RectangleShape(), posicao() {
        
    }

    Ente::~Ente() {

    }

    void Ente::mudarPos(coordenadas::vetorfloat pos) {
        posicao = pos;
        RectangleShape.setPosicao(pos);//muda a posicao do corpo (rectangle shape da sfml)
    }

    coordenadas::vetorfloat Ente::getPos() const {
        return posicao;
    }

    void Ente::MoveCorpo(coordenadas::vetorfloat v) {
        posicao += v;
        RectangleShape.setPosicao(posicao);
    }

    coordenadas::vetorfloat Ente::getTamanho()
    {
        return RectangleShape.getTam();
    }

    void Ente::render() {
        RectangleShape.render();
    }
}

