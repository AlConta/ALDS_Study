// ALDS_1_4_C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <unordered_map>

using namespace std;
int KEY = 1;
unordered_map<int, int> DICTIONARY;

int getChar(char c) {
    switch(c) {
    case 'A':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'G':
        return 3;
        break;
    case 'T':
        return 4;
        break;
    default:
        break;
    }
    return 0;
}

int getKey(string str) {

    int len = str.length();
    if (len <= 0) return len;

    int sum = 0;
    int loop = 1;
    for (int i = 0; i < len; i++) {
        sum += getChar(str[i]) * loop;
        loop *= 5;
    }

    return sum;
}

bool insertToDic(string str) {
    int key = getKey(str);
    if (key <= 0) return false;

    auto p1 = DICTIONARY.insert(make_pair(key,1));
    return p1.second;
}

bool findFrDic(string str) {
    int key = getKey(str);
    if (key <= 0) return false;

    auto p1 = DICTIONARY.find(key);
    return p1 != DICTIONARY.end();
}


int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        string command, key;
        
        cin >> command >> key;
        if (command[0] == 'i') insertToDic(key);
        else if (command[0] == 'f') {
            if (findFrDic(key)) cout << "yes\n";
            else cout << "no\n";
        }
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
