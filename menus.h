#ifndef MENUS_H
#define MENUS_H

#include "produtos.h"
#include "pedidos.h"

void menu_produtos(PPProdutos produtos, int *tamanho)
{
	int opcao, sair = 0, codigo;
	PProdutos produto;
	
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
		printf("\n\nDigite uma opção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			// Chama a função incluir produtos
			incluir_produtos(produtos, *tamanho);
			*tamanho = *tamanho + 1;

			getch();
			break;
		case 2:
			// Chama as funções de listar e alterar produtos
			listar_produtos(produtos, *tamanho);
			printf("\nDigite o código do produto que deseja alterar: ");
			scanf("%d", &codigo);

			// Busca o produto pelo código
			produto = get_produto(produtos, codigo, *tamanho);
			if (produto)
				alterar_produtos(produto);
				
			getch();
			break;
		case 3:
			// Chama as funções de listar e excluir produtos
			listar_produtos(produtos, *tamanho);

			printf("\nDigite o código do produto que deseja excluir: ");
			scanf("%d", &codigo);

			// Busca o produto pelo código
			produto = get_produto(produtos, codigo, *tamanho);
			if (produto)
			{
				// Busca posição no vetor
				int posicao = get_posicao(produtos, produto, *tamanho);
				excluir_produtos(produtos, posicao, *tamanho);
				*tamanho = *tamanho - 1;
			}
			
			getch();
			break;
		case 4:
			// Chama as funções de listar e consultar produtos
			listar_produtos(produtos, *tamanho);
			printf("\nDigite o código do produto que deseja consultar: ");
			scanf("%d", &codigo);
			
			// Busca o produto pelo código
			produto = get_produto(produtos, codigo, *tamanho);
			if (produto)
				consultar_produtos(produto);
	
			getch();
			break;
		case 5:
			// Chama a função listar produtos
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


void menu_pedidos(PPProdutos produtos, PPProdutos pedidos, int *tamanho, int *tam)
{
	int opcao, sair = 0, codigo;
	PProdutos produto, pedido;

	if(pedidos)
	{
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
			printf("\n\nDigite uma opção: ");
			scanf("%d", &opcao);
	
			switch (opcao)
			{
			case 1:
				// Chama as funções de listar produtos, consultar produtos e adicionar pedidos
				listar_produtos(produtos, *tamanho);
	
				printf("\nDigite o código do produto que deseja adicionar: ");
				scanf("%d", &codigo);
				
				// Busca o produto pelo código
				produto = get_produto(produtos, codigo, *tamanho);
				if (produto)
				{
					system("cls");
					consultar_produtos(produto);
					adicionar_pedidos(pedidos, produto, *tam);
					*tam = *tam + 1;
				}
				
				getch();
				break;
			case 2:
				// Chama a função listar produtos e colsultar pedidos
				listar_produtos(pedidos, *tam);

				printf("\nDigite o código do produto que deseja consultar no pedido: ");
				scanf("%d", &codigo);
				
				// Busca o produto pelo código
				pedido = get_produto(pedidos, codigo, *tam);
				if (pedido)
				{
					// Busca posição no vetor
					int posicao = get_posicao(pedidos, pedido, *tam);
					consultar_pedidos(pedido, posicao);
				}
				
				getch();
				break;
			case 3:
			// Chama as funções de listar produtos e excluir produtos
			listar_produtos(pedidos, *tam);

			printf("\nDigite o código do produto que deseja excluir no pedido: ");
			scanf("%d", &codigo);

			// Busca o produto pelo código
			pedido = get_produto(pedidos, codigo, *tam);
			if (pedido)
			{
				// Busca posição no vetor
				int posicao = get_posicao(pedidos, pedido, *tam);
				excluir_produtos(pedidos, posicao, *tam);
				*tam = *tam - 1;
			}
			
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
}

#endif
