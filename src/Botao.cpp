#include "../headers/Botao.h"

Botao::Botao(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, std::string info, const char* Pathtexturapadrao) :
    Ente(pos,pGraf,Pathtexturapadrao),
    texturapadrao(nullptr),
    text(pos,pGraf,info),
    texturaselecionada(nullptr),
    selecionado(false) {

    texturapadrao = getAnimacao()->getpGraf()->carregaTextura("texturas_e_fontes/Default.png");
    texturaselecionada = getAnimacao()->getpGraf()->carregaTextura("texturas_e_fontes/Selected.png");

    getAnimacao()->getCorpo()->setSize(sf::Vector2f(300, 80));
    
    getAnimacao()->getCorpo()->setOrigin(300 / 2, 80 / 2);

    getAnimacao()->getCorpo()->setPosition(sf::Vector2f(pos.getX(), pos.getY()));

    sf::Font* fonte;
    fonte = pGraf->carregaFonte("texturas_e_fontes/Pixellari.ttf");

    text.setFontSize(30);

    text.setFonte(fonte);

    text.setAlinhamento(AlinhamentoTexto::centro);

    text.setTextColor(77.6, 68.2, 44.3);

    text.setPosicao(coordenadas::vetorfloat(pos.getX(), pos.getY()));

    text.setTextoInfo(info);

}

Botao::~Botao() {
    texturapadrao = nullptr;
    texturaselecionada = nullptr;
}

void Botao::seleciona(const bool selecionado) {

    if (selecionado)
    {
        getAnimacao()->getCorpo()->setTexture(texturaselecionada);
        this->selecionado = true;
    }
    else
    {
        getAnimacao()->getCorpo()->setTexture(texturapadrao);
        this->selecionado = false;
    }
}

void Botao::render() {

    getAnimacao()->render();
    getAnimacao()->getpGraf()->desenhar(text.getText());
}