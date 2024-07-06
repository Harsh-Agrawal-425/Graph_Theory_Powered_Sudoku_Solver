//here i have start drom the first month and simply if able to buy buy and if not able to buy check if the preivously bought month with highest momey is greater than the current month then that will be replaced with the current month

#include<iostream>
#include<queue>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int m,x;cin>>m>>x;

        int c[m];
        for (int i = 0; i < m; i++) cin>>c[i];
        int cur = 0;
        priority_queue<int> pq;
        for (int i = 0; i < m; i++){
            if(cur>=c[i]){
                cur-=c[i];
                pq.push(c[i]);
            }else{
                if(!pq.empty()){
                    if(pq.top()>c[i]){
                        cur+=pq.top();
                        pq.pop();
                        cur-=c[i];
                        pq.push(c[i]);
                    }
                }
            }
            cur+=x;
        }
        cout<<pq.size()<<endl;
    }
}