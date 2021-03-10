#include "Interface.h"



Interface::Interface()
{
}


Interface::~Interface()
{
}

void Interface::inicializar()
{
	lerFase();

	if (!gRecursos.carregouFonte("Paintdrips"))
	{
		gRecursos.carregarFonte("Paintdrips", "Paintdrips.ttf", 15);
	}
	if (!gRecursos.carregouFonte("PressStart2P"))
	{
		gRecursos.carregarFonte("PressStart2P", "PressStart2P.ttf", 15);
	}

	if (!gRecursos.carregouSpriteSheet("itens_objetivos"))
	{
		gRecursos.carregarSpriteSheet("itens_objetivos", "img/itens_objetivos.png", 4);
	}

	if (!gRecursos.carregouSpriteSheet("itens_ferramentas"))
	{
		gRecursos.carregarSpriteSheet("itens_ferramentas", "img/itens_ferramentas.png", 4);
	}
	if (!gRecursos.carregouSpriteSheet("g_item"))
	{
		gRecursos.carregarSpriteSheet("g_item", "img/interface_ferramentas_Gitem.png");
	}
	if (!gRecursos.carregouSpriteSheet("selection_ferramenta"))
	{
		gRecursos.carregarSpriteSheet("selection_ferramenta", "img/selection_ferramenta.png");
	}
	selecFerramenta.setSpriteSheet("selection_ferramenta");

	if (!gRecursos.carregouAudio("SE-Objetivo"))
	{
		gRecursos.carregarAudio("SE-Objetivo", "music/SE-Objetivo.wav");
	}
	

	objetivo = new int[nObjetivos];
	metaObjetivo = new int[nObjetivos];
	spriteObjetivo = new Sprite[nObjetivos];
	valorObjetivo = new Texto[nObjetivos];
	spriteFerramenta = new Sprite[nFerramentas];
	spriteGItem = new Sprite[nFerramentas];
	custoFerramenta = new int[nFerramentas];
	valorFerramenta = new Texto[nFerramentas];
		

	for (int objetivo = 0; objetivo < nObjetivos; objetivo++)
	{
		randMeta = rand() % nMetas + 1;

		metaObjetivo[objetivo] = randMeta;
	}

	for (int objeto = 0; objeto < nObjetivos; objeto++)
	{
		spriteObjetivo[objeto].setSpriteSheet("itens_objetivos");

		valorObjetivo[objeto].setFonte("PressStart2P");
		valorObjetivo[objeto].setCorVermelho(254); valorObjetivo[objeto].setCorVerde(108); valorObjetivo[objeto].setCorAzul(12);
		valorObjetivo[objeto].setString(to_string(get_metaObjetivo(objeto)));
		

		if (get_metaObjetivo(objeto) == 0)
		{
			somObjetivo.setAudio("SE-Objetivo");
			somObjetivo.tocar();
			valorObjetivo[objeto].setString("ok!");
		}
	}

	valorOuro.setFonte("PressStart2P");
	valorOuro.setCorVermelho(254); valorOuro.setCorVerde(108); valorOuro.setCorAzul(12);
	valorOuro.setString(to_string(nOuro));

	valorJogadas.setFonte("PressStart2P");
	valorJogadas.setCorVermelho(254); valorJogadas.setCorVerde(108); valorJogadas.setCorAzul(12);
	valorJogadas.setString(to_string(nJogadas));

	for (int ferramenta = 0; ferramenta < nFerramentas; ferramenta++)
	{
		spriteFerramenta[ferramenta].setSpriteSheet("itens_ferramentas");
		spriteFerramenta[ferramenta].setAnimacao(ferramenta);

		spriteGItem[ferramenta].setSpriteSheet("g_item");

		valorFerramenta[ferramenta].setFonte("PressStart2P");
		valorFerramenta[ferramenta].setCorVermelho(254); valorFerramenta[ferramenta].setCorVerde(108); valorFerramenta[ferramenta].setCorAzul(12);

		

		if (ferramenta == 0)
		{
			custoFerramenta[ferramenta] = 0;
			valorFerramenta[ferramenta].setString("-");
		}
		if (ferramenta > 0)
		{
			custoFerramenta[ferramenta] = 10 * (ferramenta + 1);
			valorFerramenta[ferramenta].setString(to_string(custoFerramenta[ferramenta]));
		}
	}
}

void Interface::atualizar()
{
	selecFerramenta.setSpriteSheet("selection_ferramenta");

	for (int objeto = 0; objeto < nObjetivos; objeto++)
	{
		valorObjetivo[objeto].setString(to_string(get_metaObjetivo(objeto)));
		if (get_metaObjetivo(objeto) < 0) metaObjetivo[objeto] = 0;

		if (get_metaObjetivo(objeto) == 0)
		{
			somObjetivo.setAudio("SE-Objetivo");
			somObjetivo.tocar();
			valorObjetivo[objeto].setString("ok!");
		}

		spriteObjetivo[objeto].setAnimacao(objeto);
	}

	if (nOuro < 0) { nOuro = 0; }
	valorOuro.setString(to_string(nOuro));
	if (nJogadas < 0) { nJogadas = 0; }
	valorJogadas.setString(to_string(nJogadas));
}

void Interface::desenhar(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;

	for (int objeto = 0; objeto < nObjetivos; objeto++)
	{
		spriteObjetivo[objeto].desenhar(posX, posY * (objeto + 1));
		valorObjetivo[objeto].desenhar(posX + 50, posY * (objeto + 1));
	}

	valorOuro.desenhar(gJanela.getLargura() / 2 - 172, gJanela.getAltura() - 40);
	valorJogadas.desenhar(gJanela.getLargura() / 2 - 108, gJanela.getAltura() - 40);


	for (int ferramenta = 0; ferramenta < nFerramentas; ferramenta++)
	{
		spriteFerramenta[ferramenta].desenhar(gJanela.getLargura() / 2 - 90 + ((spriteFerramenta[ferramenta].getLargura() + 20) * (ferramenta + 1)), gJanela.getAltura() - 80);
		valorFerramenta[ferramenta].desenhar(gJanela.getLargura() / 2 - 90  + ((spriteFerramenta[ferramenta].getLargura() + 20) * (ferramenta + 1)), gJanela.getAltura() - 40);

		if (ferramenta > 0)
		{
			spriteGItem[ferramenta].desenhar(gJanela.getLargura() / 2 - 120 + ((spriteFerramenta[ferramenta].getLargura() + 20) * (ferramenta + 1)), gJanela.getAltura() - 40);
		}
		
	}

}

void Interface::deletar()
{
	delete[]	objetivo;
	delete[]	metaObjetivo;
	delete[]	spriteObjetivo;
	delete[]	spriteFerramenta;
	delete[]	valorObjetivo;
	delete[]	valorFerramenta;
}

void Interface::lerFase()
{

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
	arquivo
		>> nJogadas >> nJogadas >> nJogadas >> nObjetivos >> nMetas >> nFerramentas;
	arquivo.close();
}

void Interface::set_nJogadas(int jogada)
{
	get_nJogadas();

	nJogadas -= jogada;
}

void Interface::set_nOuro(int pontos)
{
	get_nOuro();

	nOuro += pontos;
}

void Interface::set_metaObjetivo(int nObjetivo)
{
	metaObjetivo[nObjetivo] = metaObjetivo[nObjetivo]--;
}

int Interface::get_SprFerramenta_largura(int ferramenta)
{

	ferramenta = spriteFerramenta[ferramenta].getLargura();

	return ferramenta;
}

int Interface::get_SprFerramenta_altura(int ferramenta)
{

	ferramenta = spriteFerramenta[ferramenta].getAltura();

	return ferramenta;
}

void Interface::set_FerramentaEmUso(Cursor ferramenta)
{
	if (ferramenta < nFerramentas)
	{
		selecFerramenta.desenhar(gJanela.getLargura() / 2 - 90 + ((selecFerramenta.getLargura() + 20) * (ferramenta + 1)), gJanela.getAltura() - 80);
	}
	
	cursorTipo = ferramenta;
}

void Interface::set_nFerramentas(int nFerramentas)
{
	this->nFerramentas = nFerramentas;
}

void Interface::set_faseAtual(Fase fase)
{
	faseAtual = fase;
}




