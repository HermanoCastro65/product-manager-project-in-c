#ifndef  STRUCTS_H
#define  STRUCTS_H

	 typedef struct produto {
	 	char descricao[40]; 
	 	int codigo, qtd_estoque; 
		float preco;  
	 }Produtos, *PProdutos, **PPProdutos;

#endif  
