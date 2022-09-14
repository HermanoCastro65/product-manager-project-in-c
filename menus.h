#ifndef MENUS_H
#define MENUS_H

#include "produtos.h"
#include "pedidos.h"

void menu_produtos(PPProdutos produtos, int *tamanho)
{
	int opcao, sair = 0;

	do
	{
		system("cls");

		printf("\n(1) Incluir Produtos");
		printf("\n(2) Alterar Produtos");
		printf("\n(3) Excluir Produtos");
		printf("\n(4) Consultar Produtos");
		printf("\n(5) Listar Produtos");
		printf("\n(6) Sair");
		printf("\n\nDigite uma opção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			if (produtos)
			{
				incluir_produtos(produtos, *tamanho);
				*tamanho = *tamanho + 1;
			}
			getch();
			break;
		case 2:
			alterar_produtos();
			getch();
			break;
		case 3:
			excluir_produtos();
			getch();
			break;
		case 4:
			consultar_produtos();
			getch();
			break;
		case 5:
			if (produtos)
				listar_produtos(produtos, *tamanho);
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

void menu_pedidos()
{
	int opcao, sair = 0;

	do
	{
		system("cls");
		printf("\n(1) Adicionar Pedidos");
		printf("\n(2) Consulta Pedidos");
		printf("\n(3) Excluir Pedidos");
		printf("\n(4) Alterar Pedidos");
		printf("\n(5) Finalizar Pedidos");
		printf("\n(6) Sair");
		printf("\n\nDigite uma opção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			adicionar_pedidos();
			getch();
			break;
		case 2:
			consultar_pedidos();
			getch();
			break;
		case 3:
			excluir_pedidos();
			getch();
			break;
		case 4:
			alterar_pedidos();
			getch();
			break;
		case 5:
			finalizar_pedidos();
			getch();
			sair = 1;
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

#endif
