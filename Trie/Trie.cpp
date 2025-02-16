#include <iostream>
using namespace std;

class TrieNode {
    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this->data = ch;
            for( int i = 0; i < 26; i++) {
                this->children[i] = NULL;
            }
            this->isTerminal = false;
        }

};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if ( word.length() == 0 ){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if ( root->children[index] != NULL ) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if( word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if( root->children[index] != NULL ){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));

    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode* root, string word) {
        if( word.length() == 0) {
            bool term = root->isTerminal;
            if ( term )
            root->isTerminal = false;
            return term;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if( root->children[index] != NULL ){
            child = root->children[index];
        }
        else{
            return false;
        }
        return removeUtil(child, word.substr(1));

    }

    bool removeWord(string word) {
        return removeUtil(root, word);
    }

};

int main() {

    Trie* t = new Trie();
    t->insertWord("ABCD");
    // Insertion T.C - O(length of word)
    // search TC - O(Length Of Word)

    cout << " Present or not " << t->search("ABCD") << endl;

    // word ko search krlo , then terminal node ko false krdo
    cout << " Is word removed - " << t->removeWord("ABCD") << endl;

    cout << " Present or not " << t->search("ABCD") << endl;

    return 0;

}