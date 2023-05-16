#include <iostream>
#include <vector>

using namespace std;

struct Rule {
    int X, Y, Z;
};

bool isUnlimitedHoldingsPossible(int M, int N, vector<Rule>& rules) {
    vector<int> holdings(M, 0); // Initialize holdings for M varieties, all set to 0
    holdings[0] = 1; // Assume initial holdings of 1 unit of the first variety

    for (int i = 0; i < N; i++) {
        Rule& rule = rules[i];
        int X = rule.X;
        int Y = rule.Y;
        int Z = rule.Z;
        int idx_X = X - 1;
        int idx_Y = Y - 1;

        if (holdings[idx_X] >= 1) {
            int tradeCount = holdings[idx_X];
            holdings[idx_X] -= tradeCount;
            holdings[idx_Y] += tradeCount * Z;
        } else if (holdings[idx_Y] >= Z) {
            int tradeCount = holdings[idx_Y] / Z;
            holdings[idx_X] += tradeCount;
            holdings[idx_Y] -= tradeCount * Z;
        }
    }

    return (holdings[0] >= 1);
}

int main() {
    int M, N;
    cout << "请输入M: ";
    cin >> M;
    cout << endl;
    cout << "请输入N: ";
    cin >> N;
    cout << endl;

    vector<Rule> rules(N);
    for (int i = 0; i < N; i++) {
        cout << "请输入第一行规则（输入一个字符后请按回车）: \n";
        cin >> rules[i].X >> rules[i].Y >> rules[i].Z;
        cout << endl;
    }

    bool unlimitedHoldingsPossible = isUnlimitedHoldingsPossible(M, N, rules);
    if (unlimitedHoldingsPossible) {
        cout << "有无限持仓可能！" << endl;
    } else {
        cout << "不可能达到无限持仓！" << endl;
    }

    return 0;
}
