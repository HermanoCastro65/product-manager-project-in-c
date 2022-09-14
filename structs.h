#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct produto
{
	char descricao[100];
	int codigo, qtd_estoque;
	float preco;
} Produtos, *PProdutos, **PPProdutos;

// Aloca o vetor de produtos
PPProdutos aloca_vetor()
{
	PPProdutos produtos = (PPProdutos)malloc(sizeof(PProdutos));
	if (produtos == NULL)
	{
		printf("\n\nMemoria insuficiente\n\n");
		exit(1);
	}
	return produtos;
}

// Aloca struct de produto
void aloca_produto(PPProdutos produtos, int tamanho)
{
	produtos[tamanho] = (PProdutos)malloc(sizeof(Produtos));
	if (produtos[tamanho] == NULL)
	{
		printf("\n\nMemoria insuficiente\n\n");
		exit(1);
	}
}

#endif
