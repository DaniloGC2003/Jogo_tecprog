#pragma once

#include "Ente.h"
#include "ID.h"
#include "Vetor.h"

namespace Entities {

    class Entidade : public Ente {
    protected:
        coordenadas::vetorfloat velocidade;
    	sf::RectangleShape hitbox;

    public:
	Entidade(ID_Ent::ID id, coordenadas::vetorfloat pos, sf::Vector2f hit);
    	Entidade();
    	virtual ~Entidade();
	    
        void mudarPosicao(coordenadas::vetorfloat pos);
    	coordenadas::vetorfloat getPosicao() const;

    	void setVelocidade(coordenadas::vetorfloat vel);
    	coordenadas::vetorfloat getVelocidade() const;

    	void setHitbox(sf::RectangleShape hit);
    	sf::RectangleShape getHitbox() const;

    	virtual void update(float dt) = 0;
    	virtual void initialize() = 0;

    	ID_Ent::ID getId() const;
    	void Move(coordenadas::vetorfloat vec);

    };
