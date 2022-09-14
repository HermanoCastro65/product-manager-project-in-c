#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menus.h"
#include "arquivo.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");

	// Delaração de variáveis
	int opcao, sair = 0, tamanho = 0;
	PPProdutos produtos = aloca_vetor();
	
	// Carrega arquivo de texto no vetor de produtos
	ler_arquivo(produtos, &tamanho);
	getchar();

	// Menu principal
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
			// Chama o meu de produtos
			menu_produtos(produtos, &tamanho);
			getch();
			break;
		case 2:
			// Chama o menu de pedidos
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
