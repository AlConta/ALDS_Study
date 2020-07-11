// 安定ソート(バブル、選択ソートの比較)

#include <iostream>
using namespace std;

class Card {
public:
    char mSuit;
    int mValue;

    Card() {
        mSuit = ' ';
        mValue = 0;
    }
    Card(char suit, int value) {
        mSuit = suit;
        mValue = value;
    }
};

void BubbleSort(Card A[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j].mValue < A[j - 1].mValue) {
                Card cardT = A[j];
                A[j] = A[j - 1];
                A[j-1] = cardT;
            }
        }
    }
}

void SelectionSort(Card A[], int N) {
    int min{ 0 };
    for (int i = 0; i < N; i++) {
        min = i;
        for (int j = i; j < N; j++) {
            if (A[j].mValue < A[min].mValue) {
                min = j;
            }
        }
        if (i != min) {
            Card cardT = A[i];
            A[i] = A[min];
            A[min] = cardT;
        }
    }
}

bool isStable(Card C1[], Card C2[], int N) {
    for (int i = 0; i < N; i++) {
        if (C1[i].mSuit != C2[i].mSuit) {
            return false;
        }
    }
    return true;
}

void outputCardArr(Card card[], int N) {
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << ' ';
        cout << card[i].mSuit << card[i].mValue;
    }
    cout << endl;
}
int main()
{
    int N{ 0 };
    cin >> N;

    Card Card1[36], Card2[36];
    for (int i = 0; i < N;i++) {
        char c;
        int n;
        cin >> c;
        cin >> n;
        Card1[i].mSuit = c;
        Card1[i].mValue = n;
        Card2[i].mSuit = c;
        Card2[i].mValue = n;

    }

    // バブルソートは安定ソート
    BubbleSort(Card1, N);
    SelectionSort(Card2, N);

    outputCardArr(Card1, N);
    cout << "Stable" << endl;

    outputCardArr(Card2, N);
    if(isStable(Card1, Card2,N)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
   
}
