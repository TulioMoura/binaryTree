#include<iostream>
using namespace std;

struct node {
	int value;
	node* left = NULL;
	node* rigth = NULL;
};

struct tree {
	node* root = NULL; //nó raiz da arvore, é um ponteiro para um endereço de memória que armazena um nó raiz da árvore
	void create();
	void addNode(int value); //prototipo da função addNode que adicionará um node na posição correta seguindo a regra da árvore binária
	//node find();
	//pre order
	//in order
	//post order   
};

void tree::create(){
	root = new node;
	
}

void tree::addNode(int value) {
		if (root == NULL) {
			root = new node; //crio um novo node para acomodar o valor, caso o valor no nó raiz seja nulo
			root->left == NULL; // inicio ambos os ponteiros left e rigth como nulos 
			root->rigth == NULL;
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
						previous->left->rigth = NULL;
						return;
					}
				}
				else{ //caso o nó atual (previous) for menor que o valor que queremos inserir
					if (previous->rigth != NULL) { //caso o nó a direita estiver preenchido, ele passará a ser o atual
						previous = previous->rigth;
					}
					else {   // caso seja null inserimos o nó `a direita do nó atual
						previous->rigth = new node;
						previous->rigth->value = value;
						previous->rigth->left = NULL;
						previous->rigth->rigth = NULL;
						return;
					}
				}
			}
		}
	}


void print(node* root ) {
		if (root== NULL) {
			return;
		}
		else{
			cout << root->value<<endl;
			print(root->rigth);
			print(root->left);
			}
		}
	
int main() {
	int arr[15] = { 12, 140, 426, 121, 296, 414, 362, 417, 105, 330, 119, 55, 182, 240, 24 };
	tree novaArvore;
	novaArvore.create();

	for (int i = 0; i < 15; i++) {
		novaArvore.addNode(arr[i]);
	}
	print(novaArvore.root);


}
