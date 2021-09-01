#include <iostream>
using namespace std;

int ans[25][1005];
int bars[25];

int t, n, p;

void init() {
    cin >> p >> n;

    for (int i = 0; i < n; i++)
        cin >> bars[i];
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            ans[i][j] = -1;
        }
    }

}

bool solve(int x1, int x2)
{
    if (x2 == p) 
        return true;

    else if (x2 > p || x1 == n) 
        return false;

    if (ans[x1][x2] != -1) 
        return ans[x1][x2];

    bool poss = false;

    for (int i = x1; i < n && !poss; i++) 
        poss |= solve(i + 1, x2 + bars[i]);
    
    return ans[x1][x2] = poss;
}


int main()
{
    int t;
    cin >> t;

    while (t--) {
        init();

        if (solve(0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}