#ifndef ARQUIVO_H
#define ARQUIVO_H

void ler_arquivo(PPProdutos produtos, int *tamanho)
{
	FILE *file;

	// abrindo o arquivo
	file = fopen("arquivo.txt", "r");

	if (file == NULL)
	{
		printf("\nNão foi possível ler o arquivo.\n");
		getchar();
		exit(1);
	}

	char buff[5];

	while (!feof(file))
	{

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

	// fechando arquivo
	fclose(file);

	printf("\nARQUIVO LIDO COM SUCESSO \n");
}

#endif
