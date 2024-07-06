/*
For the next 𝑚 months, starting with no money, 
Charlie will work hard and earn 𝑥 pounds per month. 
For the 𝑖-th month (1≤𝑖≤𝑚), there'll be a single opportunity of paying cost 𝑐𝑖 pounds 
to obtain one unit of happiness. You cannot buy more than one unit each month.

Borrowing is not allowed. 
Money earned in the 𝑖-th month can only be spent in a later 𝑗-th month (𝑗>𝑖).
*/

/*
first line : t
followed by t test cases
months, salary
cost for each month
*/

/*
1. cant buy in first month
2. one variable to store total savings
3.
*/

/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void happiness(int m, int sal){
    int sav = 0; 
    int cost = 0;
    
    //priority_queue<int, vector<int>, greater<int> > min_heap;
    int units = 0;

    for (int i = 0; i < m; i++) {
        cin >> cost;
        //min_heap.push(cost);

        if (sav >= cost) { //min_heap.top()
            units++;
            sav = sav - cost; //min_heap.top();
            //min_heap.pop();
        }

        sav = sav + sal;
        //cout << "savings " << sav << endl;
        //cout << "units " << units << endl;
    }
    cout << units << endl ;

}

int main(){

    int t;
    cin >> t;

    for (int case_num = 0; case_num < t; case_num++) {

        int m, sal;

        cin >> m >> sal;

        happiness(m, sal);

    }

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int m, x;
        cin >> m >> x;
        
        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }
        
        int maxHappiness = 0;
        priority_queue<int> Q;
        int budget = 0;
        
        for (int i = 0; i < m; ++i) {
            if (budget >= c[i]) {
                Q.push(-c[i]);
                budget -= c[i];
            } else if (!Q.empty() && -Q.top() > c[i]) {
                budget += -Q.top() - c[i];
                Q.pop();
                Q.push(-c[i]);
            }
            budget += x;
        }
        
        maxHappiness = Q.size();
        cout << maxHappiness << "\n";
    }
    
    return 0;
}