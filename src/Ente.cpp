#include "../headers/Ente.h"
//#include "../headers/ID.h"


/*Ente::Ente(ID_Ent::ID id, coordenadas::vetorfloat pos) :
    RectangleShape(new Animation::Animacao()),
    id(id),
    posicao(pos) { }*/

Ente::Ente(coordenadas::vetorfloat pos) : RectangleShape(new Animation::Animacao()),
 posicao(pos)
{

}

Ente::Ente() {
    //this->id = ID_Ent::empty;
    RectangleShape = nullptr;
}

Ente::~Ente() {
    delete (RectangleShape);
}

void Ente::mudarPos(coordenadas::vetorfloat pos) {
    posicao = pos;
}

coordenadas::vetorfloat Ente::getPos() const{
    return posicao;
}

/*ID_Ent::ID Ente::getID() {
    return id;
}*/

void Ente::MoveCorpo(coordenadas::vetorfloat v) {
    //posicao = coordenadas::vetorfloat(posicao.x + v.x, posicao.y + v.y);
    //posicao += v;
}

void Ente::render() {
    RectangleShape->render();
}
