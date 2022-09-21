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
        printf("\n\nMemória insuficiente\n\n");
        exit(1);
    }
    return pedidos;
}

void aloca_pedido(PPPedidos pedidos, int tam_hist) {
    pedidos[tam_hist] = (PPedidos) malloc(sizeof(Pedidos));
    if (pedidos[tam_hist] == NULL) {
        printf("\n\nMemória insuficiente\n\n");
        exit(1);
    }
}

void adicionar_pedidos(PPProdutos pedidos, PProdutos produto, int tam) {
    printf("\nADICIONAR PEDIDOS: \n");

    int qtd;
    printf("\nInforme a quantidade que deseja adicionar: ");
    scanf("%d", & qtd);

    if (qtd <= produto -> qtd_estoque) {
        aloca_produto(pedidos, tam); // aloca novo vetor para os produtos em estoque
		if(pedidos[tam]){
	        pedidos[tam] -> codigo = produto -> codigo;
	        strcpy(pedidos[tam] -> descricao, produto -> descricao);
	        pedidos[tam] -> preco = produto -> preco;
	        pedidos[tam] -> qtd_estoque = qtd;
	        produto -> qtd_estoque = produto -> qtd_estoque - qtd;			
		}
    } else {
        system("cls");
        printf("\nQUANTIDADE FORA DE ESTOQUE \n");
    }

    printf("\nCONCLUÍDO \n");
}

void consultar_pedidos(PProdutos pedido, int posicao) {
    system("cls");
    printf("\nCONSULTAR PEDIDOS: \n");

    printf("\n Pedido %d", posicao + 1);
    printf("\n Código do produto: %d", pedido -> codigo);
    printf("\n Descrição: %s", pedido -> descricao);
    printf("\n Preço: R$ %.2f", pedido -> preco);
    printf("\n Quantidade da compra: %d\n", pedido -> qtd_estoque);

    printf("\nCONCLUÍDO \n");
}
void repor_pedidos(PProdutos produto, PProdutos pedido) {
    printf("\nREPOR PEDIDOS: \n");

    produto -> qtd_estoque = produto -> qtd_estoque + pedido -> qtd_estoque;

    printf("\nCONCLUÍDO \n");
}

void alterar_pedidos(PProdutos produto, PProdutos pedido) {
    system("cls");
    printf("\nALTERAR PEDIDOS: \n");

    int qtd;
    printf("\nCódigo: %d", produto -> codigo);
    printf("\nAlterar a quantidade do produto no pedido: ");
    scanf("%d", & qtd);

    if (qtd <= pedido -> qtd_estoque + produto -> qtd_estoque) {
        produto -> qtd_estoque = produto -> qtd_estoque + pedido -> qtd_estoque;
        pedido -> qtd_estoque = qtd;
        produto -> qtd_estoque = produto -> qtd_estoque - qtd;
    } else {
        system("cls");
        printf("\nQUANTIDADE FORA DE ESTOQUE \n");
    }

    printf("\nCONCLUÍDO \n");
}

void finalizar_pedidos(PPProdutos pedidos, PPPedidos historico, int tam, int tam_hist) {
    system("cls");
    printf("\nFINALIZAR PEDIDOS: \n");

    aloca_pedido(historico, tam_hist); // aloca o espaço para incluir um pedido no vetor de historico

    if (historico[tam_hist]) {
        historico[tam_hist] -> codigo = 100 + rand() % 900;
        historico[tam_hist] -> pedidos = pedidos;
        historico[tam_hist] -> tam_pedidos = tam;
        historico[tam_hist] -> total = 0;
        int i;
        for (i = 0; i < tam; i++)
            historico[tam_hist] -> total = historico[tam_hist] -> total + (pedidos[i] -> preco * pedidos[i] -> qtd_estoque);
    }

    printf("\nCódigo do pedido: %d", historico[tam_hist] -> codigo);
    printf("\nTotal pago: R$ %.2f \n", historico[tam_hist] -> total);

    printf("\nCONCLUÍDO \n");
}

void ver_historico(PPPedidos historico, int tam_hist) {
    system("cls");
    printf("\nVER HISTÓRICO: \n");

    int i;
    for (i = 0; i < tam_hist; i++) {
        printf("\nCódigo do pedido: %d \n", historico[i] -> codigo);
        int j;
        for (j = 0; j < historico[i] -> tam_pedidos; j++) {
            printf("\nCódigo do produto: %d", historico[i] -> pedidos[j] -> codigo);
            printf("\nDescrição: %s", historico[i] -> pedidos[j] -> descricao);
            printf("\nPreço: R$ %.2f - Quantidade comprada: %d\n", historico[i] -> pedidos[j] -> preco, historico[i] -> pedidos[j] -> qtd_estoque);
        }
        printf("\nTotal pago: R$ %.2f \n\n", historico[i] -> total);
    }

    printf("\nCONCLUÍDO \n");
}

void destruir_pedidos(PPPedidos historico, int * tam_hist) {
    historico = NULL;
    free(historico);

    PPPedidos historico_novo = aloca_historico(); // aloca novo vetor para os pedidos no histórico
    if (historico_novo) {
        historico = historico_novo;
        * tam_hist = 0;
        printf("\nDESTRUIU HISTÓRICO \n");
    }
}

#endif
