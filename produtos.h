#ifndef PRODUTOS_H
#define PRODUTOS_H

// Struct de produto
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
 
// Função incluir produtos
void incluir_produtos(PPProdutos produtos, int tamanho)
{
	system("cls");
	printf("\nINCLUIR PRODUTOS: \n");

	// Aloca o espaço para incluir um produto
	aloca_produto(produtos, tamanho);

	if (produtos[tamanho])
	{
		produtos[tamanho]->codigo = 1000 + rand() % 9000;
		printf("\nInforme a descrição do Produto: ");
		scanf(" %[^\n]", produtos[tamanho]->descricao);
		printf("Informe a quantidade em estoque do Produto: ");
		scanf("%d", &produtos[tamanho]->qtd_estoque);
		printf("Informe o preço do Produto: ");
		scanf("%f", &produtos[tamanho]->preco);
	}
	
	printf("\nCONCLUÍDO \n");
}

// Função alterar produtos
void alterar_produtos(PProdutos produto)
{
	system("cls");
	printf("\nALTERAR PRODUTOS: \n");

	printf("\n Código: %d", produto->codigo);
	printf("\nAlterar a descrição do Produto: ");
	scanf(" %[^\n]", produto->descricao);
	printf("Alterar a quantidade em estoque do Produto: ");
	scanf("%d", &produto->qtd_estoque);
	printf("Alterar o preço do Produto: ");
	scanf("%f", &produto->preco);
	
	printf("\nCONCLUÍDO \n");
}

// Função excluir produtos
void excluir_produtos(PPProdutos produtos, int posicao, int tamanho)
{
	system("cls");
	printf("\nEXCLUIR PRODUTOS: \n");
	
	int i;
	for (i = posicao; i < tamanho; i++)
	{
		produtos[i] = produtos[i + 1];
	}
	
	produtos[tamanho] = NULL;
	free(produtos[tamanho]);
	
	printf("\nCONCLUÍDO \n");
}

// Função consultar produtos
void consultar_produtos(PProdutos produto)
{
	system("cls");
	printf("\nCONSULTAR PRODUTOS: \n");
		
	printf("\n Código: %d", produto->codigo);
	printf("\n Descrição: %s", produto->descricao);
	printf("\n Preço: R$ %.2f", produto->preco);
	printf("\n Quantidade em Estoque: %d\n", produto->qtd_estoque);
	
	printf("\nCONCLUÍDO \n");
}

// Função listar produtos
void listar_produtos(PPProdutos produtos, int tamanho)
{
	system("cls");
	printf("\nLISTAR PRODUTOS: \n");

	int i;
	for (i = 0; i < tamanho; i++)
	{
		printf("\n Código: %d", produtos[i]->codigo);
		printf("\n Descrição: %s \n", produtos[i]->descricao);
	}
	
	printf("\nCONCLUÍDO \n");
}

#endif
