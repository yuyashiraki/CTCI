/*Complete the function below
Node is as follows:
struct Node
{
    struct Node *left, *right;
    int data;
};*/
// Recursive  ** works only once
// Time O(n) Space O(height)
Node *pp = NULL, *first = NULL;
Node *bTreeToCList(Node *root)
{
//add code here.
    if (NULL == root) return NULL;
    if (first == root) return NULL;
    if (NULL == pp) {
        pp = root;
        while (pp->right) pp = pp->right;
    }
    //cout << root->data << endl;
    bTreeToCList(root->left);
    if (NULL == first) first = root;
    pp->right = root;
    root->left = pp;
    pp = root;
    bTreeToCList(root->right);
    return root;
}


Node *concatenate(Node *leftList, Node *rightList)
{
    if (leftList == NULL) return rightList;
    if (rightList == NULL) return leftList;
    Node *leftLast = leftList->left;
    Node *rightLast = rightList->left;
    leftLast->right = rightList;
    rightList->left = leftLast;
    leftList->left = rightLast;
    rightLast->right = leftList;
    return leftList;
}
Node *bTreeToCList(Node *root)
{
    if (NULL == root) return NULL;
    Node *left = bTreeToCList(root->left);
    Node *right = bTreeToCList(root->right);
    root->left = root->right = root;
    return concatenate(concatenate(left, root), right);
}
