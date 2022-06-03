#include "../headers/Entidade.h"

namespace Entities
{

    Entidade::Entidade(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, Gerenciadores::Gerenciador_colisoes* pGC, const char* pathImagem) 
        : Ente(pos, pGraf, pathImagem), pColisoes(pGC)
    {
    }

    Entidade::Entidade() : Ente(), pColisoes(nullptr)
    {
    }

    Entidade::~Entidade() {
    }

    void Entidade::mudarPosicao(coordenadas::vetorfloat pos) {
        mudarPos(pos);
    }

    coordenadas::vetorfloat Entidade::getPosicao() const {
        return getPos();
    }

    void Entidade::executar()
    {
        getAnimacao()->render();
    }

    void Entidade::Move(coordenadas::vetorfloat vec) {
        MoveCorpo(vec);
    }

}
