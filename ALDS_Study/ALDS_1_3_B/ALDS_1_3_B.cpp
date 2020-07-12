#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Process {
public:
    string mName;
    int mTime;

    Process() {
        mName = "";
        mTime = 0;
    }
    Process(string name, int time) {
        mName = name;
        mTime = time;
    }
};

int doProcess(deque<Process>& qProcess, int Q, int totalTime) {
    int nFinishT = totalTime;
    Process front = qProcess.front();
    if (front.mTime <= Q) {
        nFinishT += front.mTime;
        //int nRemain = Q - front.mTime;
        qProcess.pop_front();
        cout << front.mName << ' ' << nFinishT << endl;
        //doProcess(qProcess, nRemain, nFinishT);
    }
    else {
        front.mTime -= Q;
        qProcess.pop_front();
        qProcess.push_back(front);
        nFinishT += Q;
    }
    return nFinishT;
}

int main()
{
    int N{ 0 }, Q{ 0 };
    cin >> N >> Q;
    
    deque<Process> qProcess;

    for (int i = 0; i < N; i++) {
        string name;
        int time{ 0 };
        cin >> name >> time;

        qProcess.push_back(Process(name,time));
    }

    int totalTime = 0;
    while (!qProcess.empty()) {
        totalTime = doProcess(qProcess, Q, totalTime);
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
