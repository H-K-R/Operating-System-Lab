#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << " " << x; 
        else cout << " -";
    }
    cout << "\n";
}

int main()
{
    int size; //... Total number of frames
    cin >> size;
    vector<int> frames(size, -1);
    map<int, int> count; //... How many times a page is used
    int miss = 0;
    
    int page;
    while(cin >> page)
    {
        count[page]++;
        bool found = false;
        for (int x: frames)
        {
            if (x == page)
            {
                found = true;
                break;
            }
        } 
        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        int out = frames[0];
        for (auto x: frames)
        {
            if (x == -1) 
            {
                out = x;
                break;
            }
            if (count[x] < count[out])
            {
                out = x;
            }
        }
        for (int &x: frames)
        {
            if (x == out)
            {
                x = page;
                cout << page << " ->";
                printState(frames);
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}

/*//... Input Output:

...............Input:
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

..............Output:
7 -> 7 - -
0 -> 7 0 -
1 -> 7 0 1
2 -> 2 0 1
0 ->
3 -> 3 0 1
0 ->
4 -> 4 0 1
2 -> 2 0 1
3 -> 2 0 3
0 ->
3 ->
2 ->
1 -> 1 0 3
2 -> 2 0 3
0 ->
1 -> 2 0 1
7 -> 2 0 7
0 ->
1 -> 2 0 1
Total page fault = 13
