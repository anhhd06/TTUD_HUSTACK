#include<bits/stdc++.h>
using namespace std;
int totalSubmiss = 0,numErrSub = 0;
map<string,int> numErrOfUser;
map<string, map<string,int > > PointOfProblem;
vector <string> Time;


int TimeCall(string ftime,string etime){
    int seconds = 0 ;
    seconds += 3600* ( stoi(etime.substr(0,2)) - stoi(ftime.substr(0,2)) );
    seconds += 60 * ( stoi(etime.substr(3,2)) - stoi(ftime.substr(3,2)) );
    seconds += stoi(etime.substr(6,2)) - stoi(ftime.substr(6,2));
    return seconds;
}


void numSubInTime(string start,string end){
    int count = 0;
    for(int i=0;i<Time.size();i++){
        if(TimeCall(start,Time[i]) >= 0 && TimeCall(Time[i],end) >= 0) count ++;
    }
    cout << count << endl;
}

void totalPoint(string UserID){
    int total = 0;
    for(const auto & x : PointOfProblem[UserID]) 
        total += x.second ;
    cout<< total << endl;
}
void input(){
    string UserID,ProblemID,TimePoint,Status,Point;
    cin >> UserID;
    while(UserID != "#"){
        cin >> ProblemID >> TimePoint >> Status >> Point;
        if(Status == "ERR"){
            numErrSub ++;
            numErrOfUser[UserID] ++;
        }
        PointOfProblem[UserID][ProblemID] = max(PointOfProblem[UserID][ProblemID],stoi(Point) );
        Time.push_back(TimePoint);
        totalSubmiss ++;
        cin >> UserID;
    }
}

void solve(){
    string query;
    cin >> query ;
    while(query != "#"){
        if( query == "?total_number_submissions") cout<< totalSubmiss <<endl;
        else if( query == "?number_error_submision") cout << numErrSub << endl;
        else if( query == "?number_error_submision_of_user"){
            string UserID;
            cin>> UserID;
            cout << numErrOfUser[UserID] << endl;
        }
        else if ( query == "?total_point_of_user"){
            string UserID;
            cin>> UserID;
            totalPoint(UserID);
        }
        else if( query == "?number_submission_period"){
            string from,to;
            cin >> from >> to;
            numSubInTime(from,to);
        }
        cin >> query;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();

}