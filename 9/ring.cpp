#include <iostream>
#include <list>
using namespace std;
int n;
bool alive[100];

int election(int init)
{
	list<int> e;
	int coord = 0;
	for (int i = 0; i < n; ++i)
	{
		int p = (i+init)%n;
		if(alive[p])
		{
			e.push_back(p);
			cout << "message received at " << p << "-> ";
			for(auto x:e)
				cout << x <<" ";
			cout << endl;
			coord = max(coord,p);
		}
	}
	return coord;
}
void display()
{
	cout << "\nPID\t" << "alive?" << endl; 
	for (int i = 0; i < n; ++i)
		cout << i << "\t" << alive[i] <<endl;
}

int main()
{
	int init,c,pid;
	cout << "Enter n\n";
	cin >> n;

	cout << "Enter initiator\n";
	cin >> init;

	for (int i = 0; i < n; ++i)
		alive[i] = true;

	while(true)
	{
		display();
		cout << "1.Crash  2.recover? ";
		cin >> c;

		cout << "Enter pid\n";
		cin >> pid;

		if(c == 1)
			alive[pid] = false;	
		else if(c == 2)	
			alive[pid] = true;
		else
			return 0;

		cout << "Coordinator: " << election(init) << endl;
		cout << "initiator: " << init << endl;
	}
}