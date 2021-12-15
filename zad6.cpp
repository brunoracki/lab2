#include <iostream>

using namespace std;

class Queue {
   static const int MAX = 10;
   double queue[MAX];
   int read = 0;
   int write = 0;

 public:
   bool enqueue(double item) {
      if ((write + 1) % MAX == read)
         return false;
      queue[write] = item;
      write = (write + 1) % MAX;
      return true;
   }
   bool dequeue(double &item) {
      if (write == read) // if the queue is empty
         return false;
      item = queue[read];
      read = (read + 1) % MAX;
      return true;
   }
};

int main() {
    cout << "Unesite 8 realnih brojeva > ";
   Queue *queue = new Queue;
   for (int i = 0; i < 8; ++i) {
      double temp;
      cin >> temp;
      queue->enqueue(temp);
   }
   cout << "Ispis: "; 
   for(int i = 0; i < 8; i++){
       double item;
       queue->dequeue(item);
       cout << item << " ";
   }
   delete queue;
   return 0;
}