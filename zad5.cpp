#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
template <class T> class Stack {
   static const int MAX = 10;
   T stack[MAX];
   int top = -1;
 public:
   bool push(T item) {
      if (top >= MAX - 1)
         return false;
      stack[++top] = item;
      return true;
   }
   bool pop(T &element) {
      if (top < 0)
         return false;
      element = stack[top];
      top--;
      return true;
   }
};
int main() {
   srand(time(NULL));
   Stack<int> *stack = new Stack<int>;
   for (int i = 0; i < 10; i++) {
      int randNum = rand() % 10 + 1;
      cout << randNum << " ";
      stack->push(randNum);
   }
   Stack<int> *temp = new Stack<int>;
   int el;
   for (int i = 0; i < 10; i++) {
      stack->pop(el);
      temp->push(el);
   }
   for (int i = 0; i < 10; i++) {
      temp->pop(el);
      cout << el << " ";
   }
   delete temp;
   delete stack;
   return 0;
}