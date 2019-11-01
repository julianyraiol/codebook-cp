#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

class Node{
    public:
    Node* children[ALPHABET_SIZE];
    bool finalized;

    Node(){
    
        finalized = false;
        for(int i = 0; i < ALPHABET_SIZE; i++){
            children[i] = NULL;
        }
    }

    void print_children(Node* root, string str, int level){
        if(root->finalized == true)
            cout << str << endl;
        else{
            for(int i = 0; i < ALPHABET_SIZE; i++){
                if(root->children[i] != NULL){
                    str[level] = i + 'a';
                    cout << str << endl;
                    print_children(root->children[i], str, level+1);
                }
            }
        }
    }

};

class Trie{
    public:
        Node* root;
    
        Trie();
        void insert(string);
        void search(string);
};

Trie::Trie(){
   root = new Node();
}

void Trie::insert(string word){
    char letter;
    for(int i = 0; i < word.size(); i++){
        letter = word[i];

        if(root->children[letter-'a'] == NULL){
            root->children[letter-'a'] = new Node();
        }
        root = root->children[letter-'a'];
    }
    root->finalized = true;
}

void Trie::search(string str){
    root->print_children(root, str, 0);
}

int main(){
    Trie* root = new Trie();
    string str;
    root->insert("a");
    root->insert("aff");
    root->insert("aaaell");
    root->search(str);
}

