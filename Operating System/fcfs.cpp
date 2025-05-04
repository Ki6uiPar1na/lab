#include<bits/stdc++.h>
using namespace std;
int main()
{
    int numberOfProcess;
    cout << "Enter the number of process: ";
    cin >> numberOfProcess;

    vector<pair<string, int>> process(numberOfProcess + 1);
    for(int i = 1; i <= numberOfProcess; i++){
        cout << "Enter the PID & Brust Time: ";
        cin >> process[i].first >> process[i].second;
    }

    vector<int> complitionTime(numberOfProcess + 1);
    complitionTime[1] = process[1].second;

    for(int i = 2; i <= numberOfProcess; i++){
        complitionTime[i] = process[i].second + complitionTime[i - 1];
    }

    vector<int> waitingTime(numberOfProcess + 1);
    waitingTime[1] = 0;
    for(int i = 2; i <= numberOfProcess; i++){
        waitingTime[i] = complitionTime[i - 1];
    }

    for(int i = 1; i <= numberOfProcess; i++){
        cout << waitingTime[i] << ' ';
    }
    cout << endl;

    for(int i = 1; i <= numberOfProcess; i++){
        cout << complitionTime[i] << ' ';
    }
    cout << endl;


}
