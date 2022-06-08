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

    Entities::Lesma lesma1;
    Entities::Lesma lesma2;
    Entities::Lesma lesma3;
    Entities::Lesma lesma4;
    Entities::Monstro monstro1;
    Entities::Monstro monstro2;
    Entities::Monstro monstro3;
    Entities::Monstro monstro4;
    Entities::Barril barril1;
    Entities::Barril barril2;
    Entities::Barril barril3;
    Entities::Barril barril4;
    Entities::Lago lago1;
    Entities::Lago lago2;
    Entities::Lago lago3;
    Entities::Lago lago4;

    Entities::Plataforma plataforma1;

public:
    PrimeiraFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
    PrimeiraFase();
    ~PrimeiraFase();

    void inicializaFase();
    void executar();
    bool jogoAtivo();
};

