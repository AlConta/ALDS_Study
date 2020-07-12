// ALDS_1_3_C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Node {
public:
    int mKey;
    Node* mPrev;
    Node* mNext;

    Node() {
        mKey = 0;
        mPrev = this;
        mNext = this;
    }
    Node(int k, Node* pre, Node* next) {
        mKey = 0;
        mPrev = pre;
        mNext = next;
    }
    ~Node() {
    }
};


Node* nil;
void init() {
    nil = new Node();    
}

void insert(int key) {
    Node* pNode = new Node();
    pNode->mKey = key;

    pNode->mNext = nil->mNext;
    nil->mNext->mPrev = pNode;
    nil->mNext = pNode;
    pNode->mPrev = nil;
}

Node* listSearch(int key) {
    Node* cur = nil->mNext;

    while (cur != nil && cur->mKey != key) {
        cur = cur->mNext;
    }
    return cur;
}

void deleteNode(Node* node) {
    if (node == nil) return;
    node->mPrev->mNext = node->mNext;
    node->mNext->mPrev = node->mPrev;

    delete node;
    node = nullptr;
}

void deleteFirst() {
    deleteNode(nil->mNext);
}

void deleteLast() {
    deleteNode(nil->mPrev);
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
}

void printList() {
    Node* cur = nil->mNext;
    int isf = 0;
    while (1) {
        if (cur == nil) break;
        if (isf++ > 0) printf(" ");

        printf("%d", cur->mKey);
        cur = cur->mNext;
    }
    printf("\n");
}

void deleteList() {
    Node* cur = nil->mNext;
    while (1) {
        if (cur == nil) break;

        Node* curNext = cur->mNext;
        deleteNode(cur);

        cur = curNext;
    }
}

int main()
{
    int n;
    int size = 0;
    char com[20];
    int np{ 0 }, nd{ 0 };

    scanf("%d", &n);

    init();

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%s %d", com, &key);
        if (com[0] == 'i') {
            insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd') {
            if (strlen(com) > 6) {
                if (com[6] == 'F') deleteFirst();
                else if (com[6] == 'L') deleteLast();
            }
            else {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    printList();
    deleteList();
    delete nil;

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
