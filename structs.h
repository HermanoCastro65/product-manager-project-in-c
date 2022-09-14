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
		printf("\n\nMemória insuficiente\n\n");
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
		printf("\n\nMemória insuficiente\n\n");
		exit(1);
	}
}

// Encontra produto pelo c�digo
PProdutos get_produto(PPProdutos produtos, int codigo, int tamanho)
{
	int i = 0;
	for (i = 0; i < tamanho; i++)
	{
		if (codigo == produtos[i]->codigo)
			return produtos[i];	
	}
	return NULL;
}

#endif
