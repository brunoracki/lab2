#include <iostream>

struct zapis {
   int sifra;
   std::string naziv;
};

bool operator<(zapis const &a, zapis const &b) { return a.sifra < b.sifra; }

bool operator>(zapis const &a, zapis const &b) { return a.sifra > b.sifra; }

void obicanBubbleSort(zapis A[], int n, char smjer) {
   if (smjer == '0') { // uzlazni smjer sortiranja
      for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] < A[j]) {
               zapis temp = A[j];
               A[j] = A[j + 1];
               A[j + 1] = temp;
            }
         }
      }
   } else {
      for (int i = 0; i < n - 1; i++) {
         for (int j = 0; j < n - 1 - i; j++) {
            if (A[j + 1] > A[j]) {
               zapis temp = A[j];
               A[j] = A[j + 1];
               A[j + 1] = temp;
            }
         }
      }
   }
}

int main(void) {
   int n;
   std::cout << "Upisite zeljeni broj elemenata polja: ";
   std::cin >> n;

   zapis *A = new zapis[n];
   for (int i = 0; i < n; i++) {
      zapis z;

      std::cout << "Upisite sifru za " << i + 1 << ". jelo: ";
      std::cin >> z.sifra;
      std::cin.ignore(1, '\n');
      std::cout << "Upisite naziv za " << i + 1 << ". jelo: ";
      std::getline(std::cin, z.naziv);

      A[i] = z;
   }

   char smjer;
   std::cout << "Upisite zeljeni smjer sortiranja: ";
   std::cin >> smjer;

   obicanBubbleSort(A, n, smjer);
   for (int i = 0; i < n; i++)
      std::cout << A[i].sifra << ":" << A[i].naziv << " ";
   std::cout << std::endl;

   delete[] A;

   return 0;
}