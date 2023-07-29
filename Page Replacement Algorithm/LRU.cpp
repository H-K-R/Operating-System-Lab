#include<bits/stdc++.h>
using namespace std;

int main(){
    
    freopen("input.txt","r",stdin);

    int frame_size;
    cin>>frame_size;

    vector<pair<int,int>> frames(frame_size,{0,-1});

    int page,miss = 0;
    int clock_time = 0;

    while(cin>>page){
        clock_time++;    
        bool found = false;

        for (int i = 0; i < frames.size(); i++)
        {
            if(page == frames[i].second){
                found = true;
                frames[i].first = clock_time; 
                break;
            }
        }

        if(found){
            cout<<page<<"-> Already in Frames"<<endl;
        }
        else{
            miss++;
          
            int frame_to_remove_index = -1;
            int LRU = 9999;

            for (int i = 0; i < frames.size(); i++)
            {
                if(frames[i].first<LRU){
                    LRU = frames[i].first;
                    frame_to_remove_index = i;
                }
            }
            //cout<<"Frames to Remove : "<<frames[frame_to_remove_index].second<<endl;

            frames[frame_to_remove_index].first = clock_time;
            frames[frame_to_remove_index].second = page;

            cout<<page<<"->";
            for (int i = 0; i < frames.size(); i++)
            {
                if(frames[i].second!=-1)
                    cout<<frames[i].second<<" ";
            }
            cout<<endl;
            
            

        }
    
        
        
    }
    cout<<"Total Page Fault : "<<miss<<endl;
}