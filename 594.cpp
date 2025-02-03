#include <iostream>
#include <format>

using namespace std;

int main() {
    int a; 
    char *c = (char*)&a;

    while (cin >> a) {
        cout << a << " converts to ";
        swap(c[0], c[3]);
        swap(c[1], c[2]);
        cout << a << endl;
    }

    return 0;
}