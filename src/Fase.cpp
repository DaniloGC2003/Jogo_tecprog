#include "../headers/Fase.h"
namespace Fases
{
	Fase::Fase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho)
		: Entities::Ente(pos, pGraf, caminho), Colisoes(&personagens, &estaticas, &projeteis),
		camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(960.f, 540.f)), personagens(), estaticas(), projeteis(),
		jogador(new Entities::Personagens::Jogador(coordenadas::vetorfloat(50.f, 110.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Woodcutter.png")),
		HP(coordenadas::vetorfloat(0.f, 0.f), getAnimacao()->getpGraf(), "HP: ", "texturas_e_fontes/Pixellari.ttf")
	{

		sf::Font* fonte;
		fonte = pGraf->carregaFonte("texturas_e_fontes/Pixellari.ttf");

		HP.setFontSize(30);

		HP.setFonte(fonte);

		HP.setAlinhamento(AlinhamentoTexto::centro);

		HP.setTextColor(77.6, 68.2, 44.3);

		HP.setPosicao(coordenadas::vetorfloat(pos.getX(), pos.getY()));

		getAnimacao()->mudaEscala(500.f, 500.f);

		personagens.pushEntidade(jogador);

		/*Entities::Plataforma* pP;
		pP = new Plataforma(coordenadas::vetorfloat(1000.f, 300.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png");
		pP->getAnimacao()->mudaEscala(200.f, 1.f);
		estaticas.pushEntidade(pP);*/
	}

	Fase::Fase() : Entities::Ente(), Colisoes(), camera(), personagens(), estaticas(), projeteis(), jogador(nullptr)
	{
	}

	Fase::~Fase()
	{
		jogador = nullptr;
	}

	void Fase::mostraVidaJogador()
	{
		char vidajogador[10];
		char hp[15] = "HP: ";
		_itoa_s(jogador->getVida(), vidajogador, 10);
		HP.setPosicao(coordenadas::vetorfloat(jogador->getPos().getX() - 250, jogador->getPos().getY() - 250));
		strcat_s(hp, vidajogador);
		HP.setTextoInfo(hp);
		HP.render();
	}


}
