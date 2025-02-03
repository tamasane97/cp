#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

void readIntLine(vector<int>& nums) {
    string line;
    getline(cin, line);
    istringstream is(line);

    nums = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}

void readDoubleLine(vector<string>& nums) {
    string line;
    getline(cin, line);
    istringstream is(line);

    nums = vector<string>(istream_iterator<string>(is), istream_iterator<string>());
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    string blankline;
    bool first = true;

    while (t--) {
        getline(cin, blankline);

        if (!first) cout << "\n";
        first = false;

        vector<int> firstLine;
        vector<string> secondLine;
        readIntLine(firstLine);
        readDoubleLine(secondLine);

        vector<string> orginalLine(secondLine.size());

        for (int i=0; i<secondLine.size(); i++)
            orginalLine[firstLine[i]-1] = secondLine[i];
        
        for (int i=0; i<orginalLine.size(); i++)
            cout << orginalLine[i] << endl;
    }
}