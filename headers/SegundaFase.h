#pragma once
#include "Fase.h"
class SegundaFase :
    public Fase
{
private:
    int numLesmas;
    int numMonstros;
    int numBarris;
    int numAguas;

    Entities::Tartaruga* tartaruga;

public:
    SegundaFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
    SegundaFase();
    ~SegundaFase();

    void inicializaFase();
    void executar();
    bool jogoAtivo();
};

