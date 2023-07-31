// A Template Code by Akif

void put_dash(int count){
    for (int i = 0; i < count; i++)
    {
        cout<<"-";
    }  
}

void put_space(int count){
    for (int i = 0; i < count; i++)
    {
        cout<<" ";
    }  
}

void gant_chart_maker(){
    for (int i = 0; i < no_of_process; i++)
    {
        put_space(vec[i].waitingtime);//
        cout<<vec[i].processID;//P1
        put_dash(vec[i].burst);//P1-----------13
        cout<<vec[i].turnaround<<endl;
    }
    
}