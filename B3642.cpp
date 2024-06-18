//& 抄的题解
#include <iostream>
struct Tree {
    int data;
    int left, right;
}t[1000000];
using namespace std;
void Pre(int f) {
    if (f) {
        cout << t[f].data << " ";
        Pre(t[f].left);
        Pre(t[f].right);
    }
}
void In(int f) {
    if (f) {
        In(t[f].left);
        cout << t[f].data << " ";
        In(t[f].right);
    }
}
void Post(int f) {
    if (f) {
        Post(t[f].left);
        Post(t[f].right);
        cout << t[f].data << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        t[i].data = i;
        if (l)
            t[i].left = l;
        if (r)
            t[i].right = r;
    }
    Pre(1);
    cout << "\n";
    In(1);
    cout << "\n";
    Post(1);
    cout << "\n";
    return 0;
}