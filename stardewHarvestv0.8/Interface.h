#pragma once
#include "libUnicornio.h"


enum Cursor { regador, foice, picareta, machado, maoColher};
enum Fase { fase1 = 1, fase2, fase3, fase4, fase5, fase6, fase7, fase8, fase9, fase10 };

class Interface
{
public:
	Interface();
	~Interface();

	void inicializar();
	void atualizar();
	void desenhar(int posX, int posY);
	void deletar();
	void lerFase();

	void set_nJogadas(int jogada);
	void set_nOuro(int ouro);
	void set_metaObjetivo(int missao);
	void set_FerramentaEmUso(Cursor ferramenta);
	void set_nFerramentas(int nFerramentas);
	void set_faseAtual(Fase fase);
	
	int get_nJogadas() { return nJogadas; }
	int get_nOuro() { return nOuro; }
	int get_nMissao() { return nObjetivos; }
	int get_nFerramentas() { return nFerramentas; }
	int get_metaObjetivo(int objetivo) { return metaObjetivo[objetivo]; }
	int get_Objetivo(int nObjetivo) { return objetivo[nObjetivo]; }
	
	Cursor get_FerramentaEmUso() { return cursorTipo; }

	int get_SprFerramenta_largura(int ferramenta);
	int get_SprFerramenta_altura(int ferramenta);

	
	
	


protected:
	ifstream arquivo;
	int nOuro = 0, randMeta,
		nJogadas, nObjetivos, nMetas, nFerramentas, // lendo do arquivo
		*objetivo, *metaObjetivo, *custoFerramenta;
	float posX, posY;

	Som somObjetivo;
	Fase faseAtual;
	Cursor cursorTipo;
	Texto *valorObjetivo, *valorFerramenta, valorOuro, valorJogadas;
	Sprite *spriteObjetivo, *spriteFerramenta, *spriteGItem, selecFerramenta;
};

