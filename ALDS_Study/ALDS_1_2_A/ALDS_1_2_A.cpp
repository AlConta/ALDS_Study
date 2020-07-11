// バブルソート

#include <iostream>
#include <algorithm>

using namespace std;

int bubbleSort(int A[], int N) {
    bool bContinue = true;
    int ex = 0;
    int sorted = 0;
    while (bContinue) {
        bContinue = false;
        for (int j = N - 1; j >= sorted +1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j - 1], A[j]);
                bContinue = true;
                ex++;
            }
        }
        sorted++;
    }
    return ex;
}

int main()
{
    int N{ 0 };
    cin >> N;

    if (N < 1 || N>100) return 1;

    int A[100];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ex = bubbleSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i != 0) cout << ' ';
        cout << A[i];
    }
    cout << endl;

    cout << ex << endl;

}
