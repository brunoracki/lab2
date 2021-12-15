#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
template <typename T> class Stack {
   template <typename V> struct StackElement {
      V item;
      StackElement<V> *next;
   };
   StackElement<T> *top = nullptr;
 public:
   bool push(T item) {
      StackElement<T> *newElement = new (nothrow) StackElement<T>;
      if (newElement == nullptr)
         return false;
      newElement->item = item;
      newElement->next = top;
      top = newElement;
      return true;
   }
};

int main() { 
   Stack<int> *stack = new Stack<int>;
   srand(time(NULL));
   for(int i = 0; i < 101; i++){
      int temp = rand() % 101 + 1;
      cout << i << ". " << temp << "\n";
      stack->push(temp);
   }
   delete stack; 
   return 0; 
   }