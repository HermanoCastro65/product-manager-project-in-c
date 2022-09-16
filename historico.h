#ifndef HISTORICO_H
#define HISTORICO_H

//#include "produtos.h"

// Struct de pedidos
typedef struct pedido
{
	int codigo;
	PPProdutos pedidos;
	float total;
} Pedidos, *PPedidos, **PPPedidos;

// Aloca o vetor de pedidos
PPPedidos aloca_historico()
{
	PPPedidos pedidos = (PPPedidos)malloc(sizeof(PPedidos));
	if (pedidos == NULL)
	{
		printf("\n\nMem�ria insuficiente\n\n");
		exit(1);
	}
	return pedidos;
}

// Aloca struct de pedido
void aloca_pedido(PPPedidos pedidos, int tam_hist)
{
	pedidos[tam_hist] = (PPedidos)malloc(sizeof(Pedidos));
	if (pedidos[tam_hist] == NULL)
	{
		printf("\n\nMem�ria insuficiente\n\n");
		exit(1);
	}
}

/* Fun��o salvar hist�rico
void ver_historico(PPProdutos pedidos, PPPedidos historico, int *tam_hist)
{
		printf("\n\nVer Hist�rico\n\n");
};

// Fun��o ver hist�rico
void ver_historico(PPPedidos historico, int *tam_hist)
{
		printf("\n\nVer Hist�rico\n\n");
};*/

#endif
