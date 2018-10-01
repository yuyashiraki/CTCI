struct Node
{
	int key;
	struct Node *left, *right;
};

// Update pre when moving down to right, update suc whem moving down to left
// When Node is found, pre = maximum in left subtree, suc = minimum in right subtree
// Time O(log(n))  Space O(log(n)) because of recursion
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root->key < key) {
        pre = root;
        if (root->right) findPreSuc(root->right, pre, suc, key);
    } else if (root->key > key) {
        suc = root;
        if (root->left) findPreSuc(root->left, pre, suc, key);
    } else { // root->key == key
        if (root->left) {
            pre = root->left;
            while (pre->right) pre = pre->right;
        }
        if (root->right) {
            suc = root->right;
            while (suc->left) suc = suc->left;
        }
    }
}
