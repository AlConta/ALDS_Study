// 選択ソート O(N^2)

#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int ex{ 0 }, min{0};
    for (int i = 0; i < N-1; i++) {
        min = i;

        for (int j = i; j < N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(A[i], A[min]);
        if( i != min ) ex++;
    }
    return ex;
}

int main()
{
    int N;
    cin >> N;

    int A[100];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ex = selectionSort(A,N);

    for (int i = 0; i < N; i++) {
        if (i != 0) cout << ' ';
        cout << A[i];
    }
    cout << endl;
    cout << ex << endl;

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
