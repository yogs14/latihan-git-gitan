#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


Node* sisipkanNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = sisipkanNode(root->left, value);
    } else if (value > root->data) {
        root->right = sisipkanNode(root->right, value);
    }

    return root;
}

string cariJalur(Node* root, int target) {
    string jalur;

    while (root != nullptr) {
        if (target == root->data) {
            jalur += "S"; 
            break;
        } else if (target < root->data) {
            jalur += "L"; 
            root = root->left;
        } else {
            jalur += "R"; 
            root = root->right;
        }
    }

    return jalur;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = sisipkanNode(root, value);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        string jalur = cariJalur(root, target);
        cout << jalur << endl;
    }

    return 0;
}
