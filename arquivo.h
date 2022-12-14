#ifndef ARQUIVO_H
#define ARQUIVO_H

void ler_arquivo(PPProdutos produtos, int * tamanho) {
    FILE * file = NULL;
    file = fopen("arquivo.txt", "r");

    if (file == NULL) {
        printf("\nN?o foi poss?svel ler o arquivo.\n");
        getchar();
        exit(1);
    }

    char buff[5] = "buff";
    while (!feof(file)) {
        aloca_produto(produtos, * tamanho);

        if (produtos[ * tamanho]) {
            fgets(produtos[ * tamanho] -> descricao, sizeof(produtos[ * tamanho] -> descricao), file);
            produtos[ * tamanho] -> codigo = 1000 + rand() % 9000;
            fscanf(file, "%d %f", & produtos[ * tamanho] -> qtd, & produtos[ * tamanho] -> preco);
            fgets(buff, sizeof(buff), file);
            * tamanho = * tamanho + 1;
        }
    };
    fclose(file);

    printf("\nARQUIVO LIDO COM SUCESSO \n");
}

#endif
