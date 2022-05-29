#include "../headers/Lago.h"

Entities::Lago::Lago(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho):
	Obstaculo(pos,pGraf,caminho)
{
}

Entities::Lago::Lago()
{
}

Entities::Lago::~Lago()
{
}
