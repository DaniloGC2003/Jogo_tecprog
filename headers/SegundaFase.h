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
    Entities::Agua agua1;
    Entities::Agua agua2;
    Entities::Agua agua3;
    Entities::Agua agua4;
    Entities::Tartaruga tartaruga;

    Entities::Plataforma plataforma1;
    Entities::Plataforma plataforma2;
    Entities::Plataforma plataforma3;

public:
    SegundaFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
    SegundaFase();
    ~SegundaFase();

    void inicializaFase();
    void executar();
    bool jogoAtivo();
};

