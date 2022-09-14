#ifndef  STRUCTS_H
#define  STRUCTS_H

	 typedef struct produto {
	 	char descricao[100]; 
	 	int codigo, qtd_estoque; 
		float preco;  
	 }Produtos, *PProdutos, **PPProdutos;

#endif  
