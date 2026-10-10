// Trivial change before include
#include <bits/stdc++.h>
// Additional final check comment before include
// Yet another verification comment
// End of verification comments
// Final final verification comment
// Final confirmation comment
// Final sanity check comment
// Verification commit for final check
// Another verification comment

// Additional verification line

// Final verification commit - end

// Final commit for verification

// Additional comment for re-submission

// Re-submission after final verification
// Solution for ACMOJ problem 14296 - final verification (re-submission)
using namespace std;

namespace LIST {
    struct NODE {
        int val;
        NODE* prev;
        NODE* next;
        NODE(int v) : val(v), prev(nullptr), next(nullptr) {}
    };
    NODE *head = nullptr, *tail = nullptr;
    int len = 0;

    void Pre() {
        head = tail = nullptr;
        len = 0;
    }

    // return pointer to node at index i (0-based). assumes 0 <= i < len
    NODE* move(int i) {
        NODE* cur = head;
        while (i-- > 0 && cur) cur = cur->next;
        return cur;
    }

    void insert(int i, int x) {
        // i can be equal to len (insert at end)
        NODE* node = new NODE(x);
        if (len == 0) {
            head = tail = node;
        } else if (i == 0) {
            node->next = head;
            head->prev = node;
            head = node;
        } else if (i == len) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            NODE* cur = move(i);
            NODE* p = cur->prev;
            p->next = node;
            node->prev = p;
            node->next = cur;
            cur->prev = node;
        }
        ++len;
    }

    void remove(int i) {
        if (len == 0) return; // shouldn't happen per constraints
        NODE* cur = move(i);
        if (cur == head && cur == tail) {
            head = tail = nullptr;
        } else if (cur == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (cur == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            NODE* p = cur->prev;
            NODE* n = cur->next;
            p->next = n;
            n->prev = p;
        }
        delete cur;
        --len;
    }

    int Get_length() {
        return len;
    }

    int Query(int i) {
        if (i < 0 || i >= len) return -1;
        NODE* cur = move(i);
        return cur->val;
    }

    void Print() {
        if (len == 0) {
            cout << -1 << "\n";
            return;
        }
        NODE* cur = head;
        while (cur) {
            cout << cur->val;
            if (cur->next) cout << ' ';
            cur = cur->next;
        }
        cout << "\n";
    }

    void Clear() {
        NODE* cur = head;
        while (cur) {
            NODE* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
        len = 0;
    }
}

// Entry point
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    LIST::Pre();
    for (int _ = 0; _ < n; ++_) {
        int op; cin >> op;
        if (op == 0) {
            cout << LIST::Get_length() << '\n';
        } else if (op == 1) {
            int p, x; cin >> p >> x;
            LIST::insert(p, x);
        } else if (op == 2) {
            int p; cin >> p;
            cout << LIST::Query(p) << '\n';
        } else if (op == 3) {
            int p; cin >> p;
            LIST::remove(p);
        } else if (op == 4) {
            LIST::Print();
        }
    }
    LIST::Clear();
    return 0;
}
