#include "../headers/Projetil.h"
namespace Entities
{
	Projetil::Projetil(Jogador* pJ, Gerenciadores::Gerenciador_colisoes* pGC, coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* pathImagem, int dano)
		: Entidade(pos, pGraf, pGC, pathImagem), dano(dano), pJogador(pJ), posicaoInicial(pos)
	{
	}
	Projetil::Projetil() : Entidade(), dano(100), pJogador(nullptr), posicaoInicial()
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
	bool Projetil::verificaColisao_obstaculos()
	{
		return pColisoes->verifica_colisao_estaticos(static_cast<Entidade*>(this));
	}
	void Projetil::executar()
	{
		//std::cout << "salve\n";
		bool flagEliminado = false;
		if (verificaColisao_personagens())//fazer com todos os personagens
		{
			//pJogador->setVida(pJogador->getVida() - dano);
			flagEliminado = true;
			//pColisoes->getpPersonagens()->deleteEntidade(static_cast<Entidade*>(this));
		}
		/*if (verificaColisao_obstaculos())
		{
			//std::cout << "bateu\n"
			flagEliminado = true;
			//pColisoes->getpPersonagens()->deleteEntidade(static_cast<Entidade*>(this));
		}*/
		if (fabs(getPos().getX() - posicaoInicial.getX()) > 350.f)
		{
			flagEliminado = true;
		}
		Move(coordenadas::vetorfloat((float)VEL_PROJETIL, 0.f));
		getAnimacao()->render();
		if (flagEliminado)
		{
			pColisoes->getpPersonagens()->deleteEntidade(static_cast<Entidade*>(this));
		}
	}
}
