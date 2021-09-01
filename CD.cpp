#include <iostream>
using namespace std;

int tape, n, track[20];
int ans, nearest_total;

void choose(int total, int m, int p) {
	if (total > tape)
		return;
	if (total > nearest_total) {
		nearest_total = total;
		ans = m;
	}
	if (p >= n)
		return;

	choose(total + track[p], m | (1 << p), p + 1);
	choose(total, m, p + 1);
}

int main()
{

	while (cin>> tape >> n)
	{
		for (int i = 0; i < n; i++) 
			cin>>track[i];

		ans = -1;
		nearest_total = -1;
		choose(0, 0, 0);

		for (int i = 0; i < n; i++) {
			if ((ans >> i) % 2)
				cout << track[i] << " ";
		}
		cout << "sum:" << nearest_total << endl;
	}

	return 0;
}