#include "../headers/Projetil.h"
namespace Entities
{
	Projetil::Projetil(Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, bool frente, const char* pathImagem, int dano)
		: Entidade(pos, pGraf, pGC, pathImagem), dano(dano), pJogador(pJ), posicaoInicial(pos), paraFrente(frente)
	{
	}
	Projetil::Projetil() : Entidade(), dano(100), pJogador(nullptr), posicaoInicial(), paraFrente(true)
	{
	}
	Projetil::~Projetil()
	{
		pJogador = nullptr;
		pColisoes = nullptr;
	}

	bool Projetil::verificaColisao_personagens()
	{
		return pColisoes->verifica_projetil_personagens(static_cast<Entidade*>(this));
	}

	void Projetil::executar()
	{
		bool flagEliminado = false;
		if (verificaColisao_personagens())
		{
			flagEliminado = true;
		}
		if (fabs(getPos().getX() - posicaoInicial.getX()) > 350.f)
		{
			flagEliminado = true;
		}

		if (paraFrente)
		{
			Move(coordenadas::vetorfloat((float)VEL_PROJETIL, 0.f));
		}
		else
		{
			Move(coordenadas::vetorfloat(-(float)VEL_PROJETIL, 0.f));
		}
		getAnimacao()->render();
		if (flagEliminado)//se flag for verdadeira, projetil sera deletado
		{
			pColisoes->getpProjeteis()->deleteEntidade(static_cast<Entidade*>(this));
		}
	}
}
