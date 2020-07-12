// ALDS_1_3_D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    stack<int> S1;
    stack<pair<int, int>> S2;
    int sum{ 0 };
    char ch;
    for (int i = 0; cin >> ch; i++) {
        if (ch == '\\') S1.push(i);
        else if (ch == '/' && (int)S1.size() > 0) {
            int j = S1.top();
            S1.pop();
           
            sum += i - j;
            int a = i - j;
            while ((int)S2.size() > 0 && S2.top().first > j) {
                a += S2.top().second;
                S2.pop();
            }
            S2.push(make_pair(j,a));
        }
    }

    vector<int> ans;
    while ((int)S2.size() > 0) {
        ans.push_back(S2.top().second);
        S2.pop();
    }
    reverse(ans.begin(), ans.end());

    int nSize = (int)ans.size();
    
    cout << sum << endl;
    cout << nSize;
    for (int i = 0; i < nSize; i++) {
        cout << " ";
        cout << ans[i];
    }
    cout << endl;

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
