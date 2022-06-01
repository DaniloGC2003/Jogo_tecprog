#include "../headers/Obstaculo.h"

Entities::Obstaculo::Obstaculo(coordenadas::vetorfloat pos,Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho) :
	Entidade(pos, pGraf, pGC, caminho)
{
}

Entities::Obstaculo::Obstaculo() : Entidade()
{
}

Entities::Obstaculo::~Obstaculo()
{
}
