#include "../headers/Fase.h"

Fase::Fase(coordenadas::vetorfloat pos, Gerenciadores::Gerenciador_grafico* pGraf, const char* caminho)
	: Entities::Ente(pos, pGraf, caminho), Colisoes(&personagens, &estaticas, &projeteis),
	camera(sf::Vector2f(0.f, 0.f), sf::Vector2f(960.f, 540.f)), personagens(), estaticas(), projeteis(),
	jogador(coordenadas::vetorfloat(50.f, 110.f), getAnimacao()->getpGraf(), &Colisoes, "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/Woodcutter.png"),
	plataforma(coordenadas::vetorfloat(1000.f, 300.f), getAnimacao()->getpGraf(), &Colisoes, "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/preview.png"),
	HP(coordenadas::vetorfloat(0.f, 0.f), getAnimacao()->getpGraf(), "HP: ", "C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/Pixellari.ttf")
{
	/*sf::Font* fonte;
	HP.setTextoInfo("NOME");
	HP.setFontSize(50);
	HP.setTextColor(77.6, 68.2, 44.3);
	HP.setAlinhamento(AlinhamentoTexto::centro);
	fonte = pGraf->carregaFonte("texturas_e_fontes/Pixellari.ttf");
	HP.setFonte(fonte);
	HP.setPosicao(coordenadas::vetorfloat(300, 100));*/

	sf::Font* fonte;
	fonte = pGraf->carregaFonte("C:/Users/eduar/Documents/Técnicas de Programação/Jogo_Tec_Prog/github_jogo/texturas_e_fontes/Pixellari.ttf");

	HP.setFontSize(30);

	HP.setFonte(fonte);

	HP.setAlinhamento(AlinhamentoTexto::centro);

	HP.setTextColor(77.6, 68.2, 44.3);

	HP.setPosicao(coordenadas::vetorfloat(pos.getX(), pos.getY()));

	getAnimacao()->mudaEscala(500.f, 500.f);

	personagens.pushEntidade(&jogador);

	plataforma.getAnimacao()->mudaEscala(200.f, 1.f);
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

void Fase::mostraVidaJogador()
{
	char vidajogador[10];
	char hp[15] = "HP: ";
	_itoa_s(jogador.getVida(), vidajogador, 10);
	HP.setPosicao(coordenadas::vetorfloat(jogador.getPos().getX() - 250, jogador.getPos().getY() - 250));
	strcat_s(hp, vidajogador);
	HP.setTextoInfo(hp);
	HP.render();
}

