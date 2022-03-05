#include "lab04.h"

void printContainer(myContainer cont) {
    if (cont.N==0) {    //sprawdza czy kontener nie jest pusty
        std::cout<<"Cannot print empty Container."<<std::endl;
        return;
    }
    
    if (cont.N>MAX_SIZE) {  //jezeli rozmiar jest za duzy to poprawia na MAX_SIZE
        cont.N=MAX_SIZE;
    }
    
    std::cout<<"[";             //wypisanie zawartosci cont
    for(int i=0;i<cont.N;i++) {
        std::cout<<cont.array[i];
        if (i!=cont.N-1) {
            std::cout<<",";
        }
    }
    std::cout<<"]";
    
    return;
}

int fibonacci(int n) {  //funkcja zwracajaca n-ty wyraz ciagu Fibonacciego
    if (n<2)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int fillContainerWithFibonacci(myContainer *cont, int size) {
    if (!cont) {    //sprawdza czy cont istnieje
        std::cout<<"Empty pointer provided."<<std::endl;
        return 0;
    }
    
    if (size<1 || size>MAX_SIZE) {  //sprawdza czy rozmiar jest poprawny
        std::cout<<"Wrong number of dimensions."<<std::endl;
        return 0;
    }

    cont->N=size;           //zapisuje nowy rozmiar

    for(int i=0;i<cont->N;i++) {
        cont->array[i] = fibonacci(i);  //zapisuje ciag do cont
    }
    
    return 1;
}

int checkTwin(myContainer *a, myContainer *b) { //funkcja sprawdzajaca czy a i b to blizniaki
    if (!a || !b) {         //zwraca 0 jezeli a lub b nie istnieje
        return 0;
    }
    
    if (a->N != b->N) {     //zwraca 0 jezeli sa roznych rozmiarow
        return 0;
    }
    
    if (a->N<0) {           //zwraca 0 jezeli rozmiar jest niepoprawny
        return 0;
    }
    
    for(int i=0;i<a->N;i++) {   //zwraca 0 jezeli ktorys element jest inny
        if (a->array[i]!=b->array[i])
            return 0;
    }
    
    return 1;       //zwraca 1 gdy nie wykryto roznic
}

void checkContainerSpouse(myContainer *cont) {
    if (!cont) {    //sprawdza czy cont istnieje
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
    if (cont->spouse) {     //1 przypadek: cont ma spouse
        printContainer(*cont);
        std::cout<<" is paired with ";
        printContainer(*(cont->spouse));
        std::cout<<std::endl;
    }
    else {                  //2 przypadek cont nie ma spouse
        printContainer(*cont);
        std::cout<<" has no spouse."<<std::endl;
    }
    return;
}

void marry(myContainer *a, myContainer *b) {
    if (!a || !b) {     //sprawdza czy a i b istnieja
        std::cout<<"Empty pointer provided."<<std::endl;
        return;    
    }
    
    if (a==b) {         //sprawdza czy a i b to to samo
        std::cout<<"Can't marry myself"<<std::endl;
        return;
    }
    
    if (checkTwin(a,b)) {   //sprawdza czy a i b sa blizniakami
        std::cout<<"Can't marry my twin"<<std::endl;
        return;
    }
    
    //jezeli nie ma bledu to a i b staja sie malzenstwem
    a->spouse=b;
    b->spouse=a;
    
    return;
}

void divorce(myContainer *a, myContainer *b) {
    if (a) {    //jezeli istnieje a to usuwa jego malzonka
        a->spouse=nullptr;
    }
    
    if (b) {    //jezeli istnieje b to usuwa jego malzonka
        b->spouse=nullptr;
    }
}

void printParents(myContainer *cont) {
    if (!cont) {    //sprawdza czy cont istnieje
        std::cout<<"Empty pointer provided."<<std::endl;
        return;
    }
    
     
    if (cont->parent_a && cont->parent_b) {     //1 przypadek: cont ma 2 rodzicow
        std::cout<<"Parents of ";
        printContainer(*cont);
        std::cout<<" are ";
        printContainer(*(cont->parent_a));
        std::cout<<" and ";
        printContainer(*(cont->parent_b));
        std::cout<<std::endl;
        return;
    }
    
    if (cont->parent_a==nullptr && cont->parent_b==nullptr) {   //2 przypadek: cont nie ma zadnego rodzica
        printContainer(*cont);
        std::cout<<" has no parents."<<std::endl;
    }
    
    return;
}

myContainer formChild(myContainer *a, myContainer *b) {
    myContainer child;      //tworzymy dziecko ktore jak na razie jest puste
 
    if (!a && !b) {     //przypadek 1: a i b nie istnieja
        std::cout<<"I ain't God."<<std::endl;
        return child;
    }


    if (a && b) {       //przypadek 2: a i b istnieje
        if (a->spouse != b || b->spouse != a) { //sprawdza czy rodzice sa malzenstwem
            std::cout<<"Only spouses may have children."<<std::endl;
            return child;
        }
    
        if (a->N + b->N>MAX_SIZE) {     //sprawdza czy dziecko nie bedzie za duze
            std::cout<<"Parents are too big"<<std::endl;
            return child;
        }
        
        child.N=a->N + b->N;            //zapisuje rozmiar dziecka
        for(int i=0;i<a->N;i++) {       //kopiuje dane do dziecka
            child.array[i] = a->array[i];
        }
        for(int i=a->N;i<child.N;i++) {
           child.array[i] = b->array[i-a->N];
        }
        child.parent_a=a;               //zapisuje informacje o rodzicach
        child.parent_b=b;   
        return child;                   //zwraca dziecko
    }
    
    //przypadek 3: istnieje tylko a albo tylko b
    std::cout<<"No partenogenesis possible."<<std::endl;
    return child;
}
