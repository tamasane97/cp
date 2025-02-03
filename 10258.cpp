/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=30&page=show_problem&problem=1199

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>


using namespace std;

int main() {
    int cases;

    cin >> cases;
    cin.ignore();

    struct Coder {
        int cid;
        set<int> problems_solved;
        map<int,int> problems_attempted;
        int penalty_time = 0;
    };

    map<int, int> mp;
    vector<struct Coder*> vec;
    string line;
    int k, id, pid, ptime;
    char presult;
    bool first = true;
    cin.ignore();

    while (cases--) {
        k = 0;
        mp.clear();
        vec.clear();
        while (getline(cin, line)) {
            if (line.size() == 0) break;
            stringstream ss(line);
            ss >> id >> pid >> ptime >> presult;
            if (!mp.count(id)) { mp[id] = k++; vec.push_back(new Coder()); vec[mp[id]]->cid = id; }

            if (presult == 'I') { vec[mp[id]]->problems_attempted[pid] += 20; }
            else if (presult == 'C') { 
                if (vec[mp[id]]->problems_solved.count(pid)>0) continue;
                vec[mp[id]]->penalty_time += (ptime + vec[mp[id]]->problems_attempted[pid]);  
                vec[mp[id]]->problems_solved.insert(pid); 
            }
        }

        sort (vec.begin(), vec.end(), [](const struct Coder* a, const struct Coder* b)->bool  {
            return a->problems_solved.size() == b->problems_solved.size() ? 
                        a->penalty_time == b->penalty_time ?
                            a->cid < b->cid :
                            a->penalty_time < b->penalty_time :
                        a->problems_solved.size() > b->problems_solved.size();
        });

        if (!first) cout << endl;
        first = false;

        for (int i=0; i<k; i++) {
            struct Coder* curr = vec[i];
            cout << curr->cid << ' ' << curr->problems_solved.size() << ' ' << curr->penalty_time << endl;
        }
    }

    return 0;
}