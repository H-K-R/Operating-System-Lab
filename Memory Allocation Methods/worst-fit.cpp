#include <bits/stdc++.h>

using namespace std;

int main()
{
    int hole; // Number of free memory holes
    cin >> hole;
    vector<int> holes(hole);
    for (int i = 0; i < hole; i++)
    {
        cin >> holes[i]; // Free memory hole's size
    }
    
    int size; // Process size
    cin >> size;

    sort(holes.begin(), holes.end());
    if (holes.back() >= size)
    {
        cout << "The process is allocated into " << holes.back() 
             << " mb memory hole.";
    }
    else cout << "No suitable hole available!";
}

/*
Input:
7
12 3 5 32 43 9 7
27

Output: 
The process is allocated into 32 mb memory hole.

Input:
7
12 3 5 32 43 9 7
45

Output: 
No suitable hole available!
*/