// ALDS_1_5_A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int n, A[50];
int dp[30][3000];

int solve(int i, int m) {
    //if (m == 0) return 1;
    //if (i >= n) return 0;
    //int res = solve(i+1,m) || solve(i+1, m-A[i]);
    //return res;

    if (dp[i][m] != 0) return dp[i][m];

    if (m == 0) dp[i][m] = 1;
    else if(i >= n) dp[i][m] = -1;
    else if(solve(i+1, m) == 1) dp[i][m] = 1;
    else if(solve(i + 1, m - A[i]) == 1) dp[i][m] = 1;
    else dp[i][m] = -1;
    
    return  dp[i][m];
}

int main()
{
    int q, M, i;

    scanf_s("%d", &n);
    for (i = 0; i < n; i++) {
        scanf_s("%d", &A[i]);
    }
    scanf_s("%d", &q);
    for (i = 0; i < q; i++) {
        scanf_s("%d", &M);
        if (solve(0,M)==1) printf("yes\n");
        else printf("no\n");
    }

    return 0;
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
