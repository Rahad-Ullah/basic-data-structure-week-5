#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string text = "";
    stack<char> redoStack;

    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;

        if (op == "TYPE")
        {
            char x;
            cin >> x;
            text.push_back(x);

            while (!redoStack.empty())
            {
                redoStack.pop();
            }
        }
        else if (op == "UNDO")
        {
            if (!text.empty())
            {
                char lastChar = text.back();
                text.pop_back();
                redoStack.push(lastChar);
            }
        }
        else if (op == "REDO")
        {
            if (!redoStack.empty())
            {
                char restoredChar = redoStack.top();
                redoStack.pop();
                text.push_back(restoredChar);
            }
        }
    }

    cout << text << endl;

    return 0;
}