#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        int mx = INT_MIN, smx = INT_MIN;
        int ind1, ind2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] > mx)
            {
                if (mx > smx)
                {
                    smx = mx;
                    ind2 = ind1;
                }
                mx = a[i];
                ind1 = i;
            }
            if (a[i] < mx && a[i] > smx)
            {
                smx = a[i];
                ind2 = i;
            }
        }
        // cout << mx << " " << smx << endl;

        if (ind1 < ind2)
            cout << ind1 << " " << ind2 << endl;
        else
            cout << ind2 << " " << ind1 << endl;
    }

    return 0;
}
