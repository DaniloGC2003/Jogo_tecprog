#include "../headers/Botao.h"

Botao::Botao(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, std::string info, const char* Pathtexturapadrao) :
    Ente(pos,pGraf,Pathtexturapadrao),
    texturapadrao(nullptr),
    text(pos,pGraf,info),
    texturaselecionada(nullptr) {

    texturapadrao = getAnimacao()->getpGraf()->carregaTextura("C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/assets/Button/Default.png");
    texturaselecionada = getAnimacao()->getpGraf()->carregaTextura("C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/assets/Button/Selected.png");

    getAnimacao()->getCorpo()->setSize(sf::Vector2f(300, 80));
    
    getAnimacao()->getCorpo()->setOrigin(300 / 2, 80 / 2);

    getAnimacao()->getCorpo()->setPosition(sf::Vector2f(pos.getX(), pos.getY()));

   // getAnimacao()->getCorpo()->setTexture(texturapadrao);

    sf::Font* fonte;
    fonte = pGraf->carregaFonte("C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/MainFont.ttf");

    text.setFontSize(30);

    text.setFonte(fonte);

    text.setAlinhamento(AlinhamentoTexto::centro);

    text.setTextColor(77.6, 68.2, 44.3);

    text.setPosicao(coordenadas::vetorfloat(pos.getX(), pos.getY()));

    text.setTextoInfo(info);

}

Botao::~Botao() {

}

void Botao::seleciona(const bool selecionado) {

    if (selecionado)
        getAnimacao()->getCorpo()->setTexture(texturaselecionada);
    else
        getAnimacao()->getCorpo()->setTexture(texturapadrao);
}

void Botao::render() {

    getAnimacao()->render();
    getAnimacao()->getpGraf()->desenhar(text.getText());
}