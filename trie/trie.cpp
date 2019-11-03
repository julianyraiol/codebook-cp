#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;
 
struct Node{
    struct Node* children[ALPHABET_SIZE];
    char caracter;
    bool finalized;

    Node(){
        memset(children, false, sizeof(children));
        finalized = false;
    }
};

void insert(Node *root, string word){
    
    int index;
    for(char letter:word){
        index = letter-'a';
        
        if(!root->children[index]){
            root->children[index] = new Node();
            root->children[index]->caracter = letter;
        }
        root = root->children[index];
    }
    root->finalized = true;
}

void print(Node* root, string str, int spaces) 
{ 
    if (root->finalized != false){ 
        cout << str << endl; 
    } 

    for (Node* child:root->children){ 
        if (child){ 
            str.push_back(child->caracter); 
            print(child, str, spaces + 4); 
            str.pop_back();
        } 
    } 
} 

int main(){
    Node* root = new Node();
    string str;
    
    insert(root, "aaaa");
    insert(root, "abbbb");
    insert(root, "abc");
    print(root, str, 0);

}