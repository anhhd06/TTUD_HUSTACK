#include<bits/stdc++.h>
using namespace std;
int totalSubmiss = 0,numErrSub = 0;
map<string,int> numErrOfUser;
map<string, map<string,int > > PointOfProblem;
vector <string> Time;

void numSubInTime(string from,string to){
    int count;
    auto it_start = lower_bound(Time.begin(),Time.end(),from);
    auto it_end = upper_bound(Time.begin(),Time.end(),to);
    count = distance(it_start,it_end);
    cout<< count << endl;
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
    sort(Time.begin(),Time.end());
    solve();

}