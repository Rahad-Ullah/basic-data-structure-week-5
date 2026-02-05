#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void print_specific_level(Node *root, int level)
{
    if (root == NULL)
    {
        cout << "Invalid" << endl;
        return;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    bool found = false;
    vector<int> v;

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();

        Node *node = p.first;
        int l = p.second;

        if (l == level)
        {
            found = true;
            v.push_back(node->val);
        }

        if (l < level)
        {
            if (node->left)
                q.push({node->left, l + 1});
            if (node->right)
                q.push({node->right, l + 1});
        }
    }

    if (!found)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
}

int main()
{
    Node *root = input_tree();
    int x;
    cin >> x;

    print_specific_level(root, x);

    return 0;
}