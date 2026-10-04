#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N][N],n,m,r,c;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
void input(){
    cin >> n>>m >> r >> c;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> a[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}