/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */
Node *minChild(Node *root)
{
    while (root->left) {
        root = root->left;
    }
    return root;
}
Node * deleteNode(Node *root,  int x)
{
    //cout << root->data << endl;
    if (NULL == root) return NULL;
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else { // x == root->data
        if (NULL == root->left) {
            Node *tmp = root;
            root = root->right;
            free(tmp);
        } else if (NULL == root->right) {
            Node *tmp = root;
            root = root->left;
            free(tmp);
        } else {
            Node *tmp = minChild(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }

    }
    return root;
}

/* This function should insert a new node with given data and
   return root of the modified tree  */
struct node* insert(struct node* node, int data)
{
    // Your code here
    struct node *newNode = (struct node*)malloc(sizeof(struct node)), *cur = node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (!node) return newNode;
    while (1) {
        if (data < cur->data) {
            if (cur->left) cur = cur->left;
            else {
                cur->left = newNode;
                break;
            }
        } else if (data > cur->data) {
            if (cur->right) cur = cur->right;
            else {
                cur->right = newNode;
                break;
            }
        } else {
            break;
        }
    }
    return node;
}
