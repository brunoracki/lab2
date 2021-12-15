#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Queue {
 private:
   struct Cvor {
      Cvor *next;
      double item;
   };
   Cvor *read = nullptr;
   Cvor *write = nullptr;

 public:
   bool enqueue(double item) {
      Cvor *newElement = new (nothrow) Cvor;
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

   bool poljeURed(int polje[], int n) {
      if (n == 0)
         return true;
      if (this->enqueue(polje[n]) == false) {
         return false;
      }
      return poljeURed(polje, n - 1);
   }
};

int main(){
    srand(time(NULL));
    Queue *queue = new Queue;
   int *array = new int[10];
   for(int i = 0; i < 10; i++){
      int temp = rand() % 10 + 1;
      cout << i << ". " << temp << "\n";
      array[i] = temp;
   }
   cout << queue->poljeURed(array, 10);
   delete[] array;
   return 0;
}