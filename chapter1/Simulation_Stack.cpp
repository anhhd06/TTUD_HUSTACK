#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ip;
    stack<int> s;
    while(1){
        cin>> ip;
        if(ip == "#") break;
        else if(ip == "PUSH"){
            int x;
            cin >> x;
            s.push(x);
        }
        else {
            if(s.empty()) cout<< "NULL"<<endl;
            else{
                cout << s.top()<<endl;
                s.pop();
            }
        }
    }

}