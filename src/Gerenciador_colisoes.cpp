#include "../headers/Gerenciador_colisoes.h"
namespace Gerenciadores
{
	Gerenciador_colisoes::Gerenciador_colisoes(Lists::ListaEntidades* pP, Lists::ListaEntidades* pE)
		: pPersonagens(pP), pEstaticos(pE)
	{
	}
	Gerenciador_colisoes::Gerenciador_colisoes() : pPersonagens(nullptr), pEstaticos(nullptr)
	{

	}

	Gerenciador_colisoes::~Gerenciador_colisoes()
	{
		pPersonagens = nullptr;
		pEstaticos = nullptr;
	}

	void Gerenciador_colisoes::setpPersonagens(Lists::ListaEntidades* pP)
	{
		if (pP)
			pPersonagens = pP;
	}

	void Gerenciador_colisoes::setpEstaticos(Lists::ListaEntidades* pE)
	{
		if (pE)
			pEstaticos = pE;
	}

	bool Gerenciador_colisoes::verifica_colisao(Entities::Entidade* ent1, Entities::Entidade* ent2)
	{
		coordenadas::vetorfloat interscao = getIntersecao(ent1, ent2);

		if ((interscao.getX() < 0.0f) && (interscao.getY() < 0.0f))
			return true;
		return false;
	}

	bool Gerenciador_colisoes::verifica_colisao_estaticos(Entities::Entidade* pEnt)
	{
		for (int i = 0; i < pEstaticos->getTamanho(); i++)
		{
			//std::cout << pEstaticos->getTamanho() << "\n";
			if (verifica_colisao(pEstaticos->getEntidade(i), pEnt))
			{
				//std::cout << "oie\n";
				return true;
			}
		}
		return false;
	}

	bool Gerenciador_colisoes::verifica_projetil_personagens(Entities::Entidade* pEnt)
	{
		for (int i = 0; i < pPersonagens->getTamanho(); i++)
		{
			if (pEnt != pPersonagens->getEntidade(i))
			{
				if (verifica_colisao(pEnt, pPersonagens->getEntidade(i)))
				{
					static_cast<Entities::Personagem*>(pPersonagens->getEntidade(i))->tomaDano(static_cast<Entities::Projetil*>(pEnt)->getDano());
					//printf("colide\n");
					return true;

				}
			}
		}
		return false;
	}

	coordenadas::vetorfloat Gerenciador_colisoes::getMeioTamanho(Entities::Entidade* ent)
	{
		return ent->getTamanho() / 2;
	}

	coordenadas::vetorfloat Gerenciador_colisoes::getDistancia(Entities::Entidade* body1, Entities::Entidade* body2)
	{
		return coordenadas::vetorfloat(body2->getPos().getX() - body1->getPos().getX(), body2->getPos().getY() - body1->getPos().getY());;
		//return coordenadas::vetorfloat(body2->getPosicao().getX() - body1->getPosicao().getX(), body2->getPosicao().getY() - body1->getPosicao().getY());;
	}

	coordenadas::vetorfloat Gerenciador_colisoes::getIntersecao(Entities::Entidade* body1, Entities::Entidade* body2)
	{
		coordenadas::vetorfloat dist = getDistancia(body1, body2);
		coordenadas::vetorfloat delta(abs(dist.getX()), abs(dist.getY()));
		coordenadas::vetorfloat meiasDistancias(getMeioTamanho(body1) + getMeioTamanho(body2));

		return coordenadas::vetorfloat(delta - meiasDistancias);
	}

	void Gerenciador_colisoes::colidir()//(Lists::ListaEntidades* characters, Lists::ListaEntidades* statics)
	{
		static_cast<Entities::Jogador*>(pPersonagens->getEntidade(0))->setPodePular(false);
		int i, j;
		for (i = 0; i < pPersonagens->getTamanho(); i++)
		{
			for (j = 0; j < pEstaticos->getTamanho(); j++)
			{
				if (verifica_colisao(pPersonagens->getEntidade(i), pEstaticos->getEntidade(j)))
				{
					coordenadas::vetorfloat intersecao = getIntersecao(pPersonagens->getEntidade(i), pEstaticos->getEntidade(j));

					if (abs(intersecao.getX()) < abs(intersecao.getY()))
					{
						if (pPersonagens->getEntidade(i)->getPosicao().getX() < pEstaticos->getEntidade(j)->getPosicao().getX())
							(pPersonagens->getEntidade(i)->Move(coordenadas::vetorfloat(intersecao.getX(), 0.0f)));
						else
							(pPersonagens->getEntidade(i)->Move(coordenadas::vetorfloat(-intersecao.getX(), 0.0f)));
					}
					else
					{
						if (pPersonagens->getEntidade(i)->getPosicao().getY() < pEstaticos->getEntidade(j)->getPosicao().getY())
						{
							(pPersonagens->getEntidade(i)->Move(coordenadas::vetorfloat(0.0f, intersecao.getY())));
							if (i == 0)//se estiver analisando o jogador
							{
								static_cast<Entities::Jogador*>(pPersonagens->getEntidade(i))->setPodePular(true);
							}
						}
						else
						{
							(pPersonagens->getEntidade(i)->Move(coordenadas::vetorfloat(0.0f, -intersecao.getY())));
						}
					}
				}
			}
		}
		//std::cout << static_cast<Entities::Jogador*>(characters->getEntidade(0))->getPodePular() << "\n";
	}

}
