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



public:
    PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
    PrimeiraFase();
    ~PrimeiraFase();

    void inicializaFase();
    void executar();
    bool jogoAtivo();
};

