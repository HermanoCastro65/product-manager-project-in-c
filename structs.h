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

// Encontra produto pelo código
PProdutos get_produto(PPProdutos produtos, int codigo, int tamanho)
{
	int i;
	for (i = 0; i < tamanho; i++)
	{
		if (codigo == produtos[i]->codigo)
			return produtos[i];	
	}
	return NULL;
}

// Encontra posição do produto no vetor
 int get_posicao(PPProdutos produtos, PProdutos produto, int tamanho)
 {
 	int i;
	for (i = 0; i < tamanho; i++)
	{
		if (produto == produtos[i])
			return i;	
	}
	return;
 }
#endif
