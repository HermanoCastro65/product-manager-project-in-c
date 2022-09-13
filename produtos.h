#ifndef  PRODUTOS_H
#define  PRODUTOS_H

    #include <stdio.h>
	#include "structs.h"
	
	void incluir_produtos(PPProdutos produtos, int tamanho){
		system("cls");
		printf("\nINCLUIR PRODUTOS: \n");
		
       	produtos[tamanho] = (PProdutos) malloc(sizeof(Produtos));   
        if (produtos[tamanho] == NULL){
           printf("\n\nMemoria insuficiente\n\n");
           exit(1);           
        }
      
      	if (produtos[tamanho]){
	      	produtos[tamanho]->codigo = tamanho;
	        printf("\nInforme a descri��o do Produto: "); 
	        scanf(" %[^\n]",produtos[tamanho]->descricao);
			printf("Informe a quantidade em estoque do Produto: "); 
	        scanf("%d",&produtos[tamanho]->qtd_estoque);  
	        printf("Informe o pre�o do Produto: ");   
	        scanf("%f",&produtos[tamanho]->preco);   
			printf("\nCONCLU�DO \n");   
		}
	}
	
	void alterar_produtos(){
		printf("\n alterar");
	}
	void excluir_produtos(){
		printf("\n excluir");
	}
	void consultar_produtos(){
		printf("\n consultar");
	}
	
	void listar_produtos(PPProdutos produtos, int tamanho){
		system("cls");
		printf("\nLISTAR PRODUTOS: \n");
		
		int i;
		for(i = 0; i < tamanho; i++){
			printf("\n C�digo: %d", produtos[i]->codigo);
			printf("\n Descri��o: %s", produtos[i]->descricao);
			printf("\n Pre�o: R$ %.2f", produtos[i]->preco);
			printf("\n Quantidade em Estoque: %d\n", produtos[i]->qtd_estoque);
		}
		printf("\nCONCLU�DO \n");
	}

#endif  
