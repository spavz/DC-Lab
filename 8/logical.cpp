#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int nA;
  int nB;

  cout << "Enter number of events in Process 1: ";
  cin >> nA;
  cout << "Enter number of events in Process 2: ";
  cin >> nB;

  int A[nA], B[nB];
  int DM[nA][nB];
  // setting initial value of timestamps
  for (int i = 0; i < nA; i++)
    A[i] = i + 1;
  for (int i = 0; i < nB; i++)
    B[i] = i + 1;

  cout << "\n\nEnter Dependency matrix";

  for (int i = 0; i < nA; i++) 
    for (int j = 0; j < nB; j++) 
      cin >> DM[i][j];
    
  

  // generating time stamps for each event
  for (int i = 0; i < nA; i++) 
    for (int j = 0; j < nB; j++) 
      switch (DM[i][j]) {

      case 1:
          B[j] = max(B[j], A[i] + 1);
          for (int k = j+1; k < nB; k++)
              B[k] = B[k-1] + 1;
          break;

      case -1:
        A[i] = max(A[i], B[j] + 1);
        for (int k = i+1; k < nA; k++)
          A[k] = A[k-1] + 1;
        break;

      case 0:
        break;

      default:
        cout << "Invalid Dependency Matrix";
        break;
  }
    
  

  cout << "Process A - ";
  for (int i = 0; i < nA; i++)
    cout << "A[" << i + 1 << "]=" << A[i] << "  ";
  cout << "\nProcess B - ";
  for (int i = 0; i < nB; i++)
    cout << "B]" << i + 1 << "]=" << B[i] << "  ";
  return 0;
}
