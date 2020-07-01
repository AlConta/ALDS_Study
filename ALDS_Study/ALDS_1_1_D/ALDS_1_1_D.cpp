#include <iostream>
#include <algorithm>
using namespace std;

const static int MAX = 200000;
int main()
{
    int n{ 0 };
    cin >> n;

    int maxv = -200000000;
    int minv = 0;
    
    cin >> minv;
    for (int i = 1; i < n; i++) {
        int R{ 0 };
        cin >> R;
        maxv = max(maxv, R - minv);
        minv = min(minv, R);
    }
    cout << maxv << endl;

    return 0;
}
