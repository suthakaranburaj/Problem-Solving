class TrieNode {
public:
    int child[26];
    int idx;

    TrieNode() {

        for (int i = 0; i < 26; i++) {
            child[i] = -1;
        }

        idx = -1;
    }
};

class Solution {
public:

    vector<TrieNode> trie;

    vector<int> len;

    Solution() {
        trie.push_back(TrieNode()); // root
    }

    bool better(int newIdx, int oldIdx) {

        if (oldIdx == -1)
            return true;

        if (len[newIdx] < len[oldIdx])
            return true;

        if (len[newIdx] == len[oldIdx] &&
            newIdx < oldIdx)
            return true;

        return false;
    }

    void insert(string& word, int index) {

        int node = 0;

        if (better(index, trie[node].idx)) {
            trie[node].idx = index;
        }

        for (int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if (trie[node].child[ch] == -1) {

                trie[node].child[ch] = trie.size();

                trie.push_back(TrieNode());
            }

            node = trie[node].child[ch];

            if (better(index, trie[node].idx)) {
                trie[node].idx = index;
            }
        }
    }

    int search(string& word) {

        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if (trie[node].child[ch] == -1) {
                break;
            }

            node = trie[node].child[ch];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsContainer.size();

        len.resize(n);

        for (int i = 0; i < n; i++) {
            len[i] = wordsContainer[i].size();
        }

        for (int i = 0; i < n; i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (string& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};