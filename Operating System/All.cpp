#include <bits/stdc++.h>
using namespace std;

void roundRobin(vector<pair<string, int>> processes, int quantum) {
    map<string, int> remainingTime;
    map<string, int> completion;

    for (auto& p : processes)
        remainingTime[p.first] = p.second;

    int currentTime = 0;
    bool done = false;

    while (!done) {
        done = true;
        for (auto& p : processes) {
            string pid = p.first;
            int& rem = remainingTime[pid];

            if (rem > 0) {
                done = false;

                if (rem > quantum) {
                    currentTime += quantum;
                    rem -= quantum;
                } else {
                    currentTime += rem;
                    rem = 0;
                    completion[pid] = currentTime;
                }
            }
        }
    }

    cout << "\n--- Round Robin Scheduling (Quantum = " << quantum << ") ---\n";
    for (auto& p : processes) {
        string pid = p.first;
        int bt = p.second;
        int ct = completion[pid];
        int tat = ct;
        int wt = tat - bt;

        cout << "PID: " << pid
             << " | CT: " << ct
             << " | TAT: " << tat
             << " | WT: " << wt << '\n';
    }
}

// FCFS Scheduling
void fcfs(vector<pair<string, int>> processes) {
    map<string, int> completion, turnaround, waiting;
    int currentTime = 0;

    cout << "\n--- FCFS Scheduling ---\n";
    for (auto& p : processes) {
        string pid = p.first;
        int bt = p.second;

        currentTime += bt;
        completion[pid] = currentTime;
        turnaround[pid] = completion[pid];
        waiting[pid] = turnaround[pid] - bt;

        cout << "PID: " << pid
             << " | CT: " << completion[pid]
             << " | TAT: " << turnaround[pid]
             << " | WT: " << waiting[pid] << '\n';
    }
}

// SJF Scheduling
void sjf(vector<pair<string, int>> processes) {
    sort(processes.begin(), processes.end(), [](auto& a, auto& b){
        return a.second < b.second; // sort by burst time
    });

    map<string, int> completion, turnaround, waiting;
    int currentTime = 0;

    cout << "\n--- SJF Scheduling ---\n";
    for (auto& p : processes) {
        string pid = p.first;
        int bt = p.second;

        currentTime += bt;
        completion[pid] = currentTime;
        turnaround[pid] = completion[pid];
        waiting[pid] = turnaround[pid] - bt;

        cout << "PID: " << pid
             << " | CT: " << completion[pid]
             << " | TAT: " << turnaround[pid]
             << " | WT: " << waiting[pid] << '\n';
    }
}

// Round Robin Scheduling (Non-preemptive-style with fixed quantum)
void roundRobin(vector<pair<string, int>> processes, int quantum) {
    map<string, int> remainingTime;
    map<string, int> completion;

    for (auto& p : processes)
        remainingTime[p.first] = p.second;

    int currentTime = 0;
    bool done = false;
    while (!done) {
        done = true;
        for (auto& p : processes) {
            string pid = p.first;
            int& rem = remainingTime[pid];

            if (rem > 0) {
                done = false;

                if (rem > quantum) {
                    currentTime += quantum;
                    rem -= quantum;
                } else {
                    currentTime += rem;
                    rem = 0;
                    completion[pid] = currentTime;
                }
            }
        }
    }

    cout << "\n--- Round Robin Scheduling (Quantum = " << quantum << ") ---\n";
    for (auto& p : processes) {
        string pid = p.first;
        int bt = p.second;
        int ct = completion[pid];
        int tat = ct;
        int wt = tat - bt;

        cout << "PID: " << pid
             << " | CT: " << ct
             << " | TAT: " << tat
             << " | WT: " << wt << '\n';
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<pair<string, int>> processes;
    cout << "Enter PID and Burst Time:\n";
    for (int i = 0; i < n; i++) {
        string pid;
        int bt;
        cin >> pid >> bt;
        processes.push_back({pid, bt});
    }

    int quantum;
    cout << "Enter Time Quantum for Round Robin: ";
    cin >> quantum;

    fcfs(processes);
    sjf(processes);
    roundRobin(processes, quantum);

    return 0;
}
