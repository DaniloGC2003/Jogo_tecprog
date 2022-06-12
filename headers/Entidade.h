#pragma once

#include "Ente.h"
#include "Vetor.h"
#include <SFML\Graphics.hpp>
namespace Gerenciadores
{
    class Gerenciador_grafico;
    class Gerenciador_colisoes;
}
#define GRAVITY 0.2

namespace Entities {

    class Entidade : public Ente {
    protected:
        Gerenciadores::Gerenciador_colisoes* pColisoes;
    public:
        Entidade(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem);
        Entidade();
        virtual ~Entidade();

        void mudarPosicao(coordenadas::vetorfloat pos);
        coordenadas::vetorfloat getPosicao() const;

        virtual void executar();

        void Move(coordenadas::vetorfloat vec);

    };
}