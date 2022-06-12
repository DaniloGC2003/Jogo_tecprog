#include "../headers/Agua.h"

Entities::Obstaculos::Agua::Agua(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho, Personagens::Jogador* pJ):
	Obstaculo(pos,pGraf,pGC,caminho), pJogador(pJ), cooldown((float)COOLDOWN_AGUA)
{
	getAnimacao()->getCorpo()->setFillColor(sf::Color::Green);
}

Entities::Obstaculos::Agua::Agua() : Obstaculo(), pJogador(nullptr), cooldown((float)COOLDOWN_AGUA)
{
}

Entities::Obstaculos::Agua::~Agua()
{
	pJogador = nullptr;
}

void Entities::Obstaculos::Agua::executar()
{
	if (pColisoes->verifica_colisao(static_cast<Entidade*>(this), static_cast<Entidade*>(pJogador)))
	{
		if (cooldown >= (float)COOLDOWN_AGUA)
		{
			pJogador->tomaDano(DANO_AGUA);
			cooldown = 0.f;
		}
		else
		{
			cooldown += 5.f;
		}
	}

	getAnimacao()->render();
}
