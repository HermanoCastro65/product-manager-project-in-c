#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "structs.h"

void incluir_produtos(PPProdutos produtos, int tamanho)
{
	system("cls");
	printf("\nINCLUIR PRODUTOS: \n");

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
void consultar_produtos(PPProdutos produtos, int codigo, int tamanho)
{
	system("cls");
	printf("\nCONSULTAR PRODUTOS: \n");

	int i = 0;
	for (i = 0; i < tamanho; i++)
	{
		if (codigo == produtos[i]->codigo)
		{
			printf("\n C�digo: %d", produtos[i]->codigo);
			printf("\n Descri��o: %s", produtos[i]->descricao);
			printf("\n Pre�o: R$ %.2f", produtos[i]->preco);
			printf("\n Quantidade em Estoque: %d\n", produtos[i]->qtd_estoque);
			printf("\nCONCLU�DO \n");
			return;
		}
	}
	printf("\nC�DIGO INV�LIDO! \n");
}

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
