#ifndef PEDIDOS_H
#define PEDIDOS_H

// Struct de pedidos
typedef struct pedido
{
	int codigo;
	PPProdutos pedidos;
	int tam_pedidos;
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

// Fun��o adicionar pedidos
void adicionar_pedidos(PPProdutos pedidos, PProdutos produto, int tam)
{
	printf("\nADICIONAR PEDIDOS: \n");
	
	int qtd;
	printf("\nInforme a quantidade que deseja adicionar: ");
	scanf("%d", &qtd);

	if(qtd <= produto->qtd_estoque)
	{
		// Aloca o espa�o para incluir um produto no vetor de pedidos
		aloca_produto(pedidos, tam);
		
		pedidos[tam]->codigo = produto->codigo;
		strcpy(pedidos[tam]->descricao, produto->descricao);
		pedidos[tam]->preco = produto->preco;
		pedidos[tam]->qtd_estoque = qtd;
		produto->qtd_estoque = produto->qtd_estoque - qtd;
	} else
	{
		system("cls");
		printf("\nQUANTIDADE FORA DE ESTOQUE \n");
	}
	
	printf("\nCONCLU�DO \n");
}


// Fun��o consultar pedidos
void consultar_pedidos(PProdutos pedido, int posicao)
{
	system("cls");
	printf("\nCONSULTAR PEDIDOS: \n");
	
	printf("\n Pedido %d", posicao + 1);
	printf("\n C�digo do produto: %d", pedido->codigo);
	printf("\n Descri��o: %s", pedido->descricao);
	printf("\n Pre�o: R$ %.2f", pedido->preco);
	printf("\n Quantidade da compra: %d\n", pedido->qtd_estoque);
	
	printf("\nCONCLU�DO \n");
}

// Fun��o repor pedidos - antes de excluir repoem no estoque
void repor_pedidos(PProdutos produto, PProdutos pedido) 
{
	printf("\nREPOR PEDIDOS: \n");
	
	produto->qtd_estoque = produto->qtd_estoque + pedido->qtd_estoque;
	
	printf("\nCONCLU�DO \n");
}

// Fun��o alterar pedidos
void alterar_pedidos(PProdutos produto, PProdutos pedido)
{
	system("cls");
	printf("\nALTERAR PEDIDOS: \n");
	
	int qtd;
	printf("\nC�digo: %d", produto->codigo);
	printf("\nAlterar a quantidade do produto no pedido: ");
	scanf("%d", &qtd);
	
	if(qtd <= pedido->qtd_estoque + produto->qtd_estoque)
	{
		produto->qtd_estoque = produto->qtd_estoque + pedido->qtd_estoque;
		pedido->qtd_estoque = qtd;
		produto->qtd_estoque = produto->qtd_estoque - qtd;
	} else
	{
		system("cls");
		printf("\nQUANTIDADE FORA DE ESTOQUE \n");
	}

	printf("\nCONCLU�DO \n");
}

// Fun��o finalizar pedidos
void finalizar_pedidos(PPProdutos pedidos, PPPedidos historico, int tam, int tam_hist)
{
	system("cls");
	printf("\nFINALIZAR PEDIDOS: \n");
	
	// Aloca o espa�o para incluir um pedido no vetor de historico
	aloca_pedido(historico, tam_hist);
	
	if (historico[tam_hist])
	{
		historico[tam_hist]->codigo = 100 + rand() % 900;
		historico[tam_hist]->pedidos = pedidos;
		historico[tam_hist]->tam_pedidos = tam;
		historico[tam_hist]->total = 0;		
		int i;
		for (i = 0; i < tam; i++)
			historico[tam_hist]->total =  historico[tam_hist]->total + (pedidos[i]->preco * pedidos[i]->qtd_estoque);
	}

	printf("\nC�digo do pedido: %d", historico[tam_hist]->codigo);
	printf("\nTotal pago: R$ %.2f \n", historico[tam_hist]->total);	

	printf("\nCONCLU�DO \n");
}

// Fun��o ver hist�rico
void ver_historico(PPPedidos historico, int tam_hist)
{
	system("cls");
	printf("\nVER HIST�RICO: \n");
	
	int i;
	for(i = 0; i < tam_hist; i++){
		printf("\nC�digo do pedido: %d \n", historico[i]->codigo);
		int j;
		for (j = 0; j < historico[i]->tam_pedidos; j++)
		{
			printf("\nC�digo do produto: %d", historico[i]->pedidos[j]->codigo);
			printf("\nDescri��o: %s", historico[i]->pedidos[j]->descricao);
			printf("\nPre�o: R$ %.2f - Quantidade comprada: %d\n", historico[i]->pedidos[j]->preco, historico[i]->pedidos[j]->qtd_estoque);
		}
		printf("\nTotal pago: R$ %.2f \n\n", historico[i]->total);	
	}
	
	printf("\nCONCLU�DO \n");
}

#endif
