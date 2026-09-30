#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int n,v;
string S;
void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v;
        s.insert(v);
    }
}
void solve(){
    while(1){
        cin >> S;
        if( S == "min_greater_equal" ){
            cin >> v;
            auto it = s.lower_bound(v);
            if(it!=s.end()){
                cout << *it << endl;
            }
            else cout << "NULL" << endl;
        }
        else if( S == "min_greater"){
            cin >> v;
            auto it = s.upper_bound(v);
            if(it!=s.end()){
                cout << *it << endl;
            }
            else cout << "NULL" << endl;
        }
        else if(S=="insert"){
            cin >> v;
            s.insert(v);
        }
        else if( S=="remove" ){
            cin >> v;
            s.erase(v);

        }
        else break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;
}