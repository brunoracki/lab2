#include <iostream>

template <typename T> class Lista {
   template <class V> struct Cvor {
      V element;
      Cvor<V> *next;
   };
   Cvor<T> *head = nullptr;

 public:
   bool upis(T element) {
      Cvor<T> *newElement = new (std::nothrow) Cvor<T>; // pravimo čvor
      if (!newElement)
         return false;
      newElement->element = element;
      newElement->next = nullptr;
      Cvor<T> **p = &head;
      for (; (*p) && (*p)->element < element; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }
   void ispis() {
      Cvor<T> **p = &head;
      for (; *p; p = &((*p)->next)) {
         std::cout << (*p)->element << " ";
      }
      return;
   }
};
int main() {
   Lista<int> *lista = new Lista<int>;
   std::cout << "Upisite broj elemenata koji zelite upisati u listu > ";
   int n;
   std::cin >> n;
   std::cout << "Upisite elemente > ";
   int temp;
   for (int i = 0; i < n; i++) {
      std::cin >> temp;
      lista->upis(temp);
   }
   std::cout << "Ispis liste: " << std::endl;
   lista->ispis();
   delete lista;
   return 0;
}
