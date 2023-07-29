#include <bits/stdc++.h>

using namespace std;

struct process
{
    string id;
    vector<int> max_need, allocation, need;
};

bool safetyAlgorithm(vector<int> work, vector<process> x)
{
    string sequence = ""; //... Safe state sequence
    int no_of_resource = work.size();
    int no_of_process = x.size();
    vector<bool> finish(no_of_process, false);

    while (true)
    {
        bool found = false;
        for (int i = 0; i < no_of_process; i++)
        {
            if (finish[i]) continue;
            bool ok = true;
            for (int j = 0; j < no_of_resource; j++)
            {
                if (x[i].need[j] > work[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                found = true;
                finish[i] = true;
                for (int j = 0; j < no_of_resource; j++)
                {
                    work[j] += x[i].allocation[j];
                }
                sequence += x[i].id + " ";
            }
        }
        if (!found) break;
    }
    for (int i = 0; i < no_of_process; i++)
    {
        if (!finish[i]) return false;
    }
    cout << sequence << "\n";
    return true;
}

int main()
{
    int no_of_resource; //... Total number of resources
    cin >> no_of_resource;
    vector<int> available(no_of_resource);
    for (int &value: available)
    {
        cin >> value; //... Total number of each available resource instances
    }

    int no_of_process; //... Total number of processes
    cin >> no_of_process;
    vector<process> x(no_of_process); //... Process descriptions
    for (int i = 0; i < no_of_process; i++)
    {
        x[i].max_need.resize(no_of_resource); //... Vector max_need size = no_of_resource
        x[i].allocation = x[i].need = x[i].max_need;
        cin >> x[i].id;
        for (int j = 0; j < no_of_resource; j++)
        {
            cin >> x[i].allocation[j]; //... Total already allocated resources
        }
        for (int j = 0; j < no_of_resource; j++)
        {
            cin >> x[i].max_need[j]; //... Maximum number resources a process can request
            x[i].need[j] = x[i].max_need[j] - x[i].allocation[j];
        }
    }

    if (safetyAlgorithm(available, x))
    {
        cout << "The system is in a safe state\n";
    }
    else cout << "The system is not in a safe state!\n";

    //... Resource-Request algorithm
    int process_id; //... Process's ID which is requesting resources 
    vector<int> requests(no_of_resource); //... No of request of each resource type

    cin >> process_id;
    for (int i = 0; i < no_of_resource; i++)
    {
        cin >> requests[i];
        if (requests[i] > x[process_id].max_need[i])
        {
            cout << "Request exceeds maximum need. Can't accept request!";
            return 0;
        }
        else if (requests[i] > available[i])
        {
            cout << "Request exceeds available resources. Can't accept request!";
            return 0;
        }
        available[i] -= requests[i];
        x[process_id].allocation[i] += requests[i];
        x[process_id].need[i] -= requests[i]; 
    }
    
    if (safetyAlgorithm(available, x))
    {
        cout << "Safe State exists. So, the resources are allocated";
    }
    else
    {
        cout << "The process must wait & old resource-allocation state is restored";
        for (int i = 0; i < no_of_resource; i++)
        {
            available[i] += requests[i];
            x[process_id].allocation[i] -= requests[i];
            x[process_id].need[i] += requests[i]; 
        }
    }
}

/*//... Sample Input-Output:
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
3
3 3 2
5
T0   0 1 0   7 5 3
T1   2 0 0   3 2 2
T2   3 0 2   9 0 2
T3   2 1 1   2 2 2
T4   0 0 2   4 3 3
4
3 3 0
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
T1 T3 T4 T0 T2 
The system is in a safe state
The process must wait & old resource-allocation state is restored
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Input:
3
3 3 2
5
T0   0 1 0   7 5 3
T1   2 0 0   3 2 2
T2   3 0 2   9 0 2
T3   2 1 1   2 2 2
T4   0 0 2   4 3 3
0
0 2 0
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
Output:
T1 T3 T4 T0 T2 
The system is in a safe state
T3 T1 T2 T0 T4 
Safe State exists. So, the resources are allocated

*///...