#include <iostream>

using namespace std;
template <typename T> class Queue {
 private:
   template <class V> struct Cvor {
      Cvor<V> *next;
      T item;
   };
   Cvor<T> *read = nullptr;
   Cvor<T> *write = nullptr;

 public:
   bool enqueue(double item) {
      Cvor<double> *newElement = new (nothrow) Cvor<double>;
      if (newElement == nullptr)
         return false;
      newElement->item = item;
      newElement->next = nullptr;
      if (write == nullptr) {
         read = newElement;
      } else {
         write->next = newElement;
      }
      write = newElement;
      return true;
   }
   bool dequeue(double &item) {
      if (read == nullptr)
         return false;
      item = read->item;
      Cvor<double> *tmp = read;
      read = read->next;
      if (read == nullptr)
         write = nullptr;
      delete tmp;
      return true;
   }
};

int main() {
   cout << "Unesite 8 realnih brojeva > ";
   Queue<double> *queue = new Queue<double>;
   for (int i = 0; i < 8; ++i) {
      double temp;
      cin >> temp;
      queue->enqueue(temp);
   }
   cout << "Ispis: ";
   for (int i = 0; i < 8; i++) {
      double item;
      queue->dequeue(item);
      cout << item << " ";
   }
   delete queue;
   return 0;
}