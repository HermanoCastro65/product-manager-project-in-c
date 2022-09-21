#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menus.h"
#include "arquivo.h"

int main(int argc, char * argv[]) {
    setlocale(LC_ALL, "Portuguese");

    int opcao, sair = 0, tamanho = 0, tam_hist = 0;
    PPProdutos produtos = aloca_vetor();
    PPPedidos historico = aloca_historico();

    if (produtos && historico) {
        ler_arquivo(produtos, & tamanho);
        getchar();

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
                menu_produtos(produtos, & tamanho);
                getch();
                break;
            case 2:
                menu_pedidos(produtos, historico, & tamanho, & tam_hist);
                getch();
                break;
            case 3:
                ver_historico(historico, tam_hist);
                getch();
                break;
            case 4:
                system("cls");
                destruir_produtos(produtos, & tamanho);
                destruir_pedidos(historico, & tam_hist);
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
