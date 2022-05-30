#include <iostream>
#include <locale.h>
using namespace std;

struct node {
	int value;
	node* left = NULL;
	node* right = NULL;
};

struct tree {
	node* root = NULL; // Nó raiz da arvore, é um ponteiro para um endereço de memória que armazena um nó raiz da árvore
	void create();
	void addNode(int value); // Protótipo da função addNode que adicionará um node na posição correta seguindo a regra da árvore binária
	void print(node* node, int order); // Protótipo da função print, esta imprime a árvore em ordem, pré-ordem ou pós-ordem conforme seus argumentos
	void find(int value); // Protótipo da função find. Imprime na tela o valor do nó especificado assim como o valor de seus nós filhos
};

void tree::create(){
	root = new node; // Inicia a árvore com um nó vazio
}

void tree::addNode(int value) {
		if (root == NULL) {
			root = new node; //crio um novo node para acomodar o valor, caso o valor no nó raiz seja nulo
			root->value = value;
			root->left = NULL; // inicio ambos os ponteiros left e rigth como nulos 
			root->right = NULL;
		}
		else {
			node * previous = root; //define o nó  previous( anterior ) como o root para navegarmos na árvore e encontrar o ponto correto para inserção
			while (1) { // loop infinito que checará os valores dos nós folha até coincidir com a condição
				if (value < previous->value) { //caso o nó atual (previous) for maior que o valor que queremos inserir
					if (previous->left != NULL) { //caso o nó a esquerda estiver preenchido, ele passará a ser o atual
 						previous = previous->left;
					}
					else { // caso seja null inserimos o nó à esquerda do nó atual
						previous->left = new node;
						previous->left->value = value;
						previous->left->left = NULL;
						previous->left->right = NULL;
						return;
					}
				}
				else{ //caso o nó atual (previous) for menor que o valor que queremos inserir
					if (previous->right != NULL) { //caso o nó a direita estiver preenchido, ele passará a ser o atual
						previous = previous->right;
					}
					else {   // caso seja null inserimos o nó `a direita do nó atual
						previous->right = new node;
						previous->right->value = value;
						previous->right->left = NULL;
						previous->right->right = NULL;
						return;
					}
				}
			}
		}
	}

void tree::find(int value) {

	node* aux_node = root;

	while (true)
	{	
		if (value == aux_node->value)
		{
			printf("\n\nO valor do nó é: %d\nSeu nó filho à esquerda tem o valor de: %d\nSeu nó filho à direita tem o valor de: %d\n\n", aux_node->value, aux_node->left->value, aux_node->right->value);
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
			break;

		case 2: // Print em Pré-ordem
				if (node == NULL) return;

				cout << node->value << "  ";
				print(node->left, 2);
				print(node->right, 2);
			break;
		case 3: // Print em Pós-ordem
				if (node == NULL) return;

				print(node->left, 3);
				print(node->right, 3);
				cout << node->value << "  ";
			break;
	}
}
	
int main() {

	setlocale(LC_ALL, "");

	// ======================= Adicionando valores de teste à árvore ==============================

	int arr[15] = { 12, 140, 426, 121, 296, 414, 362, 417, 105, 330, 119, 55, 182, 240, 24 };
	tree novaArvore;
	novaArvore.create();

	for (int i = 0; i < 15; i++) {
		novaArvore.addNode(arr[i]);
	}

	// ============================================================================================

	int option; // Variável auxiliar para conter a opção escolhida pelo usuário no menu
	
	// Menu interativo com o usuário
	do
	{ 
		system("CLS");
		cout << "=============================== MENU ===========================" << endl;
		cout << "(1) - Adicionar um nó;" << endl;
		cout << "(2) - Imprimir a árvore;" << endl;
		cout << "(0) - SAIR" << endl;
		cout << "================================================================" << endl;
		cout << "\nDigite o código da opção desejada: ";
		cin >> option;
		
		switch (option) // A partir da opção escolhida pelo usuário, a função switch redireciona a execução do código ao bloco correspondente
		{
			case 1: // Caso a escolha do usuário seja adicionar um nó
					system("CLS");
					cout << "===================== Adicionar Nó ========================" << endl;
					cout << "Digite o valor a ser adicionado à árvore: ";
					int value;
					cin >> value;
					novaArvore.addNode(value);
					system("CLS");
					cout << "===========================================================" << endl;
					cout << "                        Nó Adicionado                      " << endl;
					cout << "===========================================================" << endl;
					system("PAUSE");
				break;

			case 2: // Caso a escolha do usuário seja Imprimir a árvore
					system("CLS");
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
					system("PAUSE");
				break;
			
			case 0: // Para o caso de saída da aplicação
				break;
			
			default: // Caso a opção digitada seja inválida

					system("CLS");
					cout << "===========================================================" << endl;
					cout << "                  Digite uma opção válida                  " << endl;
					cout << "===========================================================" << endl;
					system("PAUSE");

				break;
			}

	} while (option != 0); // Fim do loop caso o usuário escolha sair da aplicação
	
	system("PAUSE");
	system("CLS");
	return 0;

}
