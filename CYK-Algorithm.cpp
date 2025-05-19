#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

map<string, set<string>> productions;
vector<vector<set<string>>> table;

void parseGrammar(const vector<string>& rules) {
    for (const string& rule : rules) {
        size_t arrow = rule.find("->");
        string left = rule.substr(0, arrow - 1);
        string right = rule.substr(arrow + 3);

        stringstream ss(right);
        string production;
        while (getline(ss, production, '|')) {
            productions[production].insert(left);
        }
    }
}

set<string> combine(const set<string>& a, const set<string>& b) {
    set<string> result;
    for (const string& s1 : a) {
        for (const string& s2 : b) {
            string combined = s1 + s2;
            if (productions.count(combined)) {
                result.insert(productions[combined].begin(), productions[combined].end());
            }
        }
    }
    return result;
}

void printTable(const vector<vector<set<string>>>& table, const string& input) {
    int n = input.size();

    cout << "|";
    for (char c : input) {
        cout << c << "|";
    }
    cout << endl;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n - row; ++col) {
            cout << "|";
            if (table[row][col].empty()) {
                cout << " ";
            } else {
                for (const string& var : table[row][col]) {
                    cout << var << ",";
                }
                cout << "\b ";
            }
        }
        cout << "|" << endl;
    }
}

int main() {
    int numRules;
    vector<string> grammar;
    string input;

    cout << "Masukkan jumlah aturan grammar (CNF): ";
    cin >> numRules;
    cin.ignore(); 

    cout << "Masukkan aturan grammar (format: S -> AB):\n";
    for (int i = 0; i < numRules; ++i) {
        string rule;
        getline(cin, rule);
        grammar.push_back(rule);
    }

    cout << "Masukkan string input: ";
    cin >> input;

    parseGrammar(grammar);

    int n = input.size();
    table = vector<vector<set<string>>>(n, vector<set<string>>(n));

    for (int i = 0; i < n; ++i) {
        string ch(1, input[i]);
        if (productions.count(ch)) {
            table[0][i] = productions[ch];
        }
    }

    for (int l = 2; l <= n; ++l) { 
        for (int s = 0; s <= n - l; ++s) { 
            for (int p = 1; p < l; ++p) {
                set<string> left = table[p - 1][s];
                set<string> right = table[l - p - 1][s + p];
                set<string> combined = combine(left, right);
                table[l - 1][s].insert(combined.begin(), combined.end());
            }
        }
    }

    printTable(table, input);

    return 0;
}
