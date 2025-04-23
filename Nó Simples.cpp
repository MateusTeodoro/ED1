#include <stdio.h>

struct Node {
    int value;        // valor do nó
    Node* next;       // ponteiro para o próximo nó

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct List {
    Node* start;  // início da lista
    Node* end;    // fim da lista

    List() {
        start = NULL;
        end = NULL;
    }

    // Verifica se a lista está vazia
    bool empty() {
        return start == NULL;
    }

    // Insere um valor no final da lista
    void pushBack(int value) {
        Node* n = new Node(value);
        if (empty()) {
            start = n;
            end = n;
        } else {
            end->next = n;
            end = n;
        }
    }

    // Imprime todos os elementos da lista
    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
    }
};

int main() {
    List minhaLista;

    // Inserindo valores
    minhaLista.pushBack(10);
    minhaLista.pushBack(20);
    minhaLista.pushBack(30);

    // Mostrando os valores
    printf("Minha lista encadeada:\n");
    minhaLista.print();

    return 0;
}
