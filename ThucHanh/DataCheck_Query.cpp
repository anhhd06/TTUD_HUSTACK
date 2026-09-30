#include<bits/stdc++.h>
using namespace std;

//Hàm check SĐT hợp lệ không
bool checkNB(string NB){
    if(int(NB.size()) != 10) return false;
    for(int i=0;i<NB.size();i++){
        if( NB[i] > '9' || NB[i] < '0') return false;
    }
    return true;
}


// Hàm tính thời gian mỗi cuộc gọi
int TimeCall(string ftime,string etime){
    int seconds = 0 ;
    seconds += 3600* ( stoi(etime.substr(0,2)) - stoi(ftime.substr(0,2)) );
    seconds += 60 * ( stoi(etime.substr(3,2)) - stoi(ftime.substr(3,2)) );
    seconds += stoi(etime.substr(6,2)) - stoi(ftime.substr(6,2));
    return seconds;
}


map<string,int> numberCalls, timeCallFrom;
bool checkNum = true;
int numCall = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string type,fNum,tNum,Date ,fTime,eTime;
    cin >> type;
    while(type!="#"){
        cin >> fNum >> tNum >> Date >> fTime >> eTime;
        if(checkNum){
            if( checkNB(fNum) == 0 || checkNB(tNum) == 0 ) checkNum = false;
        }
        numCall ++;
        numberCalls[fNum] ++ ;
        timeCallFrom[fNum] += TimeCall(fTime,eTime);
        cin >> type;
    }
    string query;
    cin >> query;
    while(query != "#"){
        if(query == "?check_phone_number"){
            if(checkNum) cout<< 1 << endl;
            else cout<< 0 << endl;
        }
        else if(query == "?number_calls_from"){
            string num;
            cin>> num;
            cout<< numberCalls[num] <<endl;
        }
        else if(query == "?number_total_calls"){
            cout << numCall << endl;
        }
        else if(query == "?count_time_calls_from"){
            string num;
            cin >> num;
            cout<< timeCallFrom[num] << endl;
        }
        cin >> query;
    }
}
