#include<bits/stdc++.h>
using namespace std;
int main()

{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n; 
    in >> n;
    vector<pair<string, int>> process(n);

    map<string, int> remainTime, complitionTime, waitingTime;
    queue<string> q;

    for(int i = 0; i < n; i++){
        in >> process[i].first >> process[i].second;
        remainTime[process[i].first] = process[i].second;
        q.push(process[i].first);
    }
    int timeQuantum;
    cin >> timeQuantum;

    int time = 0;
    while(!q.empty()){
        string pid = q.front();
        q.pop();
        int &remain = remainTime[pid];
        if(remain > timeQuantum){
            time += timeQuantum;
            remain -= timeQuantum;
            q.push(pid);
        }
        else{
            time += remain;
            remain = 0;
            complitionTime[pid] = time;
        }
    }
    for(auto &[pid, brust] : process){
        out << pid << ' ' << remainTime[pid] << ' ' << complitionTime[pid] << endl;
    }
    cout << endl;
}