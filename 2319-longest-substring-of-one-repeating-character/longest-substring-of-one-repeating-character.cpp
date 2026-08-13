class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int len;
        int prefix, suffix, best;

        Node() : leftChar(0), rightChar(0), len(0),
                 prefix(0), suffix(0), best(0) {}
    };

    vector<Node> tree;
    string s;

    Node merge(Node &L, Node &R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;
        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.prefix = L.prefix;
        if (L.prefix == L.len && L.rightChar == R.leftChar)
            res.prefix = L.len + R.prefix;

        res.suffix = R.suffix;
        if (R.suffix == R.len && L.rightChar == R.leftChar)
            res.suffix = R.len + L.suffix;

        res.best = max(L.best, R.best);

        if (L.rightChar == R.leftChar)
            res.best = max(res.best, L.suffix + R.prefix);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = s[l];
            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        int k = queryIndices.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};