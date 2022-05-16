#include "Entidade.h"

#include "Animacao.h"

Entidade::Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::RectangleShape hit) :
Ente(id, pos) {
    hitbox = hit;
    velocidade = coordenadas::vetorfloat(0.0f, 0.0f);
    
}

Entidade::Entidade() : hitbox() {
    velocitdade = coordenadas::vetorfloat(0.0f, 0.0f);
   
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

void Entidade::setHitbox(sf:RectangleShape hit) {
    hitbox = hit;
}

sf:RectangleShape  Entidade::getHitbox() const {
    return hitbox;
}

ID_Ent::ID Entidade::getId() const {
    return getID();
}

void Entidade::Move(coordenadas::vetorfloat vec) {
    MoveCorpo(vec);
}
