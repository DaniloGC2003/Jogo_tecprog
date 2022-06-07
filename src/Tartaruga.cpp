#include "../headers/Tartaruga.h"
namespace Entities
{
	Tartaruga::Tartaruga(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, int pontosVida)
		: Inimigo (pos, pGraf, pathImagem, pJ, pGC, pontosVida), olhandoParaDireita(true), cooldownTiro((float)COOLDOWN_TIRO)
	{
	}
	Tartaruga::Tartaruga() : Inimigo(), olhandoParaDireita(true), cooldownTiro((float)COOLDOWN_TIRO)
	{
	}
	Tartaruga::~Tartaruga()
	{
	}
	void Tartaruga::executar()
	{
		bool flagEliminado = false;
		coordenadas::vetorfloat vetVel(0.f, (float)GRAVITY);

		float distancia = pJogador->getPos().getX() - this->getPos().getX();
		if (fabs(distancia) < 300.f)//se a distancia entre inimigo e jogador for menor que 300
		{
			if (distancia > 0.f)
			{
				olhandoParaDireita = true;
				vetVel += coordenadas::vetorfloat((float)VEL_TARTARUGA, 0.f);
			}
			else
			{
				olhandoParaDireita = false;
				vetVel -= coordenadas::vetorfloat((float)VEL_TARTARUGA, 0.f);
			}
			if (cooldownTiro >= (float)COOLDOWN_TIRO)//se pode atirar
			{
				cooldownTiro = 0.f;
				Entidade* pEnt;
				if (olhandoParaDireita)//cria projetil
				{
					pEnt = static_cast<Entidade*>(new Projetil(pJogador, pColisoes, coordenadas::vetorfloat(getPos().getX() + 50, getPos().getY()), getAnimacao()->getpGraf(), true, "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/Fishbarrel4.png", 30));
				}
				else
				{
					pEnt = static_cast<Entidade*>(new Projetil(pJogador, pColisoes, coordenadas::vetorfloat(getPos().getX() - 50, getPos().getY()), getAnimacao()->getpGraf(), false, "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/Fishbarrel4.png", 30));
				}
				pColisoes->getpProjeteis()->pushEntidade(pEnt);
			}
		}


		if (cooldownTiro < (float)COOLDOWN_TIRO)
			cooldownTiro += 0.1f;
		else
			cooldownTiro = (float)COOLDOWN_TIRO;


		if (pColisoes->verifica_colisao(pJogador, static_cast<Entidade*>(this)))//jogador automaticamente morre se encostar na tartaruga
		{
			pJogador->setVida(0);
			flagEliminado = true;
		}
		if (vida == 0)
		{
			flagEliminado = true;
		}

		Move(vetVel);
		getAnimacao()->render();

		if (flagEliminado)//se flag for true, tartaruga sera deletada
		{
			pColisoes->getpPersonagens()->deleteEntidade(static_cast<Entidade*>(this));
		}

	}
}
