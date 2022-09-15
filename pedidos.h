#ifndef PEDIDOS_H
#define PEDIDOS_H

void adicionar_pedidos(PPProdutos pedidos, PProdutos produto, int tam)
{
	printf("\nADICIONAR PEDIDOS: \n");
	
	int qtd;
	printf("\n Informe a quantidade que deseja adicionar: ");
	scanf("%d", qtd);
	if(qtd <= produto->qtd_estoque)
	{
		pedidos[tam] = produto;
		pedidos[tam]->qtd_estoque = qtd;
		produto->qtd_estoque = produto->qtd_estoque - qtd;
	} else
	{
		printf("\nQUANTIDADE FORA DE ESTOQUE \n");
	}
	
	printf("\nCONCLUÍDO \n");
}
void consultar_pedidos()
{
	printf("\n consultar");
}
void excluir_pedidos()
{
	printf("\n excluir");
}
void alterar_pedidos()
{
	printf("\n alterar");
}
void finalizar_pedidos()
{
	printf("\n finalizar");
}

#endif
