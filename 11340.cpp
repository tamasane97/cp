#include <iostream>
#include <map>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	int k, m;
	map<char, long long> cmap;
	char c;
	long long val;
	string line;
	long long int total;

	while (cases--) {
		cin >> k;
		cin.ignore();

		cmap.clear();
		while (k--) {
			c = cin.get();
			cin >> val;
			cmap[c] = val;
			cin.ignore();
		}

		cin >> m;
		cin.ignore();

		total = 0;
		while (m--) {
			getline(cin, line);
			for (char ch: line) total += cmap[ch];
		}

		cout << total / 100  << '.' << (total/10)%10 << total%10 << '$' << endl;
	}

	return 0;
}