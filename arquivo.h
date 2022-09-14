#ifndef  ARQUIVO_H
#define  ARQUIVO_H

	#include <string.h>
	
	void ler_arquivo(PPProdutos produtos, int *tamanho){
		FILE *file;
  
  		//abrindo o arquivo
  		file = fopen("arquivo.txt", "r");
  		
  		if(file == NULL){
  			printf("\nNão foi possível ler o arquivo.\n");
  			getchar();
  			exit(1);
  		}
      
		while(!feof(file)){
			produtos[*tamanho] = (PProdutos) malloc(sizeof(Produtos));   
	        if (produtos[*tamanho] == NULL){
	           printf("\n\nMemoria insuficiente\n\n");
	           exit(1);           
	        }
	        
	        char buff[5];
	        if(produtos[*tamanho]){
				fgets(produtos[*tamanho]->descricao, sizeof(produtos[*tamanho]->descricao), file);
		        produtos[*tamanho]->codigo = *tamanho;
				fscanf(file, "%d %f", &produtos[*tamanho]->qtd_estoque, &produtos[*tamanho]->preco);
				fgets(buff, sizeof(buff), file);
		    	*tamanho = *tamanho + 1;	        			
			}
		};

  		// fechando arquivo
  		fclose(file);
  		
  		printf("\nARQUIVO LIDO COM SUCESSO \n");
	}

#endif  
