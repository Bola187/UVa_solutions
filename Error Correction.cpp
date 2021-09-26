#include <iostream>
using namespace std;

int main() {

    for (;;) {

        int n = 0, m[100][100] = { 0 }, row_sum[100] = { 0 }, col_sum[100] = { 0 }, r = 0, c = 0, row = 0, col = 0;
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                row_sum[i] += m[i][j];



            if (row_sum[i] % 2 != 0) {
                r++;
                row = i;
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++)
                col_sum[j] += m[i][j];


            if (col_sum[j] % 2 != 0) {
                c++;
                col = j;

            }
        }

        if (r == 0 && c == 0)
            cout << "OK" << endl;

        if (r == 1 && c == 1)
            cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;

        if (r > 1 || c > 1)

            cout << "Corrupt" << endl;
    }

    return 0;
}