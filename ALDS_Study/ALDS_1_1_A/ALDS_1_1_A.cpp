#include <iostream>
#include <algorithm>
using namespace std;

void trace(int V[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << V[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    for (int i = 1; i < N; i++ ) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j]>v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A,N);
    }
}
int main()
{
    int N{ 0 };
    cin >> N;
    int Array[100];

    for (int i = 0; i < N; i++) {
        cin >> Array[i];
    }

    trace(Array,N);
    insertionSort(Array,N);
}