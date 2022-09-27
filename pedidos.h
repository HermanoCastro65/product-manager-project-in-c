#ifndef PEDIDOS_H
#define PEDIDOS_H

typedef struct pedido {
    int codigo;
    PPProdutos pedidos;
    int tam_pedidos;
    float total;
}
Pedidos, * PPedidos, ** PPPedidos;

PPPedidos aloca_historico() {
    PPPedidos pedidos = (PPPedidos) malloc(sizeof(PPedidos));
    if (pedidos == NULL) {
        printf("\n\nMem�ria insuficiente\n\n");
        exit(1);
    }
    return pedidos;
}

void aloca_pedido(PPPedidos pedidos, int tam_hist) {
    pedidos[tam_hist] = (PPedidos) malloc(sizeof(Pedidos));
    if (pedidos[tam_hist] == NULL) {
        printf("\n\nMem�ria insuficiente\n\n");
        exit(1);
    }
}

void adicionar_pedidos(PPProdutos pedidos, PProdutos produto, int tam) {
    printf("\nADICIONAR PEDIDOS: \n");

    int qtd = 0;
    printf("\nInforme a quantidade que deseja adicionar: ");
    scanf("%d", & qtd);

    if (qtd <= produto -> qtd) {
        aloca_produto(pedidos, tam); // aloca novo vetor para os produtos em estoque
        if (pedidos[tam]) {
            pedidos[tam] -> codigo = produto -> codigo;
            strcpy(pedidos[tam] -> descricao, produto -> descricao);
            pedidos[tam] -> preco = produto -> preco;
            pedidos[tam] -> qtd = qtd;
            produto -> qtd = produto -> qtd - qtd;
        }
    } else {
        system("cls");
        printf("\nQUANTIDADE FORA DE ESTOQUE \n");
    }

    printf("\nCONCLU�DO \n");
}

void consultar_pedidos(PProdutos pedido, int posicao) {
    system("cls");
    printf("\nCONSULTAR PEDIDOS: \n");

    printf("\n Pedido %d", posicao + 1);
    printf("\n C�digo do produto: %d", pedido -> codigo);
    printf("\n Descri��o: %s", pedido -> descricao);
    printf("\n Pre�o: R$ %.2f", pedido -> preco);
    printf("\n Quantidade da compra: %d\n", pedido -> qtd);

    printf("\nCONCLU�DO \n");
}

void repor_pedidos(PProdutos produto, PProdutos pedido) {
    printf("\nREPOR PEDIDOS: \n");

    produto -> qtd = produto -> qtd + pedido -> qtd;

    printf("\nCONCLU�DO \n");
}

void alterar_pedidos(PProdutos produto, PProdutos pedido) {
    system("cls");
    printf("\nALTERAR PEDIDOS: \n");

    int qtd = 0;
    printf("\nC�digo: %d", produto -> codigo);
    printf("\nAlterar a quantidade do produto no pedido: ");
    scanf("%d", & qtd);

    if (qtd <= pedido -> qtd + produto -> qtd) {
        produto -> qtd = produto -> qtd + pedido -> qtd;
        pedido -> qtd = qtd;
        produto -> qtd = produto -> qtd - qtd;
    } else {
        system("cls");
        printf("\nQUANTIDADE FORA DE ESTOQUE \n");
    }

    printf("\nCONCLU�DO \n");
}

void finalizar_pedidos(PPProdutos pedidos, PPPedidos historico, int tam, int tam_hist) {
    system("cls");
    printf("\nFINALIZAR PEDIDOS: \n");

    aloca_pedido(historico, tam_hist); // aloca o espa�o para incluir um pedido no vetor de historico

    if (historico[tam_hist]) {
        historico[tam_hist] -> codigo = 100 + rand() % 900;
        historico[tam_hist] -> pedidos = pedidos;
        historico[tam_hist] -> tam_pedidos = tam;
        historico[tam_hist] -> total = 0;
        int i = 0;
        for (i = 0; i < tam; i++)
            historico[tam_hist] -> total = historico[tam_hist] -> total + (pedidos[i] -> preco * pedidos[i] -> qtd);
    }

    printf("\nC�digo do pedido: %d", historico[tam_hist] -> codigo);
    printf("\nTotal pago: R$ %.2f \n", historico[tam_hist] -> total);

    printf("\nCONCLU�DO \n");
}

void ver_historico(PPPedidos historico, int tam_hist) {
    system("cls");
    printf("\nVER HIST�RICO: \n");

    PPProdutos pedidos = NULL;
    int i = 0;
    for (i = 0; i < tam_hist; i++) {
        printf("\nC�digo do pedido: %d \n", historico[i] -> codigo);
        pedidos = historico[i] -> pedidos;
        int j;
        for (j = 0; j < historico[i] -> tam_pedidos; j++) {
            printf("\nC�digo do produto: %d", pedidos[j] -> codigo);
            printf("\nDescri��o: %s", pedidos[j] -> descricao);
            printf("\nPre�o: R$ %.2f - Quantidade comprada: %d\n", pedidos[j] -> preco, pedidos[j] -> qtd);
        }
        printf("\nTotal pago: R$ %.2f \n\n", historico[i] -> total);
    }

    printf("\nCONCLU�DO \n");
}

void destruir_pedidos(PPPedidos historico, int * tam_hist) {
    historico = NULL;
    free(historico);
    PPPedidos historico_novo = aloca_historico();

    if (historico_novo) {
        historico = historico_novo;
        * tam_hist = 0;
        printf("\nDESTRUIU HIST�RICO \n");
    }
}

#endif
