#pragma once
#include "Fase.h"
namespace Fases
{
    class SegundaFase :
        public Fase
    {
    private:
        int numLesmas;
        int numMonstros;
        int numBarris;
        int numAguas;

        Entities::Personagens::Tartaruga* tartaruga;

    public:
        SegundaFase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho);
        SegundaFase();
        ~SegundaFase();

        void inicializaFase();
        void executar();
        bool jogoAtivo();
    };


}
