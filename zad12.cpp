#include <iostream>

class Osoba
{
private:
    std::string ime;
    unsigned short int starost;
    friend bool operator<(Osoba const &a, Osoba const &b);

public:
    Osoba() {};
    Osoba(std::string ime, unsigned short int starost) : ime(ime), starost(starost) {}
    std::string getIme() { return ime; }
    unsigned short int getStarost() { return starost; }
    void setIme(std::string ime) { this->ime = ime; }
    void setStarost(unsigned short int starost) { this->starost = starost; }
    ~Osoba() { std::cout << "Obrisan/a " << this->ime << "|" << this->starost << std::endl; }

    Osoba &operator=(const Osoba &osoba)
    {
        // std::cout << &(this->ime) << " : " << &osoba.ime << std::endl;
        this->ime = osoba.ime;
        this->starost = osoba.starost;
        // std::cout << &(this->ime) << " : " << &osoba.ime << std::endl;

        return *this;
    }
};

bool operator<(Osoba const &a, Osoba const &b)
{
    if (a.starost < b.starost)
        return a.starost < b.starost;
    return a.ime[0] < b.ime[0];
}

template <typename T>
void InsertionSort(T A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        T temp = A[i];
        int j;
        for(j = i; j >= 1 && temp < A[j - 1]; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
}

int main(void)
{
    static const int MAX = 5;
    Osoba *osobe = new Osoba[MAX];
    for(int i = 0; i < MAX; i++)
    {
        std::string ime;
        std::cout << "Upišite ime " << i + 1 << ". osobe: ";
        std::getline(std::cin, ime);
        unsigned short int starost;
        std::cout << "Upisite starost " << i + 1 << ". osobe: ";
        std::cin >> starost;
        std::cin.ignore(1, '\n');
        osobe[i] = Osoba(ime, starost);
    }

    InsertionSort(osobe, MAX);

    std::cout << "{";
    for(int i = 0; i < MAX; i++)
    {
        if(i == MAX - 1)
        {
            std::cout << "{\"" << osobe[i].getIme() << "\"," << osobe[i].getStarost() << "}}" << std::endl;
            break;
        }
        std::cout << "{\"" << osobe[i].getIme() << "\"," << osobe[i].getStarost() << "},";
    }

    delete[] osobe;

    return 0;
}