#pragma once

#include "Ente.h"
#include "ID.h"
#include "Vetor.h"
#include <SFML\Graphics.hpp>
namespace Entities {

    class Entidade : public Ente {
    protected:
        coordenadas::vetorfloat posicao;
        coordenadas::vetorfloat velocidade;
        sf::RectangleShape hitbox;

    public:
        //Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::RectangleShape hit);
        Entidade(coordenadas::vetorfloat pos, sf::RectangleShape hit);
        Entidade();
        //virtual ~Entidade();
        ~Entidade();

        void mudarPosicao(coordenadas::vetorfloat pos);
        coordenadas::vetorfloat getPosicao() const;

        void setVelocidade(coordenadas::vetorfloat vel);
        coordenadas::vetorfloat getVelocidade() const;

        void setHitbox(sf::RectangleShape hit);
        sf::RectangleShape* getHitbox();

        //virtual void update(float dt) = 0;
       // virtual void initialize() = 0;

        //ID_Ent::ID getId();
        void Move(coordenadas::vetorfloat vec);

    };
}