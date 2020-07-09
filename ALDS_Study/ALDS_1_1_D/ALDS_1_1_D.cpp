#include <iostream>
#include <algorithm>
using namespace std;

const static int MAX = 200000;
int main()
{
    int n{ 0 };
    cin >> n;

    int maxDiv = -2000000000;
    int minv = 0;
    
    cin >> minv;
    for (int i = 1; i < n; i++) {
        int R{ 0 };
        cin >> R;
        maxDiv = max(maxDiv, R - minv);
        minv = min(minv, R);
    }
    cout << maxDiv << endl;

    return 0;
}
