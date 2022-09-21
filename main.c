#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menus.h"
#include "arquivo.h"

int main(int argc, char * argv[]) {
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis globais
    int opcao, sair = 0, tamanho = 0, tam_hist = 0;

    // Aloca vetor para os produtos em estoque
    PPProdutos produtos = aloca_vetor();

    // Aloca vetor para os pedidos no histórico
    PPPedidos historico = aloca_historico();

    if (produtos && historico) {
        // Carrega arquivo de texto no vetor de produtos
        ler_arquivo(produtos, & tamanho);
        getchar();

        // Menu principal
        do {
            system("cls");
            printf("\n(1) Menu Produtos");
            printf("\n(2) Menu Pedidos");
            printf("\n(3) Histórico de Pedidos");
            printf("\n(4) Destruir Loja");
            printf("\n(5) Sair");
            printf("\n\nDigite uma opção: ");
            scanf("%d", & opcao);

            switch (opcao) {
            case 1:
                // Chama o menu de produtos
                menu_produtos(produtos, & tamanho);
                getch();
                break;
            case 2:
                // Chama o menu de pedidos
                menu_pedidos(produtos, historico, & tamanho, & tam_hist);
                getch();
                break;
            case 3:
                // Chama o histórico
                ver_historico(historico, tam_hist);
                getch();
                break;
            case 4:
                // Chama a função destruir
                destruir(produtos, historico, &tamanho, &tam_hist);
                getch();
                break;
            case 5:
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

    return 0;
}
