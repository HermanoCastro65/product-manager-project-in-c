#ifndef ARQUIVO_H
#define ARQUIVO_H

void ler_arquivo(PPProdutos produtos, int * tamanho) {
	FILE * file;
    file = fopen("arquivo.txt", "r"); // abre o arquivo

    if (file == NULL) {
        printf("\nNão foi possísvel ler o arquivo.\n");
        getchar();
        exit(1);
    }

    char buff[5];

    // Lê o arquivo e armazena no vetor de produtos
    while (!feof(file)) {
        aloca_produto(produtos, * tamanho); // aloca o espaço para incluir um produto

        if (produtos[ * tamanho]) {
            fgets(produtos[ * tamanho] -> descricao, sizeof(produtos[ * tamanho] -> descricao), file);
            produtos[ * tamanho] -> codigo = 1000 + rand() % 9000;
            fscanf(file, "%d %f", & produtos[ * tamanho] -> qtd_estoque, & produtos[ * tamanho] -> preco);
            fgets(buff, sizeof(buff), file);
            * tamanho = * tamanho + 1;
        }
    };

    
    fclose(file); // fecha arquivo

    printf("\nARQUIVO LIDO COM SUCESSO \n");
}

#endif
