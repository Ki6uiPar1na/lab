#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    // Vector of (priority, burst_time, PID)
    vector<tuple<int, int, string>> processes;

    // For storing results
    map<string, int> completionTime, waitingTime, turnaroundTime;

    for (int i = 0; i < n; i++) {
        string pid;
        int burst, priority;
        in >> pid >> burst >> priority;
        processes.push_back({priority, burst, pid});
    }

    // Sort by priority (lower number = higher priority)
    sort(processes.begin(), processes.end());

    int currentTime = 0;
    for (auto &[priority, burst, pid] : processes) {
        waitingTime[pid] = currentTime;
        currentTime += burst;
        completionTime[pid] = currentTime;
        turnaroundTime[pid] = completionTime[pid];  // Since arrival time is 0
    }

    // Output
    out << "PID\tBT\tPriority\tCT\tTAT\tWT\n";
    for (auto &[priority, burst, pid] : processes) {
        out << pid << '\t'
            << burst << '\t'
            << priority << '\t' 
            << completionTime[pid] << '\t'
            << turnaroundTime[pid] << '\t'
            << waitingTime[pid] << '\n';
    }

    return 0;
}
