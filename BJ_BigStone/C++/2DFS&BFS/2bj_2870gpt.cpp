#include <bits/stdc++.h>
using namespace std;

vector<string> store;

void dfs_pullNum(int idx, string s) {
    string num = "";
    while (idx < s.length() && isdigit(s[idx])) {
        num += s[idx];
        idx++;
    }
    if (!num.empty()) {
        while(num.size()>1&&num.front()=='0') num.erase(num.begin());
        store.push_back(num);
    }
    if (idx < s.length())
        dfs_pullNum(idx + 1, s);
}

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

int main() {
    int l;
    cin >> l;

    for (int i = 0; i < l; i++) {
        string s;
        cin >> s;
        dfs_pullNum(0, s);
    }

    sort(store.begin(), store.end(), cmp); // cmp 없으면 사이즈 상관없이+앞숫자 아스키코드 비교만함
    for (auto num : store) cout << num << endl;

    return 0;
}
