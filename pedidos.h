#ifndef PEDIDOS_H
#define PEDIDOS_H

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
	printf("\n C�digo: %d", produto->codigo);
	printf("Alterar a quantidade do produto no pedido: ");
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

void finalizar_pedidos()
{
	printf("\n finalizar");
}

#endif
