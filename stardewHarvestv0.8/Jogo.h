#pragma once
#include "libUnicornio.h"
#include "Terreno.h"
#include "Interface.h"

enum StatusTela { stMenu, stJogar, stCreditos, stControle, stPause, stCarregar, stSalvar, stSair};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();




protected:

	void inicializarFase();

	void telaMenu();
	void telaPause();
	void telaJogo();
	void telaCreditos();
	void telaControle();

	StatusTela tela;

	Fase faseAtual;

	ifstream arquivo;

	int //lendo do arquivo
		deslocX, deslocY, nJogadas, nObjetivos, nMetas, nFerramentas, tamMatrizX, tamMatrizY, nFasePlanta,
		//criado no jogo
		**pMatriz, posXMatriz, posYMatriz, telaX, telaY, posXMatrizPrimario, posYMatrizPrimario,
		nMusica, *metaObjetivo, nMetasBatidas,
		//aparecem na interface
		nOuro = 0; 

		//modo randomico
		//rand_nFasePlanta, rand_nObjetivos,

	float terrenoPosX, terrenoPosY;

	bool carregar, click, terrenoSeco, terrenoPrimario, musicaCarregada = false, somExecutado = false, *metaContabilizada;

	Terreno **pTerreno, terrenoModelo;

	Interface objInterfaceObjetivos, objInterfaceFerramentas;

	BotaoSprite bJogar, bControle, bCreditos, bSair, bVoltar, bMenu, bRepetir, bProxima, bSalvar, bCarregar, ballon[10];

	Som cursorSom;

	Cursor cursorTipo;

	Sprite fundo, cerca, objetoHUD, interfaceFerramentas, interfaceObjetivos, interfaceFase, cursor, telaFosca;

	Texto fase;
};

