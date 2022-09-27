#ifndef MENUS_H
#define MENUS_H

#include "produtos.h"
#include "pedidos.h"

void menu_produtos(PPProdutos produtos, int * tamanho) {
    int opcao = 0, sair = 0, codigo = 0;
    PProdutos produto = NULL;

    do {
        system("cls");

        printf("\n(1) Incluir Produtos");
        printf("\n(2) Alterar Produtos");
        printf("\n(3) Excluir Produtos");
        printf("\n(4) Consultar Produtos");
        printf("\n(5) Listar Produtos");
        printf("\n(6) Sair");
        printf("\n\nDigite uma opção: ");
        scanf("%d", & opcao);

        switch (opcao) {
        case 1:
            incluir_produtos(produtos, * tamanho);
            * tamanho = * tamanho + 1;
            getch();
            break;
        case 2:
            listar_produtos(produtos, * tamanho);
            printf("\nDigite o código do produto que deseja alterar: ");
            scanf("%d", & codigo);
            produto = get_produto(produtos, codigo, * tamanho);
            if (produto)
                alterar_produtos(produto);
            getch();
            break;
        case 3:
            listar_produtos(produtos, * tamanho);
            printf("\nDigite o código do produto que deseja excluir: ");
            scanf("%d", & codigo);
            produto = get_produto(produtos, codigo, * tamanho);
            if (produto) {
                int posicao = get_posicao(produtos, produto, * tamanho);
                excluir_produtos(produtos, posicao, * tamanho);
                * tamanho = * tamanho - 1;
            }
            getch();
            break;
        case 4:
            listar_produtos(produtos, * tamanho);
            printf("\nDigite o código do produto que deseja consultar: ");
            scanf("%d", & codigo);
            produto = get_produto(produtos, codigo, * tamanho);
            if (produto)
                consultar_produtos(produto);
            getch();
            break;
        case 5:
            listar_produtos(produtos, * tamanho);
            getch();
            break;
        case 6:
            printf("\nSAIR \n");
            sair = 1;
            break;
        default:
            printf("\nOPÇÃO INVÁLIDA! \n");
            getch();
            sair = 0;
        }
    } while (!sair);
}

void menu_pedidos(PPProdutos produtos, PPPedidos historico, int * tamanho, int * tam_hist) {
    PPProdutos pedidos = aloca_vetor();

    if (pedidos) {
        int opcao = 0, sair = 0, codigo = 0, tam = 0;
        PProdutos produto = NULL, pedido = NULL;

        do {
            system("cls");
            printf("\n(1) Adicionar Pedidos");
            printf("\n(2) Consulta Pedidos");
            printf("\n(3) Excluir Pedidos");
            printf("\n(4) Alterar Pedidos");
            printf("\n(5) Sair / Finalizar Pedidos");;
            printf("\n\nDigite uma opção: ");
            scanf("%d", & opcao);

            switch (opcao) {
            case 1:
                listar_produtos(produtos, * tamanho);
                printf("\nDigite o código do produto que deseja adicionar: ");
                scanf("%d", & codigo);
                produto = get_produto(produtos, codigo, * tamanho);
                if (produto) {
                    system("cls");
                    consultar_produtos(produto);
                    adicionar_pedidos(pedidos, produto, tam);
                    tam = tam + 1;
                }
                getch();
                break;
            case 2:
                listar_produtos(pedidos, tam);
                printf("\nDigite o código do produto que deseja consultar no pedido: ");
                scanf("%d", & codigo);
                pedido = get_produto(pedidos, codigo, tam);
                if (pedido) {
                    int posicao = get_posicao(pedidos, pedido, tam);
                    consultar_pedidos(pedido, posicao);
                }
                getch();
                break;
            case 3:
                listar_produtos(pedidos, tam);
                printf("\nDigite o código do produto que deseja excluir no pedido: ");
                scanf("%d", & codigo);
                produto = get_produto(produtos, codigo, * tamanho);
                pedido = get_produto(pedidos, codigo, tam);
                if (produto && pedido) {
                    int posicao = get_posicao(pedidos, pedido, tam);
                    repor_pedidos(produto, pedido);
                    excluir_produtos(pedidos, posicao, tam);
                    tam = tam - 1;
                }
                getch();
                break;
            case 4:
                listar_produtos(pedidos, tam);
                printf("\nDigite o código do produto que deseja alterar no pedido: ");
                scanf("%d", & codigo);
                produto = get_produto(produtos, codigo, * tamanho);
                pedido = get_produto(pedidos, codigo, tam);
                if (produto && pedido)
                    alterar_pedidos(produto, pedido);
                getch();
                break;
            case 5:
                finalizar_pedidos(pedidos, historico, tam, * tam_hist);
                * tam_hist = * tam_hist + 1;
                getch();
                sair = 1;
                break;
            default:
                printf("\nOPÇÃO INVÁLIDA! \n");
                getch();
                sair = 0;
            }
        } while (!sair);
    }
}

#endif
