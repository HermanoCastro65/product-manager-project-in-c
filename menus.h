#ifndef MENUS_H
#define MENUS_H

#include "produtos.h"
#include "pedidos.h"

void menu_produtos(PPProdutos produtos, int *tamanho)
{
	int opcao, sair = 0;

	// Menu de produtos
	do
	{
		system("cls");

		printf("\n(1) Incluir Produtos");
		printf("\n(2) Alterar Produtos");
		printf("\n(3) Excluir Produtos");
		printf("\n(4) Consultar Produtos");
		printf("\n(5) Listar Produtos");
		printf("\n(6) Sair");
		printf("\n\nDigite uma op��o: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			// Chama a fun��o incluir produtos
			if (produtos)
			{
				incluir_produtos(produtos, *tamanho);
				*tamanho = *tamanho + 1;
			}
			getch();
			break;
		case 2:
			// Chama as fun��es de listar e alterar produtos
			if (produtos)
			{
				listar_produtos(produtos, *tamanho);

				int codigo;
				printf("\nDigite o c�digo do produto que deseja alterar: ");
				scanf("%d", &codigo);

				// Busca o produto pelo c�digo
				PProdutos produto = get_produto(produtos, codigo, *tamanho);
				if (!produto)
				{
					system("cls");
					printf("\nC�DIGO INV�LIDO! \n");	
				}
				else
					alterar_produtos(produto);
			}
			getch();
			break;
		case 3:
			// Chama as fun��es de listar e excluir produtos
			if (produtos)
			{
				listar_produtos(produtos, *tamanho);

				int codigo;
				printf("\nDigite o c�digo do produto que deseja excluir: ");
				scanf("%d", &codigo);

				// Busca o produto pelo c�digo
				PProdutos produto = get_produto(produtos, codigo, *tamanho);
				if (!produto)
				{
					system("cls");
					printf("\nC�DIGO INV�LIDO! \n");	
				}
				else
				{
					// Busca posi��o no vetor
					int posicao = get_posicao(produtos, produto, *tamanho);
					if(posicao)
					{
						excluir_produtos(produtos, posicao, *tamanho);
						*tamanho = *tamanho - 1;
					}

				}
			}
			getch();
			break;
		case 4:
			// Chama as fun��es de listar e consultar produtos
			if (produtos)
			{
				listar_produtos(produtos, *tamanho);

				int codigo;
				printf("\nDigite o c�digo do produto que deseja consultar: ");
				scanf("%d", &codigo);
				
				// Busca o produto pelo c�digo
				PProdutos produto = get_produto(produtos, codigo, *tamanho);
				if (!produto)
				{
					system("cls");
					printf("\nC�DIGO INV�LIDO! \n");	
				}
				else
					consultar_produtos(produto);
			}
			getch();
			break;
		case 5:
			// Chama a fun��o listar produtos
			if (produtos)
				listar_produtos(produtos, *tamanho);
			getch();
			break;
		case 6:
			printf("\nSAIR \n");
			sair = 1;
			break;
		default:
			printf("\nOP��O INV�LIDA! \n");
			getch();
			sair = 0;
		}
	} while (!sair);
}


void menu_pedidos()
{
	int opcao, sair = 0;

	// Menu de pedidos
	do
	{
		system("cls");
		printf("\n(1) Adicionar Pedidos");
		printf("\n(2) Consulta Pedidos");
		printf("\n(3) Excluir Pedidos");
		printf("\n(4) Alterar Pedidos");
		printf("\n(5) Finalizar Pedidos");
		printf("\n(6) Sair");
		printf("\n\nDigite uma op��o: ");
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
			printf("\nOP��O INV�LIDA! \n");
			getch();
			sair = 0;
		}
	} while (!sair);
}

#endif
