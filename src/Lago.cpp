#include "../headers/Lago.h"

Entities::Lago::Lago(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* caminho):
	Obstaculo(pos,pGraf,pGC,caminho)
{
}

Entities::Lago::Lago()
{
}

Entities::Lago::~Lago()
{
}
