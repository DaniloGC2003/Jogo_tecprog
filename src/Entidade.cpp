#include "Entidade.h"

#include "Animacao.h"

Entidade::Entidade(ID_Ent::ID id, sf::Vector2f pos, sf::Vector2f hit) :
Ente(id, pos) {
    hitbox = hit;
    velocidade = sf::Vector2f(0.0f, 0.0f);
    
}

Entidade::Entidade() {
    hitbox = sf::Vector2f(0.0f, 0.0f);
    velocitdade = sf::Vector2f(0.0f, 0.0f);
   
}

Entidade::~Entidade() {
}

void Entidade::mudarPoscao(const Vector2f pos) {
    mudarPos(pos);
}

Vector2f Entity::getPosicao() const {
    return getPos();
}

void Entity::setVelocidade(const Vector2f vel) {
    velocidade = vel;
}

Vector2f Entidade::getVelocidade() const {
    return velocidade;
}

void Entidade::setHitbox(const Vector2f hit) {
    hitbox = hit;
}

Vector2f Entidade::getHitbox() const {
    return hitbox;
}

ID_Ent::ID Entidade::getId() const {
    return getID();
}

void Entidade::Move(sf::Vector2f vec) {
    MoveCorpo(vec);
}
