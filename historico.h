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
		printf("\n\nMemória insuficiente\n\n");
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
		printf("\n\nMemória insuficiente\n\n");
		exit(1);
	}
}

#endif
