#include "../headers/Menu.h"

Menu::Menu(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* background) :
   
	Ente(pos, pGraf, background),pressionado(false),selecionado(false),cont(0),min(0),max(3) {

    
    

    //começa com o botão superior com a textura selecionada
	Botao* bt = nullptr;                       
    bt = new Botao(coordenadas::vetorfloat(960 / 2, 180),pGraf, "FASE 1","texturas_e_fontes/Default.png");
    bt->seleciona(true);
    vectordeBotoes.push_back(bt);
    
    bt = new Botao(coordenadas::vetorfloat(960 / 2.0f, 180 + 100),pGraf, "FASE 2", "texturas_e_fontes/Default.png");
    vectordeBotoes.push_back(bt);

    bt = new Botao(coordenadas::vetorfloat(960 / 2.0f, 180 + 200),pGraf, "LEADERBOARD", "texturas_e_fontes/Default.png");
    vectordeBotoes.push_back(bt);

    bt = new Botao(coordenadas::vetorfloat(960 / 2.0f, 180 + 300),pGraf, "EXIT GAME", "texturas_e_fontes/Default.png");
    vectordeBotoes.push_back(bt);
    
    bt = new Botao(coordenadas::vetorfloat(960 / 2.0f, 50), pGraf, "JOGO", "texturas_e_fontes/Default.png");
    vectordeBotoes.push_back(bt);

    
    
    sf::Font* fonte;
    titulo.setTextoInfo("NOME");
    titulo.setFontSize(50);
    titulo.setTextColor(77.6, 68.2, 44.3);
    titulo.setAlinhamento(AlinhamentoTexto::centro);
    fonte = pGraf->carregaFonte("texturas_e_fontes/Pixellari.ttf");
    titulo.setFonte(fonte);
    titulo.setPosicao(coordenadas::vetorfloat(300, 100));
    
    executar();
}

Menu::Menu() {
    
}

Menu::~Menu() {

    
    for (int i = 0; i < vectordeBotoes.size(); i++) {

        delete vectordeBotoes[i];
        vectordeBotoes[i] = nullptr;
    }

    vectordeBotoes.clear();
    
}


Botao* Menu::getBotao(int pos)
{
    if (cont > 0 && cont < vectordeBotoes.size()) {

        return vectordeBotoes[pos];
    }
}

void Menu::selecionaCima() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
       
        vectordeBotoes[cont]->seleciona(false);
        cont--;// muda para o botão debaixo

        if (cont < min) {
            cont = max;
        }

        vectordeBotoes[cont]->seleciona(true);
    }
 
}

void Menu::selecionaBaixo() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        vectordeBotoes[cont]->seleciona(false);
        cont++;// muda para o botão debaixo

        if (cont > max) {
                cont = min;
            }

        vectordeBotoes[cont]->seleciona(true);
    }
}
int Menu::seleciona() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (vectordeBotoes[0]->getSelecionado())
        {
            printf("fase 1\n");
            return 0;
        }
        if (vectordeBotoes[1]->getSelecionado())
        {
            printf("fase 2\n");
            return 1;
        }
        if (vectordeBotoes[2]->getSelecionado())
        {
            printf("leaderboard\n");
            return 2;
        }
        if (vectordeBotoes[3]->getSelecionado())
        {
            getAnimacao()->getpGraf()->getJanela()->close();
        }
    }
    return -1;//nada foi selecionado
}

void Menu::executar() {

    //background
    getAnimacao()->render();
    
    //titulo
    vectordeBotoes[4]->render();

    vectordeBotoes[0]->render();
    vectordeBotoes[1]->render();
    vectordeBotoes[2]->render();
    vectordeBotoes[3]->render();

    
}