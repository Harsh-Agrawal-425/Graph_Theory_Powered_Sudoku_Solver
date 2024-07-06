#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
using namespace std;

class Medicine{
    public:
        int days;
        int effects;
        int s_effects;
        static int dijsktra(int n, int m, int i_sympt, vector<Medicine> &medicines){

            int final_condition = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> p;
            unordered_map<int, int> min_possible_days;

            p.push({0, i_sympt});
            min_possible_days[i_sympt] = 0;
            
            while (!p.empty()) {
                int current_days = p.top().first;
                int current_condition = p.top().second;
                p.pop();

                if (current_condition == final_condition) {
                    return current_days;
                }

                for (const auto& medicine : medicines) {
                    int nextState = current_condition;
                    nextState &= ~medicine.effects;
                    nextState |= medicine.s_effects;

                    int nextDays = current_days + medicine.days;
                    if (min_possible_days.find(nextState) == min_possible_days.end() || nextDays < min_possible_days[nextState]) {
                        min_possible_days[nextState] = nextDays;
                        p.push({nextDays, nextState});
                    }
                }
        }

        return -1;
        }
};

int main(){

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;

        string sympt;
        cin >> sympt;

        int i_sympt =  stoi(sympt, 0, 2);

        vector<Medicine> medicines(m);
        for(int i = 0; i < m; i++){
            cin >> medicines[i].days;

            string effect, s_effect;
            cin >> effect >> s_effect;

            medicines[i].effects = stoi(effect, 0, 2);
            medicines[i].s_effects = stoi(s_effect, 0, 2);
        }
        int minimum_days = Medicine::dijsktra(n, m, i_sympt, medicines);
        cout << minimum_days << endl;
    }

    return 0;
}