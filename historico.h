// Struct de pedidos
typedef struct pedido
{
	int codigo
	PPProdutos pedidos;
	float total;
} Pedidos, *PPedidos, **PPPedidos;

// Aloca o vetor de pedidos
PPPedidos aloca_historico()
{
	PPPedidos pedidos = (PPPedidos)malloc(sizeof(PPedidos));
	if (pedidoss == NULL)
	{
		printf("\n\nMem�ria insuficiente\n\n");
		exit(1);
	}
	return pedidos;
}

// Aloca struct de pedido
void aloca_pedido(PPPedidos pedidos, int tam_hist)
{
	produtos[tam_hist] = (PPedidos)malloc(sizeof(Pedidos));
	if (pedidos[tam_hist] == NULL)
	{
		printf("\n\nMem�ria insuficiente\n\n");
		exit(1);
	}
}
