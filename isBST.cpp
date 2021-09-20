bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}

