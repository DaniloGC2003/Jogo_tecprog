#include "../headers/Fase.h"

Fase::Fase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho)
	: Entities::Ente(pos, pGraf, caminho), Colisoes(&personagens, &estaticas, &projeteis),
	camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(960.f, 540.f)), personagens(), estaticas(), projeteis(),
	jogador(coordenadas::vetorfloat(50.f, 110.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/Woodcutter.png"),
	plataforma(coordenadas::vetorfloat(300.f, 300.f), getAnimacao()->getpGraf(), &Colisoes, "texturas_e_fontes/preview.png")
	//HP(coordenadas::vetorfloat(0.f, 0.f), getAnimacao()->getpGraf(), "HP: ", "texturas_e_fontes/Pixellari.ttf")
{
	/*sf::Font* fonte;
	HP.setTextoInfo("NOME");
	HP.setFontSize(50);
	HP.setTextColor(77.6, 68.2, 44.3);
	HP.setAlinhamento(AlinhamentoTexto::centro);
	fonte = pGraf->carregaFonte("texturas_e_fontes/Pixellari.ttf");
	HP.setFonte(fonte);
	HP.setPosicao(coordenadas::vetorfloat(300, 100));*/

	getAnimacao()->mudaEscala(500.f, 500.f);

	personagens.pushEntidade(&jogador);

	plataforma.getAnimacao()->mudaEscala(50.f, 1.f);
	estaticas.pushEntidade(&plataforma);
}

Fase::Fase() : Entities::Ente()
{
}

Fase::~Fase()
{
	while (personagens.getTamanho() > 0)
	{
		personagens.deleteEntidade(personagens.getEntidade(personagens.getTamanho() - 1));
	}
	while (estaticas.getTamanho() > 0)
	{
		estaticas.deleteEntidade(estaticas.getEntidade(estaticas.getTamanho() - 1));
	}
}
