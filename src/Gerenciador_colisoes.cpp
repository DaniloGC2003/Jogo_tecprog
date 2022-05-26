#include "../headers/Gerenciador_colisoes.h"

Gerenciador_colisoes::Gerenciador_colisoes()
{

}

Gerenciador_colisoes::~Gerenciador_colisoes()
{

}

bool Gerenciador_colisoes::verifica_colisao(Entities::Entidade* ent1, Entities::Entidade* ent2)
{
	coordenadas::vetorfloat interscao = getIntersecao(ent1, ent2);

	if ((interscao.getX() < 0.0f) && (interscao.getY() < 0.0f))
		return true;
	return false;
}

coordenadas::vetorfloat Gerenciador_colisoes::getMeioTamanho(Entities::Entidade* ent)
{
	return ent->getTamanho() / 2;
}

coordenadas::vetorfloat Gerenciador_colisoes::getDistancia(Entities::Entidade* body1, Entities::Entidade* body2)
{
	return coordenadas::vetorfloat(body2->getPosicao().getX() - body1->getPosicao().getX(), body2->getPosicao().getY() - body1->getPosicao().getY());;
}

coordenadas::vetorfloat Gerenciador_colisoes::getIntersecao(Entities::Entidade* body1, Entities::Entidade* body2)
{
	coordenadas::vetorfloat dist = getDistancia(body1, body2);
	coordenadas::vetorfloat delta(abs(dist.getX()), abs(dist.getY()));
	coordenadas::vetorfloat meiasDistancias(getMeioTamanho(body1) + getMeioTamanho(body2));

	return coordenadas::vetorfloat(delta - meiasDistancias);
}

void Gerenciador_colisoes::colidir(ListaEntidades* characters, ListaEntidades* statics)
{
	int i, j;
	for (i = 0; i < characters->getTamanho(); i++)
	{
		for (j = 0; j < statics->getTamanho(); j++)
		{
			if (verifica_colisao(characters->getEntidade(i), statics->getEntidade(j)))
			{
				coordenadas::vetorfloat intersecao = getIntersecao(characters->getEntidade(i), statics->getEntidade(j));

				if (abs(intersecao.getX()) < abs(intersecao.getY()))
				{
					if (characters->getEntidade(i)->getPosicao().getX() < statics->getEntidade(j)->getPosicao().getX())
						(characters->getEntidade(i)->Move(coordenadas::vetorfloat(intersecao.getX(), 0.0f)));
					else
						(characters->getEntidade(i)->Move(coordenadas::vetorfloat(-intersecao.getX(), 0.0f)));
				}
				else
				{
					if (characters->getEntidade(i)->getPosicao().getY() < statics->getEntidade(j)->getPosicao().getY())
						(characters->getEntidade(i)->Move(coordenadas::vetorfloat(0.0f, intersecao.getY())));
					else
						(characters->getEntidade(i)->Move(coordenadas::vetorfloat(0.0f, -intersecao.getY())));
				}
			}
		}
	}
}
