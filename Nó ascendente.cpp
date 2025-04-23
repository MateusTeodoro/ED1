#include <stdio.h>

struct Node {

    int value;
    Node* next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* start;
    Node* end;
    int s;

    List() {
        start = NULL;
        end = NULL;
        s = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        end->next = n;
        end = n;
    }

    void pushFront(int value) {
        Node* n = new Node(value);
        s++;
        if (empty()) {
            start = n;
            end = n;
            return;
        }
        n->next = start;
        start = n;
    }

    void print() {
        Node* aux = start;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("NULL\n");
    }

    int size() {
        return s;
    }

    void insertSorted(int v) {
        Node* n = new Node(v);
        s++;

        // Caso especial: lista vazia ou o valor deve ser inserido no início
        if (empty() || v < start->value) {
            n->next = start;
            start = n;
            if (s == 1) end = n;
            return;
        }

        Node* current = start;
        while (current->next != NULL && current->next->value < v) {
            current = current->next;
        }

        n->next = current->next;
        current->next = n;

        if (n->next == NULL) {
            end = n;
        }
    }
};

int main() {
    List l;
    int N, valor;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &valor);
        l.insertSorted(valor);
    }

    printf("Lista em ordem crescente:\n");
    l.print();

    return 0;
}
