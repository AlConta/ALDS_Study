// Study_C++17.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// **** 構造化バインディング(structured bindings): ****

#include <iostream>
#include <map>
using namespace std;

pair<int, string> AAA() {
    return { 10, "AAAAA" };
}

tuple<int, string, double> g()
{
    return { 1, "World", 3.14 };
}

// **** 構造化バインディング(structured bindings): ****
void StructuredBindings() {   

    // Outline: 組やタプル、配列や構造体を分解して各要素を取り出す
    auto [id, message] = AAA();
    cout << id << " : " << message << endl;

    auto [ID, text, num] = g();
    cout << ID << " : " << text << " : " << num << endl;

    // 配列の分解(1 値)
    {
        int ar[] = { 3, 1, 4 };

        auto [a, b, c] = ar;

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }
    // 配列の分解(2 参照)
    {
        int ar[] = { 3, 1, 4 };
        auto& [a, b, c] = ar;

        // ar[1]を値2に書き換える
        b = 2;

        cout << "ar[0] = " << ar[0] << endl;
        cout << "ar[1] = " << ar[1] << endl;
        cout << "ar[2] = " << ar[2] << endl;
    }
    // mapの各要素をキーと値に分解する。
    {
        // const auto&ではなくauto&にした場合は、
        // const std::string&型のkey変数と、
        // int&型のvalue変数に分解される。
        std::map<string, int> m = {
            {"Alice", 3},
            {"Bob", 1},
            {"Carol", 4}
        };

        for (const auto& [key, value] : m) {
            cout << key << " : " << value << endl;
        }
    }

    // map::insert()の戻り値を分解する
    {
        std::map<std::string, int> m;

        // 単一要素をとるmap::insert()メンバ関数は、
        // 戻り値としてpair<iterator, bool>を返す。
        // firstは指定したキーを保持する要素へのイテレータ、
        // secondは挿入に成功したかを表すbool値。
        m.insert({ "Alice", 3 });
        auto [it, inserted] = m.insert({ "Alice", 1 }); // キーがすでに登録されていたら挿入に失敗する

        std::cout << it->second << std::endl;
        std::cout << std::boolalpha << inserted << std::endl;
    }
}

// **** [[deprecated]]属性 ****
// 対象の機能が非推奨であることを示す属性
// 対象：クラス、型、変数、非静的メンバ変数、関数、列挙型、テンプレートの特殊化
// 非推奨な関数
[[deprecated("please use new_func() function")]]
void old_func() {}

void new_func() {}

// 非推奨なクラス
class [[deprecated("please use new_class class")]] old_class {};

int main()
{
    // **** 構造化バインディング(structured bindings): ****
    StructuredBindings();

    // **** [[deprecated]]属性 ****
    old_func();
    new_func();

    old_class c;
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
