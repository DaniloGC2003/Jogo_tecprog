#include "../headers/Entidade.h"

namespace Entities
{
    /*Entidade::Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::RectangleShape hit) :
        Ente(id, pos) {
        hitbox = hit;
        velocidade = coordenadas::vetorfloat(0.0f, 0.0f);
    }*/

    Entidade::Entidade(coordenadas::vetorfloat pos, sf::RectangleShape hit) : Ente(pos), hitbox(hit)
    {
    }

    Entidade::Entidade() : hitbox(sf::Vector2f(50.f,50.f)) {
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

    void Entidade::setHitbox(sf::RectangleShape hit) {
        hitbox = hit;
    }

    sf::RectangleShape* Entidade::getHitbox() {
        return &hitbox;
    }

    /*ID_Ent::ID Entidade::getId() {
        return getID();
    }*/

    void Entidade::Move(coordenadas::vetorfloat vec) {
        MoveCorpo(vec);
    }

}
