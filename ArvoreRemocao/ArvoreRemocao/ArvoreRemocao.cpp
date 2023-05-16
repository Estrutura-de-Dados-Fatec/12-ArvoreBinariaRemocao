#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* esq;
	NO* dir;
};

NO* raiz = NULL;


// headers
// estrutura principal
void menu();
void inicializar();
void inserir();
void exibir();
void exibirQuantidade();
void buscar();
void remover();



// funcoes auxiliares Arvore
NO* insereArvore(NO* no, int valor);
NO* criaNO(int valor);
int elementosArvore(NO* no);
void exibirElementosArvore(NO* no);
void buscarElementoArvore(NO* no, int valor);
NO* buscarElementoArvoreComPai(NO* no, int valor, NO*& pai);
void removerElementoArvore(NO* no, int valor);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Arvore";
		cout << endl << endl;
		cout << "1 - Inicializar Arvore \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Inserir elemento \n";
		cout << "4 - Exibir elementos \n";
		cout << "5 - Buscar elemento \n";
		cout << "6 - Remover elemento \n";
		cout << "7 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:exibirQuantidade();
			break;
		case 3: inserir();
			break;
		case 4: exibir();
			break;
		case 5: buscar();
			break;
		case 6: remover();
			break;

		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// provis�rio porque n�o libera a memoria usada pela arvore
	raiz = NULL;

	cout << "Arvore inicializada \n";

}


void inserir()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (raiz == NULL) {
		raiz = criaNO(valor);
	}
	else {
		insereArvore(raiz, valor);
	}


}

void exibirQuantidade() {
	cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;

}

void exibir() {
	exibirElementosArvore(raiz);
}

void buscar() {
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	buscarElementoArvore(raiz, valor);
}

void remover() {

	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	removerElementoArvore(raiz, valor);
}



NO* criaNO(int valor)
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

NO* insereArvore(NO* no, int valor)
{
	if (no->valor > valor && no->esq == NULL) {
		no->esq = criaNO(valor);
		return no->esq;
	}
	else if (no->valor < valor && no->dir == NULL) {
		no->dir = criaNO(valor);
		return no->dir;
	}
	else if (no->valor > valor) {
		return insereArvore(no->esq, valor);
	}
	else if (no->valor < valor) {
		return insereArvore(no->dir, valor);
	}
	else {
		return NULL;
	}


}

int elementosArvore(NO* no)
{
	if (no == NULL) {
		return 0;
	}

	return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO* no)
{
	if (no == NULL) {
		return;
	}

	cout << no->valor << endl;
	exibirElementosArvore(no->esq);
	exibirElementosArvore(no->dir);

}

void buscarElementoArvore(NO* no, int valor)
{
	if (no == NULL) {
		cout << "Elemento nao encontrado \n";
		return;
	}

	if (no->valor == valor) {
		cout << "Elemento encontrado \n";
		return;
	}

	if (valor < no->valor) {
		buscarElementoArvore(no->esq, valor);
	}
	else {
		buscarElementoArvore(no->dir, valor);
	}
}


// versao nao recursiva
NO* buscarElementoArvoreComPai(NO* no, int valor, NO*& pai)
{
	NO* atual = no;
	pai = NULL;
	while (atual != NULL) {
		if (valor == atual->valor) {
			return atual;
		}
		else {
			pai = atual;

			if (valor < atual->valor) {
				atual = atual->esq;
			}
			else {
				atual = atual->dir;
			}
		}
	}
	return NULL;
}



void removerElementoArvore(NO* no, int valor) {
	NO* pai = NULL;
	NO* atual = buscarElementoArvoreComPai(no, valor, pai);

	if (atual == NULL) {
		cout << "Elemento nao encontrado \n";
		return;
	}

	// Caso 1: remoção de um nó sem filhos
	if (atual->esq == NULL && atual->dir == NULL) {
		if (pai == NULL) {
			raiz = NULL;
		}
		else if (pai->esq == atual) {
			pai->esq = NULL;
		}
		else {
			pai->dir = NULL;
		}

		free(atual);
	}
	// Caso 2: remoção de um nó com apenas um filho
	else if (atual->esq == NULL || atual->dir == NULL) {
		NO* filho = (atual->esq != NULL) ? atual->esq : atual->dir;
		if (pai == NULL) {
			raiz = filho;
		}
		else if (pai->esq == atual) {
			pai->esq = filho;
		}
		else {
			pai->dir = filho;
		}

		free(atual);
	





