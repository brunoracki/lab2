#include <iostream>

void Zamijeni(std::string *prvi, std::string *drugi)
{
    std::string temp = *prvi;
    *prvi = *drugi;
    *drugi = temp;
}

void BubbleSortPoboljsani(std::string A[], int N, int smjer)
{
    bool swapped = true;
    for (int i = 0; swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (smjer == 1)
            { // uzlazno sortiranje
                if (A[j + 1] < A[j])
                {
                    Zamijeni(&A[j + 1], &A[j]);
                    swapped = true;
                }
            }
            else
            {
                if (A[j + 1] > A[j])
                {
                    Zamijeni(&A[j + 1], &A[j]);
                    swapped = true;
                }
            }
        }
    }
}

int main(void)
{
    static const int MAX = 4;
    std::string *A = new std::string[4];

    for (int i = 0; i < MAX; i++)
    {
        std::cout << "Upisite " << i + 1 << ". string: ";
        std::getline(std::cin, A[i]);
    }

    int smjer;
    std::cout << "Upisite zeljeni smjer sortiranja (0/1): ";
    std::cin >> smjer;

    BubbleSortPoboljsani(A, MAX, smjer);

    std::cout << "{";
    for (int i = 0; i < MAX - 1; i++)
    {
        std::cout << "\"" << A[i] << "\", ";
    }
    std::cout << "\"" << A[MAX - 1] << "\"}" << std::endl;

    delete[] A;

    return 0;
}