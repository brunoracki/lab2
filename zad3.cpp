#include <iostream>
#include <stdlib.h>
#include <time.h>
template <typename T> class Stack {
 private:
   static const int MAX = 100;
   T stack[MAX];
   int top = -1;

 public:
   bool push(T item) {
      if (top >= MAX - 1)
         return false;
      stack[++top] = item;
      return true;
   }
};

int main() {
   srand(time(NULL));
   Stack<int> *stack = new Stack<int>;

   int temp;
   for (int i = 0; i < 105; i++) {
      temp = rand() % 1000;
      std::cout << i + 1 << " " << stack->push(temp) << " " << std::endl;
   }
   delete stack;
   return 0;
}