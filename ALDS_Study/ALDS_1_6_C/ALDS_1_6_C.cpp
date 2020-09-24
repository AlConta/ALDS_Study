// ALDS_1_6_C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
const int MAXV = 1000000001;

struct Card {
    char suit;
    int value;
};

vector<Card> L, R;

void init(int n) {
    for (int i = 0; i < n; i++) {
        Card c;
        L.push_back(c);
        R.push_back(c);
    }
}

void merge(vector<Card>& A, int left, int mid, int right) {
    int i, j;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j];
    }

    L[n1].value = MAXV;
    R[n2].value = MAXV;

    i = j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<Card>& A, int left, int right) {

    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int Partition(vector<Card>& A, int p, int r) {
    Card t, x;
    x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;

    return ++i;
}

void quickSort(vector<Card>& A, int p, int r)
{
    if (p < r) {
        int q = Partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }    
}

int main()
{
    int n;
    cin >> n;

    init(n);

    vector<Card> A, B;

    for (int i = 0; i < n; i++) {
        Card card;
        cin >> card.suit >> card.value;
        A.push_back(card);
        B.push_back(card);
    }

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) stable = false;
        if (!stable) break;
    }


    if (stable) printf("Stable\n");
    else printf("Not stable\n");

    for (int i = 0; i < n; i++) {
        printf("%c %d\n", B[i].suit, B[i].value);
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
