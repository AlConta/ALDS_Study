// BinarySearch 二分探索
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int A[1000000], n;

int binarySearch(int key) {
    int left = 0;
    int right = n;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return 1;
        if (key > A[mid]) left = mid + 1;
        else if (key < A[mid]) right = mid;
    }
    return 0;
}

int main()
{
    int i, q, k, sum = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &k);
        if (binarySearch(k)) sum++;
    }
    printf("%d\n", sum);
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
