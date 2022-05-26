#include "../headers/Entidade.h"

namespace Entities
{
    /*Entidade::Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::RectangleShape hit) :
        Ente(id, pos) {
        hitbox = hit;
        velocidade = coordenadas::vetorfloat(0.0f, 0.0f);
    }*/

    Entidade::Entidade(coordenadas::vetorfloat pos) : Ente(pos)
    {
        velocidade = coordenadas::vetorfloat(0.0f, 0.0f);
    }

    Entidade::Entidade() {
        velocidade = coordenadas::vetorfloat(0.0f, 0.0f);

    }

    Entidade::~Entidade() {
    }

    void Entidade::mudarPosicao(coordenadas::vetorfloat pos) {
        mudarPos(pos);
    }

    coordenadas::vetorfloat Entidade::getPosicao() const {
        return getPos();
    }

    void Entidade::setVelocidade(coordenadas::vetorfloat vel) {
        velocidade = vel;
    }

    coordenadas::vetorfloat Entidade::getVelocidade() const {
        return velocidade;
    }

    sf::RectangleShape* Entidade::getHitbox() {
        return getAnimacao()->getCorpo();
    }

    /*ID_Ent::ID Entidade::getId() {
        return getID();
    }*/

    void Entidade::Move(coordenadas::vetorfloat vec) {
        MoveCorpo(vec);
    }

}
