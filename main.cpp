#include <iostream>
using std::cout;

void addWithCuda(int* c, int* a, int* b, int size);

int main()
{
    unsigned long long size = 1 << 14; // 2^28
    int* a = new int[size];
    int* b = new int[size];
    int* c = new int[size];

    for (int i = 0; i < size; i++) {
        a[i] = i * 2;
        b[i] = i * 3;
    }

    while (true) {
        addWithCuda(c, a, b, size);
        for (int i = 0; i < 20; i++) {
            cout << c[i] << " ";
        }
        cout << "\n";
    }


    delete[] a;
    delete[] b;
    delete[] c;

    cout << "Good Bye\n";
    return 0;
}