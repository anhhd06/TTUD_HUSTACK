#include<bits/stdc++.h>
using namespace std;
queue<int> q;
string operration;
int x;
void solve(){
    while (1)
    {
        cin >> operration ;
        if(operration == "#") break;
        else if (operration == "PUSH")
        {
           cin >> x;
           q.push(x); 
        }
        else
        {
            if(q.empty()){
                cout << "NULL" <<endl;
            }
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    
}
int main(){
    solve();
    return 0;
}