#include <vector>
#include <iostream>
using namespace std;

void adjust(vector<int>& X, int x, vector<int>& Y, int y)
{
    int a = max(Y[y], X[x] + 1);
    for (int i = y; i < Y.size(); ++i)
        Y[i] = a++;
}

int main()
{
    int n;
    cout << "Enter number of events ";
    cin >> n;

    vector<int> A, B;

    for (int i = 0; i < n; ++i)
    {
        A.push_back(i+1);
        B.push_back(i+1);
    }

    cout << "Enter DM\n";
    int e;
  
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
        {
            cin >> e;

            if(e == 1)
                adjust(A, i, B, j);
            else if(e == -1)
                adjust(B, j, A, i);
            else if(e == 0)
                continue;
            else
            {
                cout << "Invalid DM\n";
                return 0;
            }
        } 
  

    cout << "Process A:  ";
    for (int i = 0; i < n; i++)
        cout << "A[" << i + 1 << "]=" << A[i] << "  ";
    cout << "\nProcess B:  ";
    for (int i = 0; i < n; i++)
        cout << "B[" << i + 1 << "]=" << B[i] << "  ";

    return 0;
}
