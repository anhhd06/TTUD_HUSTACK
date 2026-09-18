#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N],S[N],n,Q;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>> a[i];
    }
}
// tong Sk = a1 + a2 + a3 . ... + ak
void tinhtong(){
    S[0] = 0;
    for(int i=1;i<=n;i++){
        S[i]=S[i-1] + a[i];
    }

}
void output(){
    cin >> Q;
    for(int k=1;k<=Q;k++){
        int i,j;
        cin>>i>>j;
        cout<< S[j] - S[i-1] << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    tinhtong();
    output();

}