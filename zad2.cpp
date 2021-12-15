#include <iostream>

template <typename T> class Lista {
   template <typename V> struct Cvor {
      V element;
      Cvor<V> *next;
      Cvor<V> *previous;
   };

   Cvor<T> *head = nullptr;
   Cvor<T> *tail = nullptr;

 public:
   bool upis(T element) {
      Cvor<T> *newElement = new (std::nothrow) Cvor<T>;
      if (newElement == nullptr)
         return false;

      newElement->element = element;
      newElement->previous = tail;
      newElement->next = nullptr;

      if (tail == nullptr)
         head = newElement;
      else
         tail->next = newElement;

      tail = newElement;
      return true;
   }
   void ispis() {
      for (Cvor<T> **p = &head; *p; p = &((*p)->next)) {
         std::cout << (*p)->element << " ";
      }
   }
};

int main() {
   Lista<std::string> *lista = new Lista<std::string>;
   std::cout << "Upisite broj elemenata koji zelite upisati u listu > ";
   int n;
   std::cin >> n;
   std::cout << "Upisite elemente > ";
   std::string temp;
   for (int i = 0; i < n; i++) {
      std::cin >> temp;
      lista->upis(temp);
   }
   std::cout << "Ispis liste: " << std::endl;
   lista->ispis();
   delete lista;
   return 0;
}
