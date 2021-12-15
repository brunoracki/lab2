#include <iostream>
struct Zapis {
 public:
   int postNumber;
   std::string name;
};
void insertionSort(Zapis A[], int n, char smjer) {
   // smjer == 1 silazno
   // smjer == 0 uzlazno
   if (smjer == '0') { // uzlazno
      Zapis temp;
      for (int i = 1; i < n; i++) {
         temp = A[i];
         int j;
         for (j = i; j >= 1 && A[j - 1].postNumber > temp.postNumber; j--) {
            A[j] = A[j - 1];
         }
         A[j] = temp;
      }
   } else { // silazno
      Zapis temp;
      for (int i = 1; i < n; i++) {
         temp = A[i];
         int j;
         for (j = i; j >= 1 && A[j - 1].postNumber < temp.postNumber; j--) {
            A[j] = A[j - 1];
         }
         A[j] = temp;
      }
   }
}
int main() {
   int n;
   std::cout << "Upisite koliko zapisa zelite unijeti > ";
   std::cin >> n;
   Zapis *A = new Zapis[n];
   for (int i = 0; i < n; i++) {
      Zapis z1;
      std::cout << "Unesite postanski broj " << i + 1 <<". mjesta > ";
      int postNumber;
      std::cin >> postNumber;
      std::string name;
      std::cout << "Unesite ime mjesta > ";
      std::cin >> name;
      z1.name = name;
      z1.postNumber = postNumber;
      A[i] = z1;
   }
   insertionSort(A, n, '1');
   for (int i = 0; i < n; i++) {
      std::cout << A[i].postNumber << " " << A[i].name << std::endl;
   }
   return 0;
}