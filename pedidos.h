#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "historico.h"

// Função adicionar pedidos
void adicionar_pedidos(PPProdutos pedidos, PProdutos produto, int tam)
{
	printf("\nADICIONAR PEDIDOS: \n");
	
	int qtd;
	printf("\nInforme a quantidade que deseja adicionar: ");
	scanf("%d", &qtd);

	if(qtd <= produto->qtd_estoque)
	{
		// Aloca o espaço para incluir um produto no vetor de pedidos
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
	
	printf("\nCONCLUÍDO \n");
}


// Função consultar pedidos
void consultar_pedidos(PProdutos pedido, int posicao)
{
	system("cls");
	printf("\nCONSULTAR PEDIDOS: \n");
	
	printf("\n Pedido %d", posicao + 1);
	printf("\n Código do produto: %d", pedido->codigo);
	printf("\n Descrição: %s", pedido->descricao);
	printf("\n Preço: R$ %.2f", pedido->preco);
	printf("\n Quantidade da compra: %d\n", pedido->qtd_estoque);
	
	printf("\nCONCLUÍDO \n");
}

// Função repor pedidos - antes de excluir repoem no estoque
void repor_pedidos(PProdutos produto, PProdutos pedido) 
{
	printf("\nREPOR PEDIDOS: \n");
	
	produto->qtd_estoque = produto->qtd_estoque + pedido->qtd_estoque;
	
	printf("\nCONCLUÍDO \n");
}
// Função alterar pedidos
void alterar_pedidos(PProdutos produto, PProdutos pedido)
{
	system("cls");
	printf("\nALTERAR PEDIDOS: \n");
	
	int qtd;
	printf("\n Código: %d", produto->codigo);
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

	printf("\nCONCLUÍDO \n");
}

PPedidos finalizar_pedidos(PPProdutos pedidos, PPPedidos historico, int tam, int tam_hist)
{
	system("cls");
	printf("\nFINALIZAR PEDIDOS: \n");
	
	// Aloca o espaço para incluir um pedido no vetor de historico
	aloca_pedido(historico, tam_hist);
	
	if (historico[tam_hist])
	{
		historico[tam_hist]->codigo = 100 + rand() % 900;
		historico[tam_hist]->pedidos = pedidos;
		historico[tam_hist]->total = 0;
		
		int i;
		for (i = 0; i < tam; i++)
			historico[tam_hist]->total = historico[tam_hist]->total + (pedidos[tam]->preco * pedidos[tam]->qtd_estoque);
	}

	printf("\nCONCLUÍDO \n");
}

#endif
