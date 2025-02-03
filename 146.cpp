/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string line;
    while (1) {
        getline(cin, line);
        if (line == "#") break;
        string lcopy(line);
        sort (lcopy.begin(), lcopy.end());
        next_permutation(line.begin(), line.end());
        cout << (line == lcopy ? "No Successor" : line) << endl;
    }
    return 0;
}