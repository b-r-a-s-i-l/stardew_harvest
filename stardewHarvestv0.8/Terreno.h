#pragma once
#include <fstream>
#include "libUnicornio.h"

enum TipoPlanta { outros = -1, nabo, batata, repolho, vagem};

enum FasePlanta { semente, broto, verde, maduro, colhida};

class Terreno
{
public:
	Terreno();
	~Terreno();

	void inicializar();
	void atualizar();
	void desenhar(int posX, int posY);

	void regar();
	void colher();

	void setPlanta(TipoPlanta tipo, FasePlanta fase);
	void setTempoMolhado();
	int setFase(int fase);

	int getLargura();
	int getAltura();
	void getPlantaPrimaria(TipoPlanta tipo, FasePlanta fase);


	
	int getOuro() { return nOuro; }
	bool getTerrenoSeco() { return terrenoSeco; }
	int getPosX() { return posX; }
	int getPosY() { return posX; }
	TipoPlanta getPlanta() { return tipoPlanta; }
	FasePlanta getFase() { return fasePlanta; }
	

	

protected:
	Sprite terreno, planta;
	TipoPlanta tipoPlanta;
	FasePlanta fasePlanta;

	ifstream arquivo;

	Som terrenoSom;

	bool terrenoSeco, terrenoOcupado;
	int largura, altura, tempoMolhado, posXMatriz, posYMatriz, nOuro = 0,
		deslocX, deslocY;
	float posX, posY;
};

