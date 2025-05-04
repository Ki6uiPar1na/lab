#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<pair<int, string>> process; // (burst_time, PID)
    map<string, int> completionTime, waitingTime;

    for (int i = 0; i < n; i++) {
        string pid;
        int burst;
        in >> pid >> burst;
        process.push_back({burst, pid});
    }

    // Sort by burst time (SJF)
    sort(process.begin(), process.end());

    int time = 0;
    for (int i = 0; i < n; i++) {
        int burst = process[i].first;
        string pid = process[i].second;

        waitingTime[pid] = time;         // WT is current time before execution
        time += burst;
        completionTime[pid] = time;      // CT is time after execution
    }

    // Output
    out << "PID\tCT\tWT\n";
    for (auto &[burst, pid] : process) {
        out << pid << '\t' << completionTime[pid] << '\t' << waitingTime[pid] << '\n';
    }

    return 0;
}
