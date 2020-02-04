#include <iostream>
using namespace std;
#include "ArrayList.h"
#include "LinkedList.h"
#include "BinaryTree.h"

template<class T>
void citeste(List<T> *list, int n = 0) {
    T val;
    for(int i = 0; i < ((n == 0) ? list->size() : n); i++) {
        printf("Introduceti valoare pentru x[%d]: ", i);
        scanf("%d", &val);
        list->push(val);
    }
}

template<class T>
void scrie(List<T> *list) {
    list->print();
}

template<class T>
int inserare(List<T> *list, T elem_nou, int k) {
    list->push(k, elem_nou);
    return list->size();
} 

template<class T>
int eliminare(List<T> *list, int k) {
    list->remove(k);
    return list->size();
}

int main() {

    Tree<int>* binary = new BinaryTree<int>();
    binary->insert(10);
    binary->insert(8);
    binary->insert(15);
    binary->insert(4);
    binary->insert(20);
    binary->insert(12);
    binary->insert(2);
    binary->insert(6);
    binary->insert(13);
    binary->print();
    TreeNode<int>* node = binary->search(12);
    printf("Value searched: %d", node->key_value );
    binary->destroy_tree();

    return 0;

    int n, i, val, elem_nou, k;
    char c;
    printf("Specifica marime lista: ");
    scanf("%d", &n);
    List<int> *myList = new LinkedList<int>();
    citeste(myList, n);
    scrie(myList);
    

    printf("\nIntroduceti indicile elementului pe care doriti sa il accesati: ");
    scanf("%d", &i);

    printf("\nAti accesat elementului: x[%d]=%d", i, myList->get(i));
    printf("\nDoriti sa il modificati? (Y/N) ");
    rewind(stdin);
    c = getchar();
    if(c == 'Y' || c == 'y') {
        printf("\nIntroduceti noua valoare: ");
        scanf("%d", &val);
        myList->replace(i, val);
        printf("\nSirul este acum\n");
        scrie(myList);
    }
    
    //Inserare unui element: elem_nou intr-o pozitide data k
    printf("Introduceti elementul pe care vreti sa il adaugati in lista si positia\n");
    scanf("%d %d", &elem_nou, &k);
    n = inserare(myList, elem_nou, k);
    printf("Sirul este acum\n");
    scrie(myList);

    
    //Eliminarea elementului de indice k din lista
    printf("Introduceti pozitia elementului pe care vreti sa-l stergeti din lista: ");
    scanf("%d", &k);
    n = eliminare(myList, k);
    printf("Sirul este acum\n");
    scrie(myList);
    
    
    return 0;

}