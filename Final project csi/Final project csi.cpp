#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

// Note, had some help making this from these two websites
// https://www.geeksforgeeks.org/kd-trees-in-cpp/
// https://www.baeldung.com/cs/k-d-trees

const int k = 2;

struct Node {
    vector<float> point;  
    Node* left;
    Node* right;
    int count = 0;

    Node(const vector<float>& point) : point(point), left(nullptr), right(nullptr) {}
};

Node* insertRec(Node* root, const vector<float>& point, int depth) {
    if (root == nullptr) {
        return new Node(point);
        root->count++;
    }

    int cd = depth % k;
    if (point[cd] < root->point[cd]) {
        root->left = insertRec(root->left, point, depth + 1);
    }
    else {
        root->right = insertRec(root->right, point, depth + 1);
    }

    return root;
}

void insert(Node*& root, const vector<float>& point) {
    root = insertRec(root, point, 0);
}

void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << "(" << root->point[0] << ", " << root->point[1] << ")" << endl;
        printInOrder(root->right);
    }
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        root->count = 0;
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    insert(root, {5, 6});
    insert(root, {17, 15});
    insert(root, {13, 15});
    insert(root, {6, 12});
    insert(root, {9, 1});
    insert(root, {20, 7});
    insert(root, {10, 19});
    insert(root, {12, 14});
    insert(root, {12, 14});
    insert(root, {1, 8});
    insert(root, {5, 17});
    insert(root, {19, 4});
    insert(root, {21, 19});

    cout << "Inorder traversal of the first kd-tree:" << endl;
    printInOrder(root);
    deleteTree(root);
    cout << endl;

    Node* second = nullptr;
    insert(second, { 5, 6 });
    insert(second, { 17, 15 });
    insert(second, { 13, 15 });
    insert(second, { 6, 12 });
    insert(second, { 9, 1 });
    insert(second, { 20, 7 });
    insert(second, { 10, 19 });
    insert(second, { 12, 14 });
    insert(second, { 12, 14 });
    insert(second, { 1, 8 });
    insert(second, { 5, 17 });
    insert(second, { 19, 4 });
    insert(second, { 21, 19 });

    cout << "Inorder traversal of the next kd-tree:" << endl;
    printInOrder(second);
    deleteTree(second);
    cout << endl;

    Node* custom = nullptr;

    string ending;
    int amount = 0;
    float valueOne = 1;
    float valueTwo = 2;

    cout << "how many nodes do you want?" << endl;
    cin >> amount;

    for (int i = 0; i < amount; i++) {
        cout << "X:" << endl;
        cin >> valueOne;
        cout << "Y" << endl;
        cin >> valueTwo;

        insert(custom, {valueOne, valueTwo});
    }

    cout << "Inorder traversal of the custom kd-tree:" << endl;
    printInOrder(custom);
    deleteTree(custom);
    cout << endl;

    cout << "when done type 'e' and enter pls" << endl;
    cin >> ending;

    return 0;
}
