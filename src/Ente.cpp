#include "../headers/Ente.h"

namespace Entities
{

    Ente::Ente(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
        RectangleShape(pos, caminho, pGraf), posicao(pos)
    {
        mudarPos(pos);
    }

    Ente::Ente() : RectangleShape(), posicao() {
        //this->id = ID_Ent::empty;
    }

    Ente::~Ente() {

    }

    void Ente::mudarPos(coordenadas::vetorfloat pos) {
        posicao = pos;
        RectangleShape.setPosicao(pos);
    }

    coordenadas::vetorfloat Ente::getPos() const {
        return posicao;
    }

    /*ID_Ent::ID Ente::getID() {
        return id;
    }*/

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

