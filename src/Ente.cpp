#include "../headers/Ente.h"
//#include "../headers/ID.h"


/*Ente::Ente(ID_Ent::ID id, coordenadas::vetorfloat pos) :
    RectangleShape(new Animation::Animacao()),
    id(id),
    posicao(pos) { }*/

Ente::Ente(coordenadas::vetorfloat pos) : RectangleShape(),
 posicao(pos)
{

}

Ente::Ente() : {
    //this->id = ID_Ent::empty;
    
}

Ente::~Ente() {

}

void Ente::mudarPos(coordenadas::vetorfloat pos) {
    posicao = pos;
    RectangleShape.setPosicao(pos);
}

coordenadas::vetorfloat Ente::getPos() const{
    return posicao;
}

/*ID_Ent::ID Ente::getID() {
    return id;
}*/

void Ente::MoveCorpo(coordenadas::vetorfloat v) {
    //posicao = coordenadas::vetorfloat(posicao.x + v.x, posicao.y + v.y);
    posicao += v;
    RectangleShape.setPosicao(posicao);
   // printf("posicao: %f %f\n", posicao.getX(), posicao.getY());
}

coordenadas::vetorfloat Ente::getTamanho()
{
    float coordx = RectangleShape.getCorpo()->getSize().x;
    float coordy = RectangleShape.getCorpo()->getSize().y;
    //printf("%f e %f\n", coordx, coordy);
    return coordenadas::vetorfloat(coordx, coordy);
}

void Ente::desenhar() {
    RectangleShape.desenhar();
}
