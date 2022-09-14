#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "structs.h"

// Fun��o incluir produtos
void incluir_produtos(PPProdutos produtos, int tamanho)
{
	system("cls");
	printf("\nINCLUIR PRODUTOS: \n");

	// Aloca o espa�o para incluir um produto
	aloca_produto(produtos, tamanho);

	if (produtos[tamanho])
	{
		produtos[tamanho]->codigo = 1000 + rand() % 9000;
		printf("\nInforme a descri��o do Produto: ");
		scanf(" %[^\n]", produtos[tamanho]->descricao);
		printf("Informe a quantidade em estoque do Produto: ");
		scanf("%d", &produtos[tamanho]->qtd_estoque);
		printf("Informe o pre�o do Produto: ");
		scanf("%f", &produtos[tamanho]->preco);
		printf("\nCONCLU�DO \n");
	}
}

void alterar_produtos()
{
	printf("\n alterar");
}

void excluir_produtos()
{
	printf("\n excluir");
}

// Fun��o consultar produtos
void consultar_produtos(PPProdutos produtos, int codigo, int tamanho)
{
	system("cls");
	printf("\nCONSULTAR PRODUTOS: \n");

	// Busca o produto desejado pelo c�digo
	PProdutos produto = get_produto(produtos, codigo, tamanho);

	if (!produto)
	{
		printf("\nC�DIGO INV�LIDO! \n");
		return;
	}
		
	printf("\n C�digo: %d", produto->codigo);
	printf("\n Descri��o: %s", produto->descricao);
	printf("\n Pre�o: R$ %.2f", produto->preco);
	printf("\n Quantidade em Estoque: %d\n", produto->qtd_estoque);
	printf("\nCONCLU�DO \n");
		
	free(produto);
}

// Fun��o listar produtos
void listar_produtos(PPProdutos produtos, int tamanho)
{
	system("cls");
	printf("\nLISTAR PRODUTOS: \n");

	int i;
	for (i = 0; i < tamanho; i++)
	{
		printf("\n C�digo: %d", produtos[i]->codigo);
		printf("\n Descri��o: %s", produtos[i]->descricao);
	}
	printf("\nCONCLU�DO \n");
}

#endif
