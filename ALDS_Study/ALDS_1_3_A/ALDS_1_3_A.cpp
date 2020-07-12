// ALDS_1_3_A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    string str;

    vector<int> vOperand;

    while (cin >> str) {
        if (str == "+") {
            if ((int)vOperand.size() >= 2) {
                int& a1 = vOperand.back();
                vOperand.pop_back();
                int& a2 = vOperand.back();
                vOperand.pop_back();

                vOperand.push_back(a2+a1);
            }
        }
        else if (str == "-") {
            if ((int)vOperand.size() >= 2) {
                int& a1 = vOperand.back();
                vOperand.pop_back();
                int& a2 = vOperand.back();
                vOperand.pop_back();

                vOperand.push_back(a2 - a1);
            }
        }
        else if (str == "*") {
            if ((int)vOperand.size() >= 2) {
                int& a1 = vOperand.back();
                vOperand.pop_back();
                int& a2 = vOperand.back();
                vOperand.pop_back();

                vOperand.push_back(a2 * a1);
            }
        }
        else {
            x = atoi(str.c_str());
            vOperand.push_back(x);
        }
    }

    if (!vOperand.empty()) {
        cout << vOperand.at(0) << endl;
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
