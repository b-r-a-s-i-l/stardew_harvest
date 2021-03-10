#include "Jogo.h"
#include <ctime>
Jogo::Jogo()
{
}

Jogo::~Jogo()
{
	exit(0);
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768 - 20, true);

	srand(time(0));

	//CARREGAMENDO DE IMAGENS

	// fundos

	if (!gRecursos.carregouSpriteSheet("fundo"))
	{
		gRecursos.carregarSpriteSheet("fundo", "img/fundo.png");
	}
	fundo.setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("fundomenu"))
	{
		gRecursos.carregarSpriteSheet("fundomenu", "img/fundomenu.png");
	}

	if (!gRecursos.carregouSpriteSheet("fundocontrole"))
	{
		gRecursos.carregarSpriteSheet("fundocontrole", "img/fundocontrole.png");
	}

	if (!gRecursos.carregouSpriteSheet("telaFosca"))
	{
		gRecursos.carregarSpriteSheet("telaFosca", "img/tela_fosca.png");
	}
	telaFosca.setSpriteSheet("telaFosca");

	// pertencem ao telaMenu();

	if (!gRecursos.carregouSpriteSheet("logo"))
	{
		gRecursos.carregarSpriteSheet("logo", "img/logo.png");
	}
	objetoHUD.setSpriteSheet("logo");


	if (!gRecursos.carregouSpriteSheet("bJogar"))
	{
		gRecursos.carregarSpriteSheet("bJogar", "img/botao_jogar.png", 3);
	}
	bJogar.setSpriteSheet("bJogar");
	bJogar.setPos(312, 420);

	if (!gRecursos.carregouSpriteSheet("bControle"))
	{
		gRecursos.carregarSpriteSheet("bControle", "img/botao_controle.png", 3);
	}
	bControle.setSpriteSheet("bControle");
	bControle.setPos(512, 420);

	if (!gRecursos.carregouSpriteSheet("bCreditos"))
	{
		gRecursos.carregarSpriteSheet("bCreditos", "img/botao_creditos.png", 3);
	}
	bCreditos.setSpriteSheet("bCreditos");

	if (!gRecursos.carregouSpriteSheet("bSair"))
	{
		gRecursos.carregarSpriteSheet("bSair", "img/botao_sair.png", 3);
	}
	bSair.setSpriteSheet("bSair");
	bSair.setPos(512, 600);

	if (!gRecursos.carregouSpriteSheet("bVoltar"))
	{
		gRecursos.carregarSpriteSheet("bVoltar", "img/botao_voltar.png", 3);
	}
	bVoltar.setSpriteSheet("bVoltar");

	if (!gRecursos.carregouSpriteSheet("bMenu"))
	{
		gRecursos.carregarSpriteSheet("bMenu", "img/botao_menu.png", 3);
	}
	bMenu.setSpriteSheet("bMenu");

	if (!gRecursos.carregouSpriteSheet("bSalvar"))
	{
		gRecursos.carregarSpriteSheet("bSalvar", "img/botao_salvar.png", 3);
	}
	bSalvar.setSpriteSheet("bSalvar");

	if (!gRecursos.carregouSpriteSheet("bCarregar"))
	{
		gRecursos.carregarSpriteSheet("bCarregar", "img/botao_carregar.png", 3);
	}
	bCarregar.setSpriteSheet("bCarregar");

	if (!gRecursos.carregouSpriteSheet("bRepetir"))
	{
		gRecursos.carregarSpriteSheet("bRepetir", "img/botao_repetir.png", 3);
	}
	bRepetir.setSpriteSheet("bRepetir");

	if (!gRecursos.carregouSpriteSheet("bProxima"))
	{
		gRecursos.carregarSpriteSheet("bProxima", "img/botao_proxima.png", 3);
	}
	bProxima.setSpriteSheet("bProxima");

	//pertencem ao telaControle();

	if (!gRecursos.carregouSpriteSheet("ballon_!"))
	{
		gRecursos.carregarSpriteSheet("ballon_!", "img/ballon_!.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("ballon_contadores"))
	{
		gRecursos.carregarSpriteSheet("ballon_contadores", "img/ballon_contadores.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_ferramentas"))
	{
		gRecursos.carregarSpriteSheet("ballon_ferramentas", "img/ballon_ferramentas.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_mouse"))
	{
		gRecursos.carregarSpriteSheet("ballon_mouse", "img/ballon_mouse.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_objetivos"))
	{
		gRecursos.carregarSpriteSheet("ballon_objetivos", "img/ballon_objetivos.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_pedra"))
	{
		gRecursos.carregarSpriteSheet("ballon_pedra", "img/ballon_pedra.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_plantaColher"))
	{
		gRecursos.carregarSpriteSheet("ballon_plantaColher", "img/ballon_plantaColher.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_plantaMorta"))
	{
		gRecursos.carregarSpriteSheet("ballon_plantaMorta", "img/ballon_plantaMorta.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_terrenoMolhado"))
	{
		gRecursos.carregarSpriteSheet("ballon_terrenoMolhado", "img/ballon_terrenoMolhado.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_terrenoSeco"))
	{
		gRecursos.carregarSpriteSheet("ballon_terrenoSeco", "img/ballon_terrenoSeco.png");
	}
	if (!gRecursos.carregouSpriteSheet("ballon_tronco"))
	{
		gRecursos.carregarSpriteSheet("ballon_tronco", "img/ballon_tronco.png");
	}

	for (int i = 0; i < 10; i++)
	{
		ballon[i].setSpriteSheet("ballon_!");
	}


	//pertencem ao telaCreditos();

	if (!gRecursos.carregouSpriteSheet("texto_creditos"))
	{
		gRecursos.carregarSpriteSheet("texto_creditos", "img/texto_creditos.png");
	}

	//pertecem ao telaJogo();

	// interface

	if (!gRecursos.carregouSpriteSheet("cerca"))
	{
		gRecursos.carregarSpriteSheet("cerca", "img/cerca.png", 8);
	}
	cerca.setSpriteSheet("cerca");

	if (!gRecursos.carregouSpriteSheet("interface_ferramentas"))
	{
		gRecursos.carregarSpriteSheet("interface_ferramentas", "img/interface_ferramentas.png");
	}
	interfaceFerramentas.setSpriteSheet("interface_ferramentas");

	if (!gRecursos.carregouSpriteSheet("interface_objetivos"))
	{
		gRecursos.carregarSpriteSheet("interface_objetivos", "img/interface_objetivos.png");
	}
	interfaceObjetivos.setSpriteSheet("interface_objetivos");

	if (!gRecursos.carregouSpriteSheet("interface_fase"))
	{
		gRecursos.carregarSpriteSheet("interface_fase", "img/interface_fase.png");
	}
	interfaceFase.setSpriteSheet("interface_fase");

	if (!gRecursos.carregouSpriteSheet("cerca"))
	{
		gRecursos.carregarSpriteSheet("cerca", "img/cerca.png", 8);
	}
	cerca.setSpriteSheet("cerca");

	//HUD

	if (!gRecursos.carregouSpriteSheet("stageClear"))
	{
		gRecursos.carregarSpriteSheet("stageClear", "img/stageClear.png");
	}
	if (!gRecursos.carregouSpriteSheet("stageFailed"))
	{
		gRecursos.carregarSpriteSheet("stageFailed", "img/stageFailed.png");
	}

	//cursor

	if (!gRecursos.carregouSpriteSheet("cursor_regador"))
	{
		gRecursos.carregarSpriteSheet("cursor_regador", "img/cursor_regador.png", 1, 2);
	}
	if (!gRecursos.carregouSpriteSheet("cursor_foice"))
	{
		gRecursos.carregarSpriteSheet("cursor_foice", "img/cursor_foice.png");
	}
	if (!gRecursos.carregouSpriteSheet("cursor_picareta"))
	{
		gRecursos.carregarSpriteSheet("cursor_picareta", "img/cursor_picareta.png");
	}
	if (!gRecursos.carregouSpriteSheet("cursor_machado"))
	{
		gRecursos.carregarSpriteSheet("cursor_machado", "img/cursor_machado.png");
	}
	if (!gRecursos.carregouSpriteSheet("cursor_mao_colher"))
	{
		gRecursos.carregarSpriteSheet("cursor_mao_colher", "img/cursor_mao_colher.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("cursor_mao"))
	{
		gRecursos.carregarSpriteSheet("cursor_mao", "img/cursor_mao.png");
	}
	if (!gRecursos.carregouSpriteSheet("cursor_regador_ativo"))
	{
		gRecursos.carregarSpriteSheet("cursor_regador_ativo", "img/cursor_regador_ativo.png", 1, 4);
	}

	//CARREGAMENDO DE MUSICAS E SONS

	//musicas

	if (!gRecursos.carregouMusica("musicaMenu"))
	{
		gRecursos.carregarMusica("musicaMenu", "music/Stardew Valley - Settling In.mp3", 100.0f);
	}

	if (!gRecursos.carregouMusica("musicaFase1"))
	{
		gRecursos.carregarMusica("musicaFase1", "music/Stardew Valley - Spring (Its a Big World Outside).mp3", 60.0f);
	}

	if (!gRecursos.carregouMusica("musicaFase2"))
	{
		gRecursos.carregarMusica("musicaFase2", "music/Stardew Valley - Spring (The Valley Comes Alive).mp3", 60.0f);
	}

	if (!gRecursos.carregouMusica("musicaFase3"))
	{
		gRecursos.carregarMusica("musicaFase3", "music/Stardew Valley - Spring (Wild Horseradish Jam).mp3", 60.0f);
	}

	if (!gRecursos.carregouAudio("SE-Molhar"))
	{
		gRecursos.carregarAudio("SE-Molhar", "music/SE-Molhar.wav");
	}
	if (!gRecursos.carregouAudio("SE-Cursor_move"))
	{
		gRecursos.carregarAudio("SE-Cursor_move", "music/SE-Cursor_move.wav");
	}
	if (!gRecursos.carregouAudio("SE-Cursor_decide"))
	{
		gRecursos.carregarAudio("SE-Cursor_decide", "music/SE-Cursor_decide.wav");
	}
	if (!gRecursos.carregouAudio("SE-Cursor_foice"))
	{
		gRecursos.carregarAudio("SE-Cursor_foice", "music/SE-Cursor_foice.wav");
	}
	if (!gRecursos.carregouAudio("SE-Cursor_picareta"))
	{
		gRecursos.carregarAudio("SE-Cursor_picareta", "music/SE-Cursor_picareta.wav");
	}

	//TEXTO
	if (!gRecursos.carregouFonte("PressStart2P"))
	{
		gRecursos.carregarFonte("PressStart2P", "PressStart2P.ttf", 15);
	}
	fase.setFonte("PressStart2P");
	fase.setCorVermelho(254); fase.setCorVerde(108); fase.setCorAzul(12);

	//definições

	tela = stMenu;
	click = false;
	terrenoModelo.inicializar();
	terrenoModelo.setPlanta(nabo, semente);
	faseAtual = fase1;
	cursorTipo = regador;
	gMouse.esconderCursor();

}

void Jogo::finalizar()
{

	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (tela != stSair && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (tela)
		{
		case stMenu: telaMenu();
			break;
		case stPause: telaPause();
			break;
		case stJogar: telaJogo();
			break;
		case stCreditos: telaCreditos();
			break;
		case stControle: telaControle();
			break;
		}

		uniTerminarFrame();
	}
}


void Jogo::inicializarFase()
{
	// Abertura do .txt
	switch (faseAtual)
	{
	case fase1:
		arquivo.open("stage/fase_01.txt");
		break;
	case fase2:
		arquivo.open("stage/fase_02.txt");
		break;
	case fase3:
		arquivo.open("stage/fase_03.txt");
		break;
	case fase4:
		arquivo.open("stage/fase_04.txt");
		break;
	case fase5:
		arquivo.open("stage/fase_05.txt");
		break;
	case fase6:
		arquivo.open("stage/fase_06.txt");
		break;
	case fase7:
		arquivo.open("stage/fase_07.txt");
		break;
	case fase8:
		arquivo.open("stage/fase_08.txt");
		break;
	case fase9:
		arquivo.open("stage/fase_09.txt");
		break;
	case fase10:
		arquivo.open("stage/fase_10.txt");
		break;
	}

	if (!arquivo.is_open())
	{
		finalizar();
		exit(0);
	}
	else
	{
		// Definindo valores a variáveis pelo .txt

		arquivo
			>> deslocX >> deslocY
			>> nJogadas >> nObjetivos
			>> nMetas >> nFerramentas
			>> tamMatrizX >> tamMatrizY
			>> nFasePlanta;

		// Setando array de oobjetivos da fase

		metaObjetivo = new int[nObjetivos];
		metaContabilizada = new bool[nObjetivos];

		nMetasBatidas = 0;

		// Alocando a matriz		

		pMatriz = new int*[tamMatrizX]; // Ponteiro int que recebe um novo ponteiro int [] no tamanho "tamMatrizX".
		pTerreno = new Terreno*[tamMatrizX]; //Ponteiro Terreno que recebe um novo ponteiro Terreno [] no tamanho "tamMatrizX".

		for (int c = 0; c < tamMatrizX; c++) // para cada posição do vetor definido acima vai criar um novo vetor no tamanho "tamY"
		{
			pMatriz[c] = new int[tamMatrizY];
			pTerreno[c] = new Terreno[tamMatrizY];

		}
		//Lendo valores do txt para a matriz


		for (int y = 0; y < tamMatrizY; y++)
			for (int x = 0; x < tamMatrizX; x++)
			{
				arquivo >> pMatriz[x][y]; // realiza a leitura do arquivo.txt para cada posição da Matriz
				pTerreno[x][y].inicializar();

				//RANDOMICO
				/*rand_nObjetivos = rand() % nObjetivos;
				pMatriz[x][y] = rand_nObjetivos;
				pTerreno[x][y].inicializar();*/

			}

		for (int y = 0; y < tamMatrizY; y++)
			for (int x = 0; x < tamMatrizX; x++)
			{
				arquivo >> nFasePlanta;
				pTerreno[x][y].setFase(nFasePlanta); // realiza a leitura do arquivo.txt para cada posição da Matriz
				pTerreno[x][y].setPlanta((TipoPlanta)pMatriz[x][y], pTerreno[x][y].getFase());

				//RANDOMICO
				/*rand_nFasePlanta = rand() % nFasePlanta;
				pTerreno[x][y].setFase(rand_nFasePlanta);
				pTerreno[x][y].setPlanta((TipoPlanta)pMatriz[x][y], pTerreno[x][y].getFase());*/

			}

		arquivo.close();

		//leitura dos valores no executar();
		objInterfaceObjetivos.set_faseAtual(faseAtual);
		objInterfaceObjetivos.inicializar();
		objInterfaceFerramentas.set_faseAtual(faseAtual);
		objInterfaceFerramentas.inicializar();

		for (int objeto = 0; objeto < nObjetivos; objeto++)
		{
			metaObjetivo[objeto] = objInterfaceObjetivos.get_metaObjetivo(objeto);
			metaContabilizada[objeto] = false;

		}
	}

	objInterfaceFerramentas.set_nFerramentas(nFerramentas);

	cursorTipo = regador;
	objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
}

void Jogo::telaMenu()
{

	// MUSICA

	if (!musicaCarregada)
	{
		nMusica = 0;

		if (nMusica == 0)
		{
			gMusica.tocar("musicaMenu", false);
		}

		musicaCarregada = true;
	}

	if (!gMusica.estaTocando())
	{
		musicaCarregada = false;
	}

	//Desenhar Fundo
	fundo.setSpriteSheet("fundomenu");
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	objetoHUD.setSpriteSheet("logo");
	objetoHUD.desenhar(555, gJanela.getAltura() / 4);

	bJogar.atualizar();
	bJogar.desenhar();

	if (bJogar.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		inicializarFase();
		tela = stJogar;
		musicaCarregada = false;
	}

	bControle.atualizar();
	bControle.desenhar();
	if (bControle.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		tela = stControle;

	}

	bCarregar.atualizar();
	bCarregar.setPos(712, 420);
	bCarregar.desenhar();
	if (bCarregar.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		//tela = stCarregar;
	}

	bSair.atualizar();
	bSair.desenhar();
	if (bSair.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		tela = stSair;
	}

	if ((bJogar.mouseEntrouEmCima() || bControle.mouseEntrouEmCima() || bCarregar.mouseEntrouEmCima() || bSair.mouseEntrouEmCima()) && somExecutado == false)
	{
		cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

		somExecutado = true;
	}
	if (bJogar.mouseSaiuDeCima() || bControle.mouseSaiuDeCima() || bCarregar.mouseSaiuDeCima() || bSair.mouseEntrouEmCima()) { somExecutado = false; }

	cursor.setSpriteSheet("cursor_mao");

	cursor.desenhar(gMouse.x, gMouse.y);

}

void Jogo::telaPause()
{
	cursor.setSpriteSheet("cursor_mao");

	telaFosca.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bMenu.atualizar();
	bMenu.setPos(gJanela.getLargura() / 2 - 150, gJanela.getAltura() - 200);
	bMenu.desenhar();

	if (bMenu.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		tela = stMenu;

		musicaCarregada = false;
		delete[] pMatriz;
		delete[] metaObjetivo;
		delete[] metaContabilizada;
		delete[] pTerreno;
	}

	bVoltar.atualizar();
	bVoltar.setPos(gJanela.getLargura() / 2 + 150, gJanela.getAltura() - 200);
	bVoltar.desenhar();

	if (bVoltar.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		tela = stJogar;
	}

	if (bMenu.mouseEntrouEmCima() || bVoltar.mouseEntrouEmCima() && somExecutado == false)
	{
		cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

		somExecutado = true;
	}
	if (bMenu.mouseSaiuDeCima() || bVoltar.mouseSaiuDeCima()) { somExecutado = false; }

	cursor.desenhar(gMouse.x, gMouse.y);
}

void Jogo::telaJogo()
{
	//CURSOR
	cursor.setSpriteSheet("cursor_mao");
	objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);

	//MUSICA
	if (!musicaCarregada)
	{

		nMusica = rand() % 3 + 1;

		if (nMusica == 1)
		{
			gMusica.tocar("musicaFase1", false);
		}
		if (nMusica == 2)
		{
			gMusica.tocar("musicaFase2", false);
		}
		if (nMusica == 3)
		{
			gMusica.tocar("musicaFase3", false);
		}

		musicaCarregada = true;

	}

	if (!gMusica.estaTocando())
	{
		musicaCarregada = false;
	}

	// voltar ao telaMenu
	if (gTeclado.pressionou[TECLA_ESC])
	{
		tela = stPause;
	}
	for (int y = 0; y < tamMatrizY; y++)
		for (int x = 0; x < tamMatrizX; x++)
		{
			telaX = deslocX - pTerreno[x][y].getLargura(); // posição da tela eixo X 
			telaY = deslocY - pTerreno[x][y].getAltura(); // posição da tela eixo Y
		}

	//FUNDO
	fundo.setSpriteSheet("fundo");
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);


	//MATRIZ

	for (int y = 0; y < tamMatrizY; y++)
		for (int x = 0; x < tamMatrizX; x++)
		{

			posXMatriz = (gMouse.x - telaX) / pTerreno[x][y].getLargura();
			posYMatriz = (gMouse.y - telaY) / pTerreno[x][y].getAltura();

			terrenoPosX = telaX + pTerreno[x][y].getLargura() / 2 + x * pTerreno[x][y].getLargura();
			terrenoPosY = telaY + pTerreno[x][y].getAltura() / 2 + y * pTerreno[x][y].getAltura();
			// xTela definida ali em cima + posição "X" da matriz multiplicado pela largura do item.
			// yTela definida ali em cima + posição "Y" da matriz multiplicado pela altura do item.

			pTerreno[x][y].atualizar();
			pTerreno[x][y].desenhar(terrenoPosX, terrenoPosY);
			// Desenhando terrenos.

			//CERCAS
			int borderAjust = 10;

			if (x >= 0 && y == 0) // cerca cima
			{
				cerca.setAnimacao(0);
				cerca.desenhar(terrenoPosX, terrenoPosY - cerca.getAltura());
			}
			if (x == 0 && y >= 0) // cerca esquerda
			{
				cerca.setAnimacao(1);
				cerca.desenhar(terrenoPosX - cerca.getLargura(), terrenoPosY - borderAjust);
			}
			if (x == 0 && y == 0) // cerca diag sup esquerda
			{
				cerca.setAnimacao(2);
				cerca.desenhar(terrenoPosX - cerca.getLargura(), terrenoPosY - cerca.getAltura() - borderAjust);
			}
			if (x == 0 && y == tamMatrizY - 1) // cerca diag inf esquerda
			{
				cerca.setAnimacao(3);
				cerca.desenhar(terrenoPosX - cerca.getLargura(), terrenoPosY + cerca.getAltura() - borderAjust);
			}
			if (x >= 0 && y == tamMatrizY - 1) // cerca baixo
			{
				cerca.setAnimacao(4);
				cerca.desenhar(terrenoPosX, terrenoPosY + cerca.getAltura() / 2);
			}
			if (x == tamMatrizX - 1 && y >= 0) // cerca direita
			{
				cerca.setAnimacao(5);
				cerca.desenhar(terrenoPosX + cerca.getLargura(), terrenoPosY - borderAjust);
			}
			if (x == tamMatrizX - 1 && y == 0) // cerca diag sup direita
			{
				cerca.setAnimacao(6);
				cerca.desenhar(terrenoPosX + cerca.getLargura(), terrenoPosY - cerca.getAltura() - borderAjust);
			}
			if (x == tamMatrizX - 1 && y == tamMatrizY - 1) // cerca diag inf direito
			{
				cerca.setAnimacao(7);
				cerca.desenhar(terrenoPosX + cerca.getLargura(), terrenoPosY + cerca.getAltura() - borderAjust);
			}

			// MECÂNICA DA MATRIZ
			if (posXMatriz == x && posYMatriz == y) // certfica a posição do mouse a da matriz.
			{
				// Se regador estiver selecionado
				if (objInterfaceFerramentas.get_FerramentaEmUso() == regador)
				{
					cursor.setSpriteSheet("cursor_regador");
					cursorTipo = regador;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}

				// Se foice estiver selecionado
				if (objInterfaceFerramentas.get_FerramentaEmUso() == foice)
				{
					cursor.setSpriteSheet("cursor_foice");
					cursorTipo = foice;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}

				// Se picareta estiver selecionado
				if (objInterfaceFerramentas.get_FerramentaEmUso() == picareta)
				{
					cursor.setSpriteSheet("cursor_picareta");
					cursorTipo = picareta;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}

				// Se machado estiver selecionado
				if (objInterfaceFerramentas.get_FerramentaEmUso() == machado)
				{
					cursor.setSpriteSheet("cursor_machado");
					cursorTipo = machado;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}

				// Se planta estiver pronta para ser colhida
				if (pTerreno[posXMatriz][posYMatriz].getFase() == maduro && pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true)
				{
					cursor.setSpriteSheet("cursor_mao_colher");
					cursor.avancarAnimacao();
					cursor.setVelocidadeAnimacao(2.0f);
				}

				// Ao precionar o botão esquerdo do mouse com terrenoSeco == true e nJogadas > 0.
				if (gMouse.pressionou[BOTAO_MOUSE_ESQ] && pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true && objInterfaceObjetivos.get_nJogadas() > 0)
				{
					click = true;

					// Se terreno estiver seco e regador selecionado.
					if (pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true && objInterfaceFerramentas.get_FerramentaEmUso() == regador)
						// Se a planta estiver numa fase menor que 'maduro' e o tipo for maior que 'outros'
						if ((pTerreno[posXMatriz][posYMatriz].getFase() < (int)maduro) && (pTerreno[posXMatriz][posYMatriz].getPlanta() >= (int)nabo))
						{
							objInterfaceObjetivos.set_nJogadas(1); // diminui 1 jogada se terrenoseco() == true.

							// aciona o som de efeito Molhar no clique.
							cursorSom.setAudio("SE-Molhar");
							cursorSom.tocar();

							for (int y = 0; y < tamMatrizY; y++)
								for (int x = 0; x < tamMatrizX; x++)
								{
									pTerreno[x][y].setTempoMolhado(); // Contador para deixar o terreno molhado por + 1 turno.
								}
						}

					// Se o terreno estiver seco e planta estiver na fase 'maduro'.
					if (pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true && pTerreno[posXMatriz][posYMatriz].getFase() == maduro)
					{
						cursor.setSpriteSheet("cursor_mao_colher");
						cursorTipo = maoColher;
						objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
						cursor.avancarAnimacao();
						cursor.setVelocidadeAnimacao(2.0f);

						pTerreno[posXMatriz][posYMatriz].regar();

						//Pontuação
						nOuro = pTerreno[posXMatriz][posYMatriz].getOuro();

						// recebe o valor do atributo nOuro de pTerreno[posXMatriz][posYMatriz].
						objInterfaceObjetivos.set_nOuro(nOuro);
						// seta na interface o valor de nOuro de Jogo.cpp

						if (pTerreno[posXMatriz][posYMatriz].getFase() == colhida) // Caso colhida, diminui 1 na missão da planta.
						{
							objInterfaceObjetivos.set_metaObjetivo(pTerreno[posXMatriz][posYMatriz].getPlanta());
						}
					}

					//Cortando erva daninha / planta morta
					if ((pTerreno[posXMatriz][posYMatriz].getPlanta() == outros && pTerreno[posXMatriz][posYMatriz].getFase() == broto) && objInterfaceFerramentas.get_FerramentaEmUso() == foice)
					{
						if (objInterfaceObjetivos.get_nOuro() > 0)
						{
							cursorSom.setAudio("SE-Cursor_foice");
							cursorSom.tocar();
							pTerreno[posXMatriz][posYMatriz].colher();
							//Pontuação
							nOuro = pTerreno[posXMatriz][posYMatriz].getOuro();

							// recebe o valor do atributo nOuro de pTerreno[posXMatriz][posYMatriz].
							objInterfaceObjetivos.set_nOuro(nOuro);
							// seta na interface o valor de nOuro de Jogo.cpp
						}
					}
					//Quebrando a pedra
					if (pTerreno[posXMatriz][posYMatriz].getPlanta() == outros && pTerreno[posXMatriz][posYMatriz].getFase() == verde && objInterfaceFerramentas.get_FerramentaEmUso() == picareta)
					{
						if (objInterfaceObjetivos.get_nOuro() > 0)
						{
							cursorSom.setAudio("SE-Cursor_picareta");
							cursorSom.tocar();
							pTerreno[posXMatriz][posYMatriz].colher();
							//Pontuação
							nOuro = pTerreno[posXMatriz][posYMatriz].getOuro();

							// recebe o valor do atributo nOuro de pTerreno[posXMatriz][posYMatriz].
							objInterfaceObjetivos.set_nOuro(nOuro);
							// seta na interface o valor de nOuro de Jogo.cpp
						}
					}
					//Rachando o tronco
					if (pTerreno[posXMatriz][posYMatriz].getPlanta() == outros && pTerreno[posXMatriz][posYMatriz].getFase() == maduro && objInterfaceFerramentas.get_FerramentaEmUso() == machado)
					{
						if (objInterfaceObjetivos.get_nOuro() > 0)
						{
							cursorSom.setAudio("SE-Cursor_machado");
							cursorSom.tocar();
							pTerreno[posXMatriz][posYMatriz].colher();
							//Pontuação
							nOuro = pTerreno[posXMatriz][posYMatriz].getOuro();

							// recebe o valor do atributo nOuro de pTerreno[posXMatriz][posYMatriz].
							objInterfaceObjetivos.set_nOuro(nOuro);
							// seta na interface o valor de nOuro de Jogo.cpp
						}
					}

				}
				if (gMouse.segurando[BOTAO_MOUSE_ESQ] && click)
				{
					// Se regador selecionado
					if (objInterfaceFerramentas.get_FerramentaEmUso() == regador)
					{
						// Se a planta estiver numa fase menor que 'maduro' e o tipo for maior que 'outros'
						if ((pTerreno[posXMatriz][posYMatriz].getFase() <= (int)maduro) && pTerreno[posXMatriz][posYMatriz].getPlanta() >= (int)nabo)
						{
							cursor.setSpriteSheet("cursor_regador_ativo");
							objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
							cursor.avancarAnimacao();
							cursor.setVelocidadeAnimacao(2.0f);
						}


						if (pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true && terrenoPrimario) // primeiro terreno
							if (pTerreno[posXMatriz][posYMatriz].getFase() <= (int)maduro && pTerreno[posXMatriz][posYMatriz].getPlanta() >= (int)nabo)
							{

								terrenoModelo.getPlantaPrimaria  // armazena as informações de pTerreno[posXMatriz][posYMatriz].
								(pTerreno[posXMatriz][posYMatriz].getPlanta()
									, pTerreno[posXMatriz][posYMatriz].getFase());

								pTerreno[posXMatriz][posYMatriz].regar();

								if (pTerreno[posXMatriz][posYMatriz].getFase() == colhida) // Caso colhida, diminui 1 na missão da planta.
								{
									objInterfaceObjetivos.set_metaObjetivo(pTerreno[posXMatriz][posYMatriz].getPlanta());
								}

								terrenoPrimario = false;
								posXMatrizPrimario = posXMatriz;
								posYMatrizPrimario = posYMatriz;
							}
						if (pTerreno[posXMatriz][posYMatriz].getTerrenoSeco() == true && !terrenoPrimario) // demais terrenos
							if (pTerreno[posXMatriz][posYMatriz].getFase() <= (int)maduro && pTerreno[posXMatriz][posYMatriz].getPlanta() >= (int)nabo)

								// verifica se os dados batem com o primeiro terreno.
								if ((pTerreno[posXMatriz][posYMatriz].getPlanta() == terrenoModelo.getPlanta()) && (pTerreno[posXMatriz][posYMatriz].getFase() == terrenoModelo.getFase()))
									// verifica a posição do terreno vizinho.
									if ((posXMatriz == posXMatrizPrimario + 1 || posXMatriz == posXMatrizPrimario || posXMatriz == posXMatrizPrimario - 1) &&
										(posYMatriz == posYMatrizPrimario + 1 || posYMatriz == posYMatrizPrimario || posYMatriz == posYMatrizPrimario - 1))
									{

										terrenoModelo.getPlantaPrimaria // redefine o terreno vizinho como primario.
										(pTerreno[posXMatriz][posYMatriz].getPlanta(), pTerreno[posXMatriz][posYMatriz].getFase());
										posXMatrizPrimario = posXMatriz;
										posYMatrizPrimario = posYMatriz;

										pTerreno[posXMatriz][posYMatriz].regar();
									}
					}
				}
			}

			if (gMouse.soltou[BOTAO_MOUSE_ESQ])
			{
				click = false;
				terrenoPrimario = true;

				if (objInterfaceFerramentas.get_FerramentaEmUso() == regador)
				{
					cursor.setSpriteSheet("cursor_regador");
					cursorTipo = regador;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}
				if (objInterfaceFerramentas.get_FerramentaEmUso() == maoColher)
				{
					cursor.setSpriteSheet("cursor_regador");
					cursorTipo = regador;
					objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);
				}
			}

		}

	//INTERFACE

	interfaceFase.setSpriteSheet("interface_fase");
	interfaceFase.desenhar(70, 70);
	fase.setString(to_string(faseAtual));
	fase.desenhar(110, 70);

	interfaceObjetivos.setSpriteSheet("interface_objetivos");
	interfaceObjetivos.desenhar(gJanela.getLargura() - 80, gJanela.getAltura() / 3 - 15);

	interfaceFerramentas.setSpriteSheet("interface_ferramentas");
	interfaceFerramentas.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() - 70);

	objInterfaceObjetivos.atualizar();
	objInterfaceObjetivos.desenhar(gJanela.getLargura() - 100, 150);

	objInterfaceFerramentas.atualizar();
	objInterfaceFerramentas.set_FerramentaEmUso(cursorTipo);

	//SELEÇÃO DE FERRAMENTA

	if (gTeclado.pressionou[TECLA_1]) { cursorTipo = regador; }
	if (gTeclado.pressionou[TECLA_2] && nFerramentas >= 2) { cursorTipo = foice; }
	if (gTeclado.pressionou[TECLA_3] && nFerramentas >= 3) { cursorTipo = picareta; }
	if (gTeclado.pressionou[TECLA_4] && nFerramentas == 4) { cursorTipo = machado; }

	//VITORIA-DERROTA

	// Verificando
	for (int objeto = 0; objeto < nObjetivos; objeto++)
	{
		if (objInterfaceObjetivos.get_metaObjetivo(objeto) == 0 && metaContabilizada[objeto] == false) { metaContabilizada[objeto] = true; nMetasBatidas++; }
	}

	//Vencedor
	if (nMetasBatidas == nObjetivos)
	{
		telaFosca.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		objetoHUD.setSpriteSheet("stageClear");
		objetoHUD.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);


		bProxima.atualizar();
		bProxima.setPos(gJanela.getLargura() / 2 - 150, gJanela.getAltura() - 200);
		bProxima.desenhar();

		if (bProxima.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();
			switch (faseAtual)
			{
			case fase1:
				faseAtual = fase2;
				break;
			case fase2:
				faseAtual = fase3;
				break;
			case fase3:
				faseAtual = fase4;
				break;
			case fase4:
				faseAtual = fase5;
				break;
			case fase5:
				faseAtual = fase6;
				break;
			case fase6:
				faseAtual = fase7;
				break;
			case fase7:
				faseAtual = fase8;
				break;
			case fase8:
				faseAtual = fase9;
				break;
			case fase9:
				faseAtual = fase10;
				break;
			case fase10:
				//termina
				break;
			}
			musicaCarregada = false;

			delete[] pMatriz;
			delete[] metaObjetivo;
			delete[] metaContabilizada;
			delete[] pTerreno;

			objInterfaceObjetivos.deletar();
			objInterfaceFerramentas.deletar();

			inicializarFase();
		}

		bMenu.atualizar();
		bMenu.setPos(gJanela.getLargura() / 2, gJanela.getAltura() - 200);
		bMenu.desenhar();

		if (bMenu.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();

			musicaCarregada = false;

			delete[] pMatriz;
			delete[] metaObjetivo;
			delete[] metaContabilizada;
			delete[] pTerreno;

			tela = stMenu;
		}

		bSalvar.atualizar();
		bSalvar.setPos(gJanela.getLargura() / 2 + 150, gJanela.getAltura() - 200);
		bSalvar.desenhar();

		if (bSalvar.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();
			//tela = stSalvar;
		}

		if (bProxima.mouseEntrouEmCima() || bMenu.mouseEntrouEmCima() || bSalvar.mouseEntrouEmCima() && somExecutado == false)
		{
			cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

			somExecutado = true;
		}
		if (bProxima.mouseSaiuDeCima() || bMenu.mouseSaiuDeCima() || bSalvar.mouseSaiuDeCima()) { somExecutado = false; }
	}

	//Perdedor
	if (objInterfaceObjetivos.get_nJogadas() == 0 && nMetasBatidas < nObjetivos)
	{
		telaFosca.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		objetoHUD.setSpriteSheet("stageFailed");
		objetoHUD.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		bRepetir.atualizar();
		bRepetir.setPos(gJanela.getLargura() / 2 - 150, gJanela.getAltura() - 200);
		bRepetir.desenhar();

		if (bRepetir.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();

			musicaCarregada = false;

			delete[] pMatriz;
			delete[] metaObjetivo;
			delete[] metaContabilizada;
			delete[] pTerreno;

			inicializarFase();
		}

		bMenu.atualizar();
		bMenu.setPos(gJanela.getLargura() / 2, gJanela.getAltura() - 200);
		bMenu.desenhar();

		if (bMenu.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();

			musicaCarregada = false;

			delete[] pMatriz;
			delete[] metaObjetivo;
			delete[] metaContabilizada;
			delete[] pTerreno;

			tela = stMenu;
		}

		bCarregar.atualizar();
		bCarregar.setPos(gJanela.getLargura() / 2 + 150, gJanela.getAltura() - 200);
		bCarregar.desenhar();

		if (bCarregar.estaClicado())
		{
			cursorSom.setAudio("SE-Cursor_decide");
			cursorSom.tocar();
			//tela = stCarregar;
		}

		if (bRepetir.mouseEntrouEmCima() || bMenu.mouseEntrouEmCima() || bCarregar.mouseEntrouEmCima() && somExecutado == false)
		{
			cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

			somExecutado = true;
		}
		if (bRepetir.mouseSaiuDeCima() || bMenu.mouseSaiuDeCima() || bCarregar.mouseSaiuDeCima()) { somExecutado = false; }

	}

	cursor.desenhar(gMouse.x, gMouse.y);
}

void Jogo::telaCreditos()
{
	// MUSICA

	if (!musicaCarregada)
	{
		nMusica = 0;

		if (nMusica == 0)
		{
			gMusica.tocar("musicaMenu", false);
		}

		musicaCarregada = true;
	}

	if (!gMusica.estaTocando())
	{
		musicaCarregada = false;
	}

	//Desenhar Fundo
	fundo.setSpriteSheet("fundomenu");
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	objetoHUD.setSpriteSheet("texto_creditos");
	objetoHUD.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bVoltar.atualizar();
	bVoltar.setPos(512, 600);
	bVoltar.desenhar();

	if (bVoltar.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		inicializarFase();
		tela = stMenu;
		musicaCarregada = false;
	}

	if (bVoltar.mouseEntrouEmCima() && somExecutado == false)
	{
		cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

		somExecutado = true;
	}
	if (bVoltar.mouseSaiuDeCima()) { somExecutado = false; }

	cursor.setSpriteSheet("cursor_mao");

	cursor.desenhar(gMouse.x, gMouse.y);
}

void Jogo::telaControle()
{
	// MUSICA

	if (!musicaCarregada)
	{
		nMusica = 3;

		if (nMusica == 3)
		{
			gMusica.tocar("musicaFase3", false);
		}

		musicaCarregada = true;
	}

	if (!gMusica.estaTocando())
	{
		musicaCarregada = false;
	}

	//Desenhar Fundo
	fundo.setSpriteSheet("fundocontrole");
	fundo.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	// interface objetivos
	if (ballon[0].estaComMouseEmCima())
	{
		ballon[0].setSpriteSheet("ballon_objetivos");
		ballon[0].setPos(916 - 300, 228 - 33);
		ballon[7].setPos(-100, -100);
		ballon[8].setPos(-100, -100);
	}
	else
	{
		ballon[0].setSpriteSheet("ballon_!");
		ballon[0].setPos(916 - 46, 228 - 33);
		ballon[7].setPos(448, 140);
		ballon[8].setPos(503 - 50, 302 - 33);
	}

	// interface ferramentas
	if (ballon[1].estaComMouseEmCima())
	{
		ballon[1].setSpriteSheet("ballon_ferramentas");
		ballon[1].setPos(594 - 40, 646 - 87);
	}
	else
	{
		ballon[1].setSpriteSheet("ballon_!");
		ballon[1].setPos(594 - 46, 646 - 33);
	}

	// interface ouro / jogada
	if (ballon[2].estaComMouseEmCima())
	{
		ballon[2].setSpriteSheet("ballon_contadores");
		ballon[2].setPos(384 - 70, 648 - 87);
	}
	else
	{
		ballon[2].setSpriteSheet("ballon_!");
		ballon[2].setPos(384 - 46, 648 - 33);
	}

	// planta morta
	if (ballon[3].estaComMouseEmCima())
	{
		ballon[3].setSpriteSheet("ballon_plantaMorta");
		ballon[3].setPos(126, 148);
	}
	else
	{
		ballon[3].setSpriteSheet("ballon_!");
		ballon[3].setPos(170 - 50, 220 - 33);
	}

	// pedra
	if (ballon[4].estaComMouseEmCima())
	{
		ballon[4].setSpriteSheet("ballon_pedra");
		ballon[4].setPos(230 - 50, 410);
	}
	else
	{
		ballon[4].setSpriteSheet("ballon_!");
		ballon[4].setPos(230 - 50, 340);
	}

	// pedra
	if (ballon[5].estaComMouseEmCima())
	{
		ballon[5].setSpriteSheet("ballon_tronco");
		ballon[5].setPos(395, 410);
	}
	else
	{
		ballon[5].setSpriteSheet("ballon_!");
		ballon[5].setPos(367 - 50, 337);
	}

	// planta para colher
	if (ballon[6].estaComMouseEmCima())
	{
		ballon[6].setSpriteSheet("ballon_plantaColher");
		ballon[6].setPos(320, 75);
	}
	else
	{
		ballon[6].setSpriteSheet("ballon_!");
		ballon[6].setPos(295 - 50, 150 - 33);
	}

	// terreno seco
	if (ballon[7].estaComMouseEmCima())
	{
		ballon[7].setSpriteSheet("ballon_terrenoSeco");
		ballon[7].setPos(680, 120);
	}
	else
	{
		ballon[7].setSpriteSheet("ballon_!");
		//ballon[7].setPos(448, 140);
	}

	// terreno molhado
	if (ballon[8].estaComMouseEmCima())
	{
		ballon[8].setSpriteSheet("ballon_terrenoMolhado");
		ballon[8].setPos(680, 277);
	}
	else
	{
		ballon[8].setSpriteSheet("ballon_!");
		//ballon[8].setPos(503 - 50, 302 - 33);
	}

	// interface mouse
	if (ballon[9].estaComMouseEmCima())
	{
		ballon[9].setSpriteSheet("ballon_mouse");
		ballon[9].setPos(945 - 48, 550);
	}
	else
	{
		ballon[9].setSpriteSheet("ballon_!");
		ballon[9].setPos(945 - 48, 691 - 33);
	}

	for (int i = 0; i < 10; i++)
	{
		ballon[i].atualizar();
		ballon[i].desenhar();
	}

	bVoltar.atualizar();
	bVoltar.setPos(70, gJanela.getAltura() - 70);
	bVoltar.desenhar();

	if (bVoltar.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		inicializarFase();
		tela = stMenu;
		musicaCarregada = false;
	}

	bCreditos.atualizar();
	bCreditos.setPos(200, gJanela.getAltura() - 70);
	bCreditos.desenhar();
	if (bCreditos.estaClicado())
	{
		cursorSom.setAudio("SE-Cursor_decide");
		cursorSom.tocar();
		tela = stCreditos;
	}

	if (bVoltar.mouseEntrouEmCima() || bCreditos.mouseEntrouEmCima() && somExecutado == false)
	{
		cursorSom.setAudio("SE-Cursor_move"); cursorSom.tocar();

		somExecutado = true;
	}
	if (bVoltar.mouseSaiuDeCima() || bCreditos.mouseSaiuDeCima()) { somExecutado = false; }

	cursor.setSpriteSheet("cursor_mao");

	cursor.setSpriteSheet("cursor_mao");

	cursor.desenhar(gMouse.x, gMouse.y);

}

