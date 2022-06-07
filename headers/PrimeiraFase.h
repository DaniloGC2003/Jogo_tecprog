#pragma once
#include "Fase.h"
class PrimeiraFase :
    public Fase
{
private:
    int numLesmas;
    int numMonstros;
    int numBarris;
    int numLagos;
    Entities::Lesma lesma;
public:
    PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
    PrimeiraFase();
    ~PrimeiraFase();

    void executar();
};

