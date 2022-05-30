#include <iostream>
#include <locale.h>
#include <stdlib.h>

#ifdef __unix__ 
        #define clearT  "clear" 
    #elif _WIN32 
        #define clearT  "CLS" 
    #endif

using namespace std;

void clear(){

}

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
    node *find(int value); // Protótipo da função find. Imprime na tela o valor do nó especificado assim como o valor de seus nós filhos
	node *remove(node*parent, int value); //Protótipo da função remove, que remove um node da árvore e retorna uma nova subárvore sem esse valor.
	node *findBiggest(node * root); //Protótipo da função findBiggest, que retorna um ponteiro para o node de maior valor da árvore
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

node* tree::find(int value) {

    node* aux_node = root;

    while (true)
    {
	if(aux_node == NULL){
		return NULL;
		break;
	}
   	else if (value == aux_node->value)
   	 {
   		 return aux_node;
   		 break;
   	 }
   	 else if (value < aux_node->value)
   	 {
   		 aux_node = aux_node->left;
   	 }
   	 else if (value > aux_node->value)
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

node * tree::findBiggest(node * root){
	if(root->right == NULL){
		return root;
	}
	else{
		return findBiggest(root->right);
	}
}    
node * tree::remove(node*parent, int value){
	if(parent==NULL){
		return NULL;
	}
	else if(parent->value == value){
		if(	parent->left == NULL && parent->right == NULL){
			return NULL;
		}
	else if(parent->left == NULL && parent->right!=NULL){
		return parent->right;
	}
	else if(parent->right == NULL && parent->left!=NULL){
		return parent->left;
	}
	else{
		node * temp =  findBiggest(parent);
		cout<<temp->value;
		remove(parent, temp->value);
		temp->left = parent->left;
		temp->right = parent->right;
		//delete parent;
		return temp; 
	}

	}

	else if(parent->value > value){
		parent->left =  remove(parent->left, value);
		return parent;
	}
	else if(parent->value < value){
	parent -> right = remove(parent->right, value);
	return parent;
	}
}
int main() {
	char temp; //variável temporaria para evitar o uso do system("pause")
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
node*isFind = NULL;
    
    do // Menu interativo com o usuário
    {
   	system(clearT);
   	cout << "=============================== MENU ===========================" << endl;
   	cout << "(1) - Adicionar um nó;" << endl;
   	cout << "(2) - Imprimir a árvore;" << endl;
   	cout << "(3) - Encontrar um valor na árvore;" << endl;
	cout << "(4) - Remover um valor da árvore;" << endl;  
   	cout << "(0) - SAIR" << endl;
   	cout << "================================================================" << endl;
   	cout << "\nDigite o código da opção desejada: ";
   	cin >> option;
	
   	 
   	switch (option) // A partir da opção escolhida pelo usuário, a função switch redireciona a execução do código ao bloco correspondente
   	{
		
   		case 1: // Caso a escolha do usuário seja adicionar um nó

   				system(clearT);
		        cout << "===================== Adicionar Nó ========================" << endl;
   				cout << "Digite o valor a ser adicionado à árvore: ";
   				int value;
   				cin >> value;
   				novaArvore.addNode(novaArvore.root, value);
   				system(clearT);
   				cout << "===========================================================" << endl;
   				cout << "                    	Nó Adicionado                  	" << endl;
   				cout << "===========================================================" << endl;
   				cout<<"Pressione uma tecla para continuar ";
				cin>>temp;
				
				//#ifdef _WIN32 
                //   system("PAUSE"); 
                //#endif
   			 break;

   		case 2: // Caso a escolha do usuário seja Imprimir a árvore
   				system(clearT);
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
   				cout<<"Pressione uma tecla para continuar ";
				cin>>temp;
				//#ifdef _WIN32 
                //   system("PAUSE"); 
                //#endif
   			break;

   		case 3:

   				cout << "===================== Encontrar ========================" << endl;
   			    cout << "Encontra o valor de um nó especificado na árvore" << endl;
   			    cout << "=========================================================" << endl;
   				cout << "Digite um valor a ser encontrado na árvore";
   				cin >> value;
   				isFind = novaArvore.find(value);
				   if(isFind==NULL){
					   cout<<"O valor não foi encontrado"<<endl;
				   }
				   else{
					   cout<<"o valor está no endereço "<<&isFind<<endl;
					   cout<<"e seus nós filhos são: ";
					   if(isFind->left!=NULL){
						     cout<<isFind->left->value;
					   }
					   else{
							cout<<"NULL";
					   }
					   cout<<" e ";
					   if(isFind->right!=NULL){
						   cout<<isFind->right->value<<endl;
					   }
					   else{
						   cout<<"NULL";
					   }   
				}
   				cout<<"Pressione uma tecla para continuar ";
				cin>>temp;   
				//#ifdef _WIN32 
                //   system("PAUSE"); 
                //#endif

   			break;

   		case 4:	
		   		system(clearT);
		   		cout << "======================= Remover =========================" << endl;
   			    cout << "Remove um valor da estrutura da árvore" << endl;
   			    cout << "=========================================================" << endl;
   				cout << "Atualmente a árvore tem a seguinte estrutura: "<<endl;
   				novaArvore.print(novaArvore.root, 1);
				cout<<endl;
				cout << "=========================================================" << endl;
				cout << "Digite um valor para ser removido da árvore ";
				cin >> value;
				isFind = novaArvore.find(value);
				if(isFind==NULL){
					   cout<<"Valor Inválido";
				}
				else{
					novaArvore.root = novaArvore.remove(novaArvore.root, value);
				}

				cout<<"Pressione uma tecla para continuar ";
				cin>>temp;
				
			break;

   		case 0: // Para o caso de saída da aplicação
   			break;
   		 
   		default: // Caso a opção digitada seja inválida

   				
   				cout << "===========================================================" << endl;
   				cout << "              	Digite uma opção válida              	" << endl;
   				cout << "===========================================================" << endl;
   				cout<<"Pressione uma tecla para continuar ";
				cin>>temp;
				//#ifdef _WIN32 
                //   system("PAUSE"); 
                //#endif

   			break;
   		}

    }while (option != 0); // Fim do loop caso o usuário escolha sair da aplicação
    
    cout<<"Pressione uma tecla para continuar ";
	cin>>temp;
	//#ifdef _WIN32 
    //    system("PAUSE"); 
    //#endif
    system(clearT);
    return 0;

}