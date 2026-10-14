
class Trie {
private:
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            // Initially, no character links exist
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';  // Map a-z to 0-25

            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }

            node = node->links[idx];
        }

        node->isEnd = true;  // Mark complete word
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->links[idx] == nullptr) {
                return false;
            }

            node = node->links[idx];
        }

        return node->isEnd;  // Must be a complete word
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->links[idx] == nullptr) {
                return false;
            }

            node = node->links[idx];
        }

        return true;  // Prefix path exists
    }
};
