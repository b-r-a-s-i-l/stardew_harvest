#include "Terreno.h"



Terreno::Terreno()
{
}


Terreno::~Terreno()
{
}

void Terreno::inicializar()
{
	arquivo.open("stage/fase_01.txt");
	arquivo >> deslocX >> deslocY;
	arquivo.close();

	if (!gRecursos.carregouSpriteSheet("plantas"))
	{
		gRecursos.carregarSpriteSheet("plantas", "img/plantas.png", 5, 4);
	}
	planta.setSpriteSheet("plantas");

	if (!gRecursos.carregouSpriteSheet("terreno"))
	{
		gRecursos.carregarSpriteSheet("terreno", "img/terreno.png", 1, 2);
	}
	terreno.setSpriteSheet("terreno");

	if (!gRecursos.carregouAudio("SE-TerrenoMolhado"))
	{
		gRecursos.carregarAudio("SE-TerrenoMolhado", "music/SE-TerrenoMolhado.wav");
	}

	if (!gRecursos.carregouAudio("SE-TerrenoColher"))
	{
		gRecursos.carregarAudio("SE-TerrenoColher", "music/SE-TerrenoColher.wav");
	}


}

void Terreno::setPlanta(TipoPlanta tipo, FasePlanta fase)
{
	tipoPlanta = tipo;
	fasePlanta = fase;
	terrenoSeco = true;
	tempoMolhado = 0;

	// define NABO
	if (tipoPlanta == nabo)
	{
		planta.setAnimacao(0);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	// define BATATA
	if (tipoPlanta == batata)
	{
		planta.setAnimacao(2);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define REPOLHO
	if (tipoPlanta == repolho)
	{
		planta.setAnimacao(1);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define VAGEM
	if (tipoPlanta == vagem)
	{
		planta.setAnimacao(3);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define OUTROS
	if (tipoPlanta == outros)
	{
		planta.setAnimacao(4);

		if (fasePlanta == semente) // nada
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto) // erva daninha
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde) // pedra
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro) // maduro
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}
}

void Terreno::regar()
{
	if (terrenoOcupado)
	{
		// define NABO
		if (tipoPlanta == nabo)
		{
			switch (fasePlanta)
			{
			case semente:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = broto;
				break;
			case broto:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = verde;
				break;
			case verde:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = maduro;
				break;
			case maduro:
				colher();
				break;
			case colhida:
				//nada acontece
				break;
			}
		}

		// define REPOLHO
		if (tipoPlanta == batata)
		{
			switch (fasePlanta)
			{
			case semente:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = broto;
				break;
			case broto:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = verde;
				break;
			case verde:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = maduro;
				break;
			case maduro:
				colher();
				break;
			case colhida:
				//nada acontece
				break;
			}
		}

		//define BATATA
		if (tipoPlanta == repolho)
		{
			switch (fasePlanta)
			{
			case semente:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = broto;
				break;
			case broto:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = verde;
				break;
			case verde:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = maduro;
				break;
			case maduro:
				colher();
				break;
			case colhida:
				//nada acontece
				break;
			}
		}

		//define VAGEM
		if (tipoPlanta == vagem)
		{
			switch (fasePlanta)
			{
			case semente:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = broto;
				break;
			case broto:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = verde;
				break;
			case verde:
				terrenoSeco = false;
				tempoMolhado = 2;
				terrenoSom.setAudio("SE-TerrenoMolhado");
				terrenoSom.tocar();

				fasePlanta = maduro;
				break;
			case maduro:
				colher();
				break;
			case colhida:
				//nada acontece
				break;
			}
		}

		//define OUTROS
		if (tipoPlanta == outros)
		{
			switch (fasePlanta)
			{
			case semente:
				fasePlanta = broto;
				break;
			case broto:
				fasePlanta = verde;
				break;
			case verde:
				fasePlanta = maduro;
				break;
			case maduro:
				colher();
				break;
			case colhida:
				//nada acontece
				break;
			}
		}
	}
}
void Terreno::atualizar()
{
	//define TERRENO COND

	if (terrenoSeco) terreno.setFrame(0); // seco
	if (!terrenoSeco) terreno.setFrame(1); // molhado

		// define NABO
	if (tipoPlanta == nabo)
	{
		planta.setAnimacao(0);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	// define BATATA
	if (tipoPlanta == batata)
	{
		planta.setAnimacao(2);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define REPOLHO
	if (tipoPlanta == repolho)
	{
		planta.setAnimacao(1);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define VAGEM
	if (tipoPlanta == vagem)
	{
		planta.setAnimacao(3);

		if (fasePlanta == semente)
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto)
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde)
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro)
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}

	//define OUTROS
	if (tipoPlanta == outros)
	{
		planta.setAnimacao(4);

		if (fasePlanta == semente) // nada
		{
			planta.setFrame(0);
		}
		if (fasePlanta == broto) // erva daninha
		{
			planta.setFrame(1);
		}
		if (fasePlanta == verde) // pedra
		{
			planta.setFrame(2);
		}
		if (fasePlanta == maduro) // maduro
		{
			planta.setFrame(3);
		}
		if (fasePlanta == colhida)
		{
			terrenoOcupado = false;
		}
	}
}

void Terreno::desenhar(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;

	terreno.desenhar(posX, posY);
	if (terrenoOcupado)
	{
		planta.desenhar(posX, posY);
	}
}



void Terreno::colher()
{
	if (terrenoOcupado)
	{
		if (tipoPlanta == outros)
		{
			if (fasePlanta == semente) { nOuro = 0; }
			if (fasePlanta == broto) { nOuro = 2; }
			if (fasePlanta == verde) { nOuro = 3; }
			if (fasePlanta == maduro) { nOuro = 4; }

			nOuro = nOuro * -10;

			getOuro(); // retorna nOuro
			fasePlanta = colhida;
		}

		if (fasePlanta == maduro)
		{
			terrenoSom.setAudio("SE-TerrenoColher");
			terrenoSom.tocar();

			if (tipoPlanta == nabo) { nOuro = 1; }
			if (tipoPlanta == batata) { nOuro = 2; }
			if (tipoPlanta == repolho) { nOuro = 3; }
			if (tipoPlanta == vagem) { nOuro = 4; }

			nOuro = nOuro * maduro;

			getOuro(); // retorna nOuro
			fasePlanta = colhida;
		}
	}
}

int Terreno::getLargura()
{
	largura = terreno.getLargura();
	return largura;
}

int Terreno::getAltura()
{
	altura = terreno.getAltura();
	return altura;
}

void Terreno::getPlantaPrimaria(TipoPlanta tipo, FasePlanta fase)
{
	tipoPlanta = tipo;
	fasePlanta = fase;
}

int Terreno::setFase(int fase)
{
	fasePlanta = (FasePlanta)fase;

	return fasePlanta;
}


void Terreno::setTempoMolhado()
{

	if (tempoMolhado > 0)
	{
		terrenoSeco = false;
		tempoMolhado--;
	}
	if (tempoMolhado <= 0)
	{
		tempoMolhado = 0;
		terrenoSeco = true;
	}
}
