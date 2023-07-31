/*
    "Shobai k Shoman vabe Ektu Ektu kore Bhalobasha Biliye Dibo" - Round Robin
    Akif Islam
    11 July 2023
*/

#include<bits/stdc++.h>
using namespace std;


struct process{
    string processID;
    int burst;
    int waitingtime;
    int turnaround;
};


int no_of_process;
vector<process> vec(1000);

// This function is just for debug, not for production/exam
void emergency_print(){
    cout<<"__________________________________________________________________"<<endl;
    cout<<"PID\t\tTAROUND"<<endl;   
    
    for (int i = 0; i < no_of_process; i++)
    {
        cout<<vec[i].processID<<"\t\t"<<vec[i].turnaround<<endl;   
    }
    cout<<"__________________________________________________________________"<<endl;
    
}

int main(){
    
    freopen("input.txt","r",stdin);

    cin>>no_of_process;

    
    //Input
    int total_burst = 0;
    for (int i = 0; i < no_of_process; i++){
        cin>>vec[i].processID>>vec[i].burst;
        total_burst+=vec[i].burst;
    }
    
    int time_quantum;
    cin>>time_quantum;
    
    
    //Calculating Waiting and Turnaround Time
    int clock_time = 0;
   
    vector<string> gant_chart;

    for (int i = 0; i < 1000; i++)
    {
        if(vec[i%no_of_process].burst<=0)
            continue;

        clock_time+=min(vec[i%no_of_process].burst,time_quantum);

        if(vec[i%no_of_process].burst>time_quantum){
            gant_chart.push_back(vec[i%no_of_process].processID);
            vec[i%no_of_process].burst-=time_quantum;
        }
        else{
            vec[i%no_of_process].turnaround = clock_time;
            vec[i%no_of_process].burst-=time_quantum;
            gant_chart.push_back(vec[i%no_of_process].processID);
        }
    }
    
       
    for (int i = 0; i < gant_chart.size(); i++)
    {
        cout<<gant_chart[i]<<" ";
    }
    cout<<endl;
    emergency_print();
    return 0;
}