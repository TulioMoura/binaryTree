#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include<unistd.h>
using namespace std;

struct node {
    int value;
    node* left = NULL;
    node* right = NULL;
};

struct tree {
    node* root = NULL; // Nó raiz da arvore, é um ponteiro para um endereço de memória que armazena um nó raiz da árvore
    void create();
    node *addNode(node* no_atual, int value); // Protótipo da função addNode que adicionará um node na posição correta seguindo a regra da árvore binária
    void print(node* node, int order); // Protótipo da função print, esta imprime a árvore em ordem, pré-ordem ou pós-ordem conforme seus argumentos
    void find(int value); // Protótipo da função find. Imprime na tela o valor do nó especificado assim como o valor de seus nós filhos
};

void tree::create(){
    root = new node; // Inicia a árvore com um nó vazio
}

node* tree::addNode(node* current_node, int value1){
   	 

	if(current_node == NULL){
    	current_node = new node;
    	current_node->value = value1;
    	current_node->left = NULL;
    	current_node->right = NULL;
   	 
    	return current_node;
	}else{
    	if(value1 > current_node->value){
        	current_node->right = addNode(current_node->right, value1);
    	}else
    	if(value1 < current_node->value){
        	current_node->left = addNode(current_node->left, value1);
    	}   
	}
    return current_node;
}

void tree::find(int value) {

    node* aux_node = root;

    while (true)
    {    
   	 if (value == aux_node->value)
   	 {
   		 cout << ("\n\nO valor do nó é: %d\nSeu nó filho à esquerda tem o valor de: %d\nSeu nó filho à direita tem o valor de: %d\n\n", aux_node->value, aux_node->left->value, aux_node->right->value);
   		 break;
   	 }
   	 else
   	 if (value < aux_node->value)
   	 {
   		 aux_node = aux_node->left;
   	 }
   	 else
   	 if (value > aux_node->value)
   	 {
   		 aux_node = aux_node->right;
   	 }    
    }
}

void tree::print(node* node, int order) {

    switch (order) // A execução do código é redirecionada ao bloco correspondente à escolha do usuário (order)
    {
   	 case 1: // Print em ordem
   			 if (node == NULL) return;

   			 print(node->left, 1);
   			 cout << node->value << "  ";
   			 print(node->right, 1);
   			 sleep(5);
   		 break;

   	 case 2: // Print em Pré-ordem
   			 if (node == NULL) return;

   			 cout << node->value << "  ";
   			 print(node->left, 2);
   			 print(node->right, 2);
   			 sleep(5);
   		 break;
   	 case 3: // Print em Pós-ordem
   			 if (node == NULL) return;

   			 print(node->left, 3);
   			 print(node->right, 3);
   			 cout << node->value << "  ";
   			 sleep(5);
   		 break;
    }
}
    
int main() {

    setlocale(LC_ALL, "");


    // ======================= Adicionando valores de teste à árvore ==============================

    int arr[15] = { 121, 296, 414, 362, 417, 105, 330, 119, 55, 182, 240, 24 };
    tree novaArvore;
    novaArvore.create();

    for (int i = 0; i < 15; i++) {
   	 novaArvore.addNode(novaArvore.root, arr[i]);
    }

    // ============================================================================================

    int option; // Variável auxiliar para conter a opção escolhida pelo usuário no menu
    
    
    do // Menu interativo com o usuário
    {
   	 system("clear");
   	 cout << "=============================== MENU ===========================" << endl;
   	 cout << "(1) - Adicionar um nó;" << endl;
   	 cout << "(2) - Imprimir a árvore;" << endl;
   	 cout << "(3) - Encontrar um valor na árvore;" << endl;
   	 cout << "(0) - SAIR" << endl;
   	 cout << "================================================================" << endl;
   	 cout << "\nDigite o código da opção desejada: ";
   	 cin >> option;
   	 
   	 switch (option) // A partir da opção escolhida pelo usuário, a função switch redireciona a execução do código ao bloco correspondente
   	 {
   		 case 1: // Caso a escolha do usuário seja adicionar um nó
   				 system("clear");
   				 cout << "===================== Adicionar Nó ========================" << endl;
   				 cout << "Digite o valor a ser adicionado à árvore: ";
   				 int value;
   				 cin >> value;
   				 novaArvore.addNode(novaArvore.root, value);
   				 system("clear");
   				 cout << "===========================================================" << endl;
   				 cout << "                    	Nó Adicionado                  	" << endl;
   				 cout << "===========================================================" << endl;
   				 //system("PAUSE");
   			 break;

   		 case 2: // Caso a escolha do usuário seja Imprimir a árvore
   				 system("clear");
   				 cout << "===================== Imprimir ========================" << endl;
   				 cout << "(1) - Imprimir em Ordem" << endl;
   				 cout << "(2) - Imprimir em Pré-ordem" << endl;
   				 cout << "(3) - Imprimir em Pós-ordem" << endl;
   				 cout << "=========================================================" << endl;
   				 cout << "Digite uma opção para a impressão da árvore: ";
   				 int order;
   				 cin >> order;
   				 
   				 novaArvore.print(novaArvore.root, order);
   				 cout << endl;
   				 //system("PAUSE");
   			 break;

   		 case 3:

   				 cout << "===================== Encontrar ========================" << endl;
   				 cout << "Encontra o valor de um nó especificado na árvore" << endl;
   				 cout << "=========================================================" << endl;
   				 cout << "Digite uma opção para a impressão da árvore: ";
   				 cin >> value;
   				 system("clear");
   				 novaArvore.find(value);
   				 //system("PAUSE");

   			 break;
   		 
   		 case 0: // Para o caso de saída da aplicação
   			 break;
   		 
   		 default: // Caso a opção digitada seja inválida

   				 system("clear");
   				 cout << "===========================================================" << endl;
   				 cout << "              	Digite uma opção válida              	" << endl;
   				 cout << "===========================================================" << endl;
   				 //system("PAUSE");

   			 break;
   		 }

    } while (option != 0); // Fim do loop caso o usuário escolha sair da aplicação
    
    //system("PAUSE");
    system("clear");
    return 0;

}


