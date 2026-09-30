#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N],n,m,M[20][N];
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}
void pre(){
    for(int i=0;i<n;i++){
        M[0][i] = i;
    }
    for(int i=1;i<=log2(n);i++){
        for(int j=0 ; j + (1 << i) -1 < n ; j++){
            if ( a[ M[i-1][j] ] < a[ M[i-1][j + (1 <<(i-1))] ] ) M[i][j] = M[i-1][j];
            else M[i][j] = M[i-1][j + (1 <<(i-1))] ;
        }
    }
}
void solve(){
    cin >> m;
    int i,j,sum = 0;
    for(int u=1;u<=m;u++){
        cin >> i >> j;
        int k = log2(j-i+1);
        if(a[ M[k][i] ] < a[ M[k][j - (1 << k) +1] ] ) sum+= a[  M[k][i] ];
        else sum+= a[ M[k][j - (1 << k) + 1 ] ] ;
    }
    cout << sum ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pre();
    solve();
}