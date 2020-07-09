#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Dice {
public:
    int label1;
    int label2;
    int label3;
    int label4;
    int label5;
    int label6;

    Dice() {
        label1 = 0;
        label2 = 0;
        label3 = 0;
        label4 = 0;
        label5 = 0;
        label6 = 0;
    }
    Dice(const Dice& obj) {
        label1 = obj.label1;
        label2 = obj.label2;
        label3 = obj.label3;
        label4 = obj.label4;
        label5 = obj.label5;
        label6 = obj.label6;
    }
    ~Dice(){
    }

    int getValue(int label) {
        switch (label) {
        case 1: return label1; break;
        case 2: return label2; break;
        case 3: return label3; break;
        case 4: return label4; break;
        case 5: return label5; break;
        case 6: return label6; break;
        default: break;
        }
        return -1;
    }

    void setValue(int n, int l) {
        switch (l) {
        case 1: label1 = n; break;
        case 2: label2 = n; break;
        case 3: label3 = n; break;
        case 4: label4 = n; break;
        case 5: label5 = n; break;
        case 6: label6 = n; break;
        default: break;
        }
    }

    void roll(char c) {
        int a = label1;
        int b = label2;
        switch (c) {
        case 'N':
            label1 = label2;
            label2 = label6;
            label6 = label5;
            label5 = a;
            break;
        case 'S':
            label1 = label5;
            label5 = label6;
            label6 = label2;
            label2 = a;
            break;
        case 'W':
            label1 = label3;
            label3 = label6;
            label6 = label4;
            label4 = a;
            break;
        case 'E':
            label1 = label4;
            label4 = label6;
            label6 = label3;
            label3 = a;
            break;
        case 'R':
            label2 = label3;
            label3 = label5;
            label5 = label4;
            label4 = b;
            break;
        default:
            break;
        }
    }
    int FindLabel(int n) {
        if (label1 == n) return 1;
        if (label2 == n) return 2;
        if (label3 == n) return 3;
        if (label4 == n) return 4;
        if (label5 == n) return 5;
        if (label6 == n) return 6;
        return -1;
    }
    bool SameDice(shared_ptr<Dice> rhs) {
        return (label1 == rhs->label1
            && label2 == rhs->label2
            && label3 == rhs->label3
            && label4 == rhs->label4
            && label5 == rhs->label5
            && label6 == rhs->label6
            );
    }

public:
    bool operator ==(const Dice& rhs) const
    {
        return (label1 == rhs.label1
            && label2 == rhs.label2
            && label3 == rhs.label3
            && label4 == rhs.label4
            && label5 == rhs.label5
            && label6 == rhs.label6
            );
    }

    bool operator !=(const Dice& rhs) const
    {
        return (label1 != rhs.label1
            || label2 != rhs.label2
            || label3 != rhs.label3
            || label4 != rhs.label4
            || label5 != rhs.label5
            || label6 != rhs.label6
            );
    }

    Dice &operator =(const Dice& rhs)
    {
        label1 = rhs.label1;
        label2 = rhs.label2;
        label3 = rhs.label3;
        label4 = rhs.label4;
        label5 = rhs.label5;
        label6 = rhs.label6;
    }
};

bool FindSameDice(shared_ptr<Dice> DiceA, shared_ptr<Dice> DiceB) {
    if (DiceA->SameDice(DiceB)) return true;

    for (int i = 0; i < 4; i++) {
        DiceB->roll('N');
        for (int j = 0; j < 4; j++) {
            DiceB->roll('R');
            if (DiceA->SameDice(DiceB)) return true;
        }
    }
    DiceB->roll('W');
    for (int i = 0; i < 4; i++) {
        DiceB->roll('R');
        if (DiceA->SameDice(DiceB)) return true;
    }
    DiceB->roll('W');
    DiceB->roll('W');
    for (int i = 0; i < 4; i++) {
        DiceB->roll('R');
        if (DiceA->SameDice(DiceB)) return true;
    }
    return false;
}

int main()
{
    //Dice DiceA;

    //for (int i = 0; i < 6; i++) {
    //    int n = 0;
    //    cin >> n;
    //    DiceA.setValue(n, i + 1);
    //}

    // Ver.1
    //string str;
    //cin >> str;
    //if (str.empty()) return 1;
    //int nSize = (int)str.size();
    //for (int i = 0; i < nSize; i++) {
    //    char c = str[i];
    //    DiceA.roll(c);
    //}

    //cout << DiceA.label1 << endl;

    // Ver.2
    //int Q; 
    //cin >> Q;
    //if (Q<1||Q>24) return 1;

    //for (int i = 0; i < Q; i++) {
    //    int q1{ 0 }, q2{ 0 };
    //    cin >> q1 >> q2;

    //    if (DiceA.label3 == q1) DiceA.roll('W');
    //    if (DiceA.label4 == q1) DiceA.roll('E');
    //    while (DiceA.label1!=q1) {
    //        DiceA.roll('N');
    //    }
    //    while (DiceA.label2 != q2) {
    //        DiceA.roll('R');
    //    }
    //    cout << DiceA.label3 << endl;
    //}

    // Ver.3
    //Dice DiceB;

    //for (int i = 0; i < 6; i++) {
    //    int n = 0;
    //    cin >> n;
    //    DiceB.setValue(n, i + 1);
    //}

    //int l1 = DiceA.FindLabel(DiceB.label1);
    //int l2 = DiceA.FindLabel(DiceB.label2);
    //if (l1 < 0 || l2 < 0) cout << "No" << endl;
    //else {
    //    bool bSame = false;
    //    if (DiceA == DiceB) bSame = true;
    //    for (int i = 0; i < 4; i++) {
    //        DiceB.roll('N');
    //        for (int j = 0; j < 4; j++) {
    //            DiceB.roll('R');
    //            if (DiceA == DiceB) bSame = true;
    //        }
    //    }
    //    DiceB.roll('W');
    //    for (int i = 0; i < 4; i++) {
    //        DiceB.roll('R');
    //        if (DiceA == DiceB) bSame = true;
    //    }
    //    DiceB.roll('W');
    //    DiceB.roll('W');
    //    for (int i = 0; i < 4; i++) {
    //        DiceB.roll('R');
    //        if (DiceA == DiceB) bSame = true;
    //    }

    //    if (bSame) cout << "Yes" << endl;
    //    else cout << "No" << endl;
    //}

    int N;
    cin >> N;

    if (N < 2 || N > 100) return 1;

    vector<shared_ptr<Dice>> vDice;

    for (int i = 0; i < N; i++) {
        shared_ptr<Dice> DiceA(new Dice);

        for (int i = 0; i < 6; i++) {
            int n = 0;
            cin >> n;
            DiceA->setValue(n, i + 1);
        }

        vDice.push_back(DiceA);
    }

    bool bFind = false;
    for (int i = 0; i < N; i++) {
        shared_ptr<Dice> DiceA = vDice[i];
        
        for (int j = i + 1; j < N; j++) {
            shared_ptr<Dice> DiceB = vDice[j];

            bFind = FindSameDice(DiceA, DiceB);
            if (bFind) break;
        }
        if (bFind) break;
    }
    
    if (bFind) cout << "No" << endl;
    else cout << "Yes" << endl;
}