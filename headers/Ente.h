#pragma once
#include "ID.h"

class Vetor;
class Animacao;

class Ente
{
protected:
    Animacao* RectangleShape;
    ID_Ent::ID id;
    coordenadas::vetorfloat posicao;

public:
    Ente(ID_Ent::ID id, coordenadas::vetorfloat pos);
    Ente();
    virtual ~Ente();

    void mudarPos(coordenadas::vetorfloat pos);
    coordenadas::vetorfloat getPos() const;
    void MoveCorpo(coordenadas::vetorfloat vec);
    ID_Ent::ID getID();

    virtual void initialize() = 0;
    virtual void update(float dt) = 0;
    virtual void render();
    
};


