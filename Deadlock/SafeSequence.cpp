#include<bits/stdc++.h>
using namespace std;

struct process{
    string processID;
    vector<int> max_need,allocated,need;
};

bool safety_algorithm(vector<int> available, vector<process> vec){
    int no_of_process = vec.size();
    int no_of_resource = available.size();

    string safe_sequence = "";
    vector<bool> finish(no_of_process, false);

    // Safe Sequence
    while(true){
       
        bool found = false; // If I got a process to execute
        for (int i = 0; i < no_of_process; i++)
        {
            if(finish[i]) continue;
            bool isOK = true;

            for (int j = 0; j < no_of_resource; j++)
            {
                // if available resources are not enough
                if(vec[i].need[j]>available[j]){
                    isOK = false;
                    break;
                }
            }

            if(isOK){
                found = true;
                finish[i] = true;

                for (int j = 0; j < no_of_resource; j++)
                {
                    available[j]+=vec[i].allocated[j];
                }

                safe_sequence+=vec[i].processID+" ";
                
            }
                
        }
        if(!found)
            break; 
    }

    for (int i = 0; i < no_of_process; i++)
    {
        if(!finish[i]) return false;
    }
    cout<<safe_sequence<<endl;
    return true;    
}

int main(){
    
    freopen("input.txt","r",stdin);

    int no_of_resource;
    cin>>no_of_resource;

    vector<int> available(no_of_resource);

    // Input : Available Resources
    for (int i = 0; i < no_of_resource; i++)
    {
        cin>>available[i];
   
    }

    int no_of_process;
    cin>>no_of_process;

    vector<process> vec(no_of_process);

    // Input : Allocated, Max_Need, Need
    for (int i = 0; i < no_of_process; i++)
    {  
        vec[i].allocated.resize(no_of_process);
        vec[i].need.resize(no_of_process);
        vec[i].max_need.resize(no_of_process); 
    
        cin>>vec[i].processID;

        for (int j = 0; j < no_of_resource; j++)
        {
            cin>>vec[i].allocated[j];
        }
        
        for (int j = 0; j < no_of_resource; j++)
        {
            cin>>vec[i].max_need[j];
            vec[i].need[j] = vec[i].max_need[j]-vec[i].allocated[j];
        }
       
    }

    if(safety_algorithm(available,vec)){
        cout<<"The system is in a safe state."<<endl;
    }
    else{
        cout<<"The system is not in a safe state."<<endl;
    }
  
    return 0;
}