#pragma once

#include "Ente.h"
#include "ID.h"
#include "Vetor.h"
#include <SFML\Graphics.hpp>
#define GRAVITY 0.2

namespace Entities {

    class Entidade : public Ente {
    protected:
    public:
        //Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::RectangleShape hit);
        Entidade(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem);
        Entidade();
        //virtual ~Entidade();
        virtual ~Entidade();

        void mudarPosicao(coordenadas::vetorfloat pos);
        coordenadas::vetorfloat getPosicao() const;

        //sf::RectangleShape* getHitbox();

        virtual void executar();

        //ID_Ent::ID getId();
        void Move(coordenadas::vetorfloat vec);

    };
}