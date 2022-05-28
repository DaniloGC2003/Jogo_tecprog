#pragma once
#include "ID.h"
#include "Animacao.h"
#include "Vetor.h"
namespace Entities
{
    class Ente
    {
    protected:
        Animation::Animacao RectangleShape;
        //ID_Ent::ID id;
        coordenadas::vetorfloat posicao;

    public:
        Ente(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
        Ente();
        virtual ~Ente();

        void mudarPos(coordenadas::vetorfloat pos);
        coordenadas::vetorfloat getPos() const;
        void MoveCorpo(coordenadas::vetorfloat vec);

        Animation::Animacao* getAnimacao() { return &RectangleShape; }
        coordenadas::vetorfloat getTamanho();
        //ID_Ent::ID getID();

        //virtual void initialize() = 0;
        //virtual void update(float dt) = 0;
        virtual void render();

    };

}


