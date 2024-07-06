#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

typedef pair<int, string> StatePair; // creates a custom class

int bfs(int n, int m, string& initialSymptoms, vector<int>& days, vector<string>& removes, vector<string>& sideEffects) {
    queue<StatePair> q;
    unordered_set<string> visited;

    q.push(StatePair(0, initialSymptoms));
    visited.insert(initialSymptoms);

    while (!q.empty()) {
        StatePair current = q.front();
        q.pop();

        int currentDays = current.first;
        string currentSymptoms = current.second;

        if (currentSymptoms.find('1') == string::npos) {
            return currentDays;
        }

        for (int i = 0; i < m; ++i) {
            string nextSymptoms = currentSymptoms;

            // Apply the medicine's removal and side effects
            for (int j = 0; j < n; ++j) {
                if (removes[i][j] == '1') {
                    nextSymptoms[j] = '0';
                }
                if (sideEffects[i][j] == '1') {
                    nextSymptoms[j] = '1';
                }
            }

            if (visited.find(nextSymptoms) == visited.end()) {
                visited.insert(nextSymptoms);
                q.push(StatePair(currentDays + days[i], nextSymptoms));
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string initialSymptoms;
        cin >> initialSymptoms;

        vector<int> days(m);
        vector<string> removes(m), sideEffects(m);

        for (int i = 0; i < m; ++i) {
            cin >> days[i] >> removes[i] >> sideEffects[i];
        }

        cout << bfs(n, m, initialSymptoms, days, removes, sideEffects) << endl;
    }

    return 0;
}
