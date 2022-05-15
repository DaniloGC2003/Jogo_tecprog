#pragma once

#include "Ente.h"
#include "ID.h"

namespace Entities {

    class Entidade : public Ente {
    protected:
        sf::Vector2f velocidade;
    	sf::Vector2f hitbox;

    public:
	Entidade(ID_Ent::ID id, sf::Vector2f pos, sf::Vector2f hit);
    	Entidade();
    	virtual ~Entidade();
	    
        void mudarPosicao(const sf::Vector2f pos);
    	sf::Vector2f getPosicao() const;

    	void setVelocidade(const sf::Vector2f vel);
    	sf::Vector2f getVelocidade() const;

    	void setHitbox(const sf::Vector2f hit);
    	sf::Vector2f getHitbox() const;

    	virtual void update(float dt) = 0;
    	virtual void initialize() = 0;

    	ID_Ent::ID getId() const;
    	void Move(sf::Vector2f vec);

    };
