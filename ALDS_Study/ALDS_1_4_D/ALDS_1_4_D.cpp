// ALDS_1_4_D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

#define MAX 100000
typedef long long llong;
int num{ 1 }, truck{ 1 };
llong T[MAX];

int check(llong P) {
    int count = 0;
    for (int j = 0; j < truck; j++) {
        llong s = 0;
        while (s + T[count] <= P) {
            s += T[count];
            count++;
            if (count == num) return num;
        }
    }
    return count;
}

llong solve(llong right) {
    llong left{ 0 };

    while (right - left > 1) {
        llong mid = (left + right) / 2;
        int volume = check(mid);
        if (volume >= num) right = mid;
        else left = mid;
    }

    return right;
}

int main()
{
    scanf_s("%d %d", &num, &truck);
    int maxw = 1;
    for (int i = 0; i < num; i++) {
        int w = 0;
        scanf_s("%d", &w);
        T[i] = w;
        if (maxw <= w) maxw = w;
    }

    llong ans = solve((llong)num* (llong)maxw);
    cout << ans << "\n";
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
