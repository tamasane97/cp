/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=32&page=show_problem&problem=1135

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set> 
#include <strings.h>

using namespace std;


int main() {
    /// N is #tournaments, T is #team_names, G is #games
    int N, T, G, goals_a, goals_b;
    string tournament_name, team_name, game, team_a, team_b;

    struct Team {
        string team_name;
        int points_earned = 0, games_played = 0, goals_scored = 0, goals_against = 0, win_count = 0, ties = 0, losses = 0;
    };

    map<string, int> mp;
    vector<struct Team*> vec;
    bool first = true;

    cin >> N;
    cin.ignore();

    while (N--) {
        getline(cin, tournament_name);
        cin >> T;
        cin.ignore();

        int k = 0;
        vec.clear();
        mp.clear();

        while (T--) {
            getline(cin, team_name);
            mp[team_name] = k++;
            vec.push_back(new Team());
            vec[mp[team_name]]->team_name = team_name;
        }

        cin >> G;
        cin.ignore();
        
        while (G--) {
            getline(cin, game);
            int i=0;
            while (game[i] != '#') i++;
            team_a = game.substr(0, i);
            i++; // skip '#'
            goals_a = 0;
            while (game[i] != '@') goals_a = (goals_a * 10 + game[i++] - '0');
            i++; // skip '@'
            goals_b = 0;
            while (game[i] != '#') goals_b = (goals_b * 10 + game[i++] - '0');
            i++; // skip '#'
            team_b = game.substr(i);
            vec[mp[team_a]]->goals_scored += goals_a;
            vec[mp[team_a]]->goals_against += goals_b;
            vec[mp[team_b]]->goals_scored += goals_b;
            vec[mp[team_b]]->goals_against += goals_a;
            vec[mp[team_a]]->games_played += 1;
            vec[mp[team_b]]->games_played += 1;
            if (goals_a > goals_b) { vec[mp[team_a]]->points_earned += 3; vec[mp[team_a]]->win_count += 1; vec[mp[team_b]]->losses += 1; }
            else if (goals_a < goals_b) { vec[mp[team_b]]->points_earned += 3; vec[mp[team_b]]->win_count += 1; vec[mp[team_a]]->losses += 1; }
            else {
                vec[mp[team_a]]->points_earned += 1;
                vec[mp[team_b]]->points_earned += 1;
                vec[mp[team_a]]->ties += 1;
                vec[mp[team_b]]->ties += 1;
            }
        }

        sort (vec.begin(), vec.end(), [](const struct Team* a, const struct Team* b) -> bool {
            return a->points_earned == b->points_earned ?
                        a->win_count == b->win_count ? 
                            a->goals_scored - a->goals_against == b->goals_scored - b->goals_against ?
                                a->goals_scored == b->goals_scored ?
                                    a->games_played == b->games_played ? 
                                        strcasecmp(a->team_name.c_str(), b->team_name.c_str()) < 0 :
                                        a->games_played < b->games_played :
                                    a->goals_scored > b->goals_scored :
                                a->goals_scored - a->goals_against > b->goals_scored - b->goals_against :
                            a->win_count > b->win_count :
                        a->points_earned > b->points_earned;
        });

        if (!first) cout << endl;
        first = false;

        cout << tournament_name << endl;
        for (int i=0; i<k; i++) {
            struct Team* curr = vec[i];
            cout << (i+1) << ") " << curr->team_name << ' '
                 << curr->points_earned << "p, "
                 << curr->games_played << "g "
                 << '(' << curr->win_count << '-' << curr->ties << '-' << curr->losses << "), "
                 << (curr->goals_scored - curr->goals_against) << "gd "
                 << '(' << curr->goals_scored << '-' << curr->goals_against << ')' << endl;
        }
    }

    cout << endl;

    return 0;
}