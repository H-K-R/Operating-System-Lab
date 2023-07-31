#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, size, f;
    cin >> n >> size >> f;

    vector<int> page(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
    }

    while (1)
    {
        int t;
        cin >> t;

        if (t == 0)
            break;
        cout << "Find the pysical address ";

        int page_no, offset;
        cin >> page_no >> offset;

        if (page[page_no] == -1)
        {
            cout << "Page is not available" << endl;
        }
        else
        {
            cout << "Physical address of " << page_no << " " << offset << " is : " << page[page_no] << "  " << offset << endl;
        }
    }
}