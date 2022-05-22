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
					else { // caso seja null inserimos o nó `a esquerda do nó atual
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

	switch (order)
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

	// ======================= Adicionando valores à árvore ==============================

	int arr[15] = { 12, 140, 426, 121, 296, 414, 362, 417, 105, 330, 119, 55, 182, 240, 24 };
	tree novaArvore;
	novaArvore.create();

	for (int i = 0; i < 15; i++) {
		novaArvore.addNode(arr[i]);
	}

	// ==================================================================================

	cout << "\n==========================================================================\n" << endl; // Espaço entre as linhas de comando e o início da função Print no terminal
	cout << "\n\nÁrvore em ordem: " << endl;
	novaArvore.print(novaArvore.root, 1); // Print em ordem
	cout << "\n\nÁrvore em Pré-ordem: " << endl;
	novaArvore.print(novaArvore.root, 2); // Print em Pré-ordem
	cout << "\n\nÁrvore em Pós-ordem: " << endl;
	novaArvore.print(novaArvore.root, 3); // Print em Pós-ordem


	novaArvore.find(414);
	
	cout << "\n==========================================================================\n" << endl; // Espaço entre as linhas de comando e o fim da aplicação no terminal

	system("PAUSE");
	return 0;

}
