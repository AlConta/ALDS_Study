#include <iostream>
using namespace std;

const int MAX = 500000;
const int MAXV = 1000000001;
typedef long long llong;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

llong merge(int A[], int left, int mid, int right) {
    int i{ 0 }, j{ 0 };
    int n1 = mid - left;
    int n2 = right - mid;
    llong cnt = 0;
    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j];
    }

    L[n1] = MAXV;
    R[n2] = MAXV;

    i = j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
            cnt += (llong)n1 - (llong)i;
        }

    }
    return cnt;
}

llong mergeSort(int A[], int left, int right) {
    llong v1{ 0 }, v2{ 0 }, v3{ 0 };

    if (left + 1 < right) {
        int mid = (left + right) / 2;
        v1 = mergeSort(A, left, mid);
        v2 = mergeSort(A, mid, right);
        v3 = merge(A, left, mid, right);
        return v1 + v2 + v3;
    }
    else return 0;
}

int main()
{
    int n, i;
    int A[MAX];
    //A = (int*)malloc(MAX);

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }

    llong ans = mergeSort(A, 0, n);

    std::cout << ans << "\n";
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

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
