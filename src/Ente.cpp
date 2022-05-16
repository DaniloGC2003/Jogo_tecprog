#include "Ente.h"

#include "Animacao.h"

Ente::Ente(ID_Ent::ID id, coordenadas::vetorfloat pos) :
    RectangleShape(new Animacao()),
    id(id),
    posicao(pos) { }

Ente::Ente() {
    this->id = ID_Ent::empty;
    RectangleShape = nullptr;
}

Ente::~Ente() {
    delete (RectangleShape);
}

void Ente::mudarPos(coordenadas::vetorfloat pos) {
    posicao = pos;
}

coordenadas::vetorfloat Ente::getPos() {
    return position;
}

ID_Ent::ID Ente::getID(){
    return id;
}

void Ente::MoveCorpo(coordenadas::vetorfloat v) {
    posicao = coordenadas::vetorfloat(posicao.x + v.x, posicao.y + v.y);
}

void Ente::render() {
    RectangleShape->render();
}
