#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menus.h"
#include "arquivo.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	int opcao, sair = 0, tamanho = 0;
	PPProdutos produtos = aloca_vetor();

	ler_arquivo(produtos, &tamanho);
	getchar();

	do
	{
		system("cls");
		printf("\n(1) Menu Produtos");
		printf("\n(2) Menu Pedidos");
		printf("\n(3) Sair");
		printf("\n\nDigite uma opção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			menu_produtos(produtos, &tamanho);
			getch();
			break;
		case 2:
			menu_pedidos();
			getch();
			break;
		case 3:
			printf("\nSAIR \n");
			sair = 1;
			break;
		default:
			printf("\nOPÇÃO INVÁLIDA! \n");
			getch();
			sair = 0;
		}
	} while (!sair);

	return 0;
}
