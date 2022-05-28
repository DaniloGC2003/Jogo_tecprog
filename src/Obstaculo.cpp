#include "../headers/Obstaculo.h"

Entities::Obstaculo::Obstaculo(coordenadas::vetorfloat pos,Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho) :
	Entidade(pos,pGraf,caminho)
{
}

Entities::Obstaculo::Obstaculo()
{
}

Entities::Obstaculo::~Obstaculo()
{
}
