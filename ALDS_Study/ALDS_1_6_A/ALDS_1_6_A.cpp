// ALDS_1_6_A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

const int MAXNUM = 2000001;
const int MAXK = 10000;

int main()
{
    unsigned short* A, * B;
    int C[MAXK + 1];
    int n, i, j;

    cin >> n;

    A = (unsigned short*)malloc(sizeof(short) * n + 1);
    B = (unsigned short*)malloc(sizeof(short) * n + 1);

    for (int i = 0; i <= MAXK; i++) C[i] = 0;

    for (int j = 0; j < n; j++) {
        cin >> A[j+1];
        C[A[j+1]]++;
    }

    for (int i = 1; i <= MAXK; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
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
