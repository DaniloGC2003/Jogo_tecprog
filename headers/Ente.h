#pragma once
#include "Animacao.h"
#include "Vetor.h"
namespace Entities
{
    class Ente
    {
    protected:
        Animation::Animacao RectangleShape;
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

        virtual void render();

    };

}


