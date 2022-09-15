#ifndef ARQUIVO_H
#define ARQUIVO_H

void ler_arquivo(PPProdutos produtos, int *tamanho)
{
	FILE *file;

	// Abre o arquivo
	file = fopen("arquivo.txt", "r");

	if (file == NULL)
	{
		printf("\nNão foi possísvel ler o arquivo.\n");
		getchar();
		exit(1);
	}

	char buff[5];

	// Lê o arquivo e armazena no vetor de produtos
	while (!feof(file))
	{
		// Aloca o espaço para incluir um produto
		aloca_produto(produtos, *tamanho);

		if (produtos[*tamanho])
		{
			fgets(produtos[*tamanho]->descricao, sizeof(produtos[*tamanho]->descricao), file);
			produtos[*tamanho]->codigo = 1000 + rand() % 9000;
			fscanf(file, "%d %f", &produtos[*tamanho]->qtd_estoque, &produtos[*tamanho]->preco);
			fgets(buff, sizeof(buff), file);
			*tamanho = *tamanho + 1;
		}
	};

	// Fecha arquivo
	fclose(file);

	printf("\nARQUIVO LIDO COM SUCESSO \n");
}

#endif
