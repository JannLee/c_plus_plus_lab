// p247_17_6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <string>


using namespace std;


struct Node
{
    string key;
    string value;

    Node* left;
    Node* right;
};


Node* Add(Node* tree, const string& key, const string& value);

Node* Remove(Node* tree, const string& key);
Node* FindMax(Node* tree);
Node* RemoveMax(Node* tree, Node* max);

Node* Find(Node* tree, const string& key);
Node* Clear(Node* tree);

void Print(Node* tree, int& depth);


int main()
{
    Node* tree = nullptr;
    int depth = 0;
    int menuNumber = 1;
    string menuString[5] = { "종료", "추가", "제거", "업데이트", "검색" };
    Node* node = nullptr;
    string name;
    string email;

    while (menuNumber != 0)
    {
        cout << "주소록(원하는 기능의 숫자를 입력하세요.)" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << "\t" << i << ". " << menuString[i] << endl;
        }
        cin >> menuNumber;

        if (menuNumber >= 0 && menuNumber < 5)
        {
            cout << "\t" << menuNumber << ". " << menuString[menuNumber] << endl;
            if (menuNumber == 0)
            {
                cout << "\t주소록을 삭제합니다." << endl;
                tree = Clear(tree);
                break;
            }
            else
            {
                cout << "\t이  름: ";
                cin >> name;
                node = Find(tree, name);
                if (node)
                {
                    email = node->value;
                }
                switch (menuNumber)
                {
                case 1:
                    if (node)
                    {
                        cout << "\t이미 추가됨: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t이메일: ";
                        cin >> email;
                        tree = Add(tree, name, email);
                        cout << "\t추가 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    break;
                case 2:
                    if (node)
                    {
                        tree = Remove(tree, name);
                        cout << "\t제거 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                case 3:
                    if (node)
                    {
                        cout << "\t이메일: ";
                        cin >> email;
                        tree = Add(tree, name, email);
                        cout << "\t업데이트 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                case 4:
                    if (node)
                    {
                        cout << "\t검색 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << menuNumber << ": 없는 기능입니다" << endl;
        }

        cout << endl;
    }

    return 0;
}

Node* Add(Node* tree, const string& key, const string& value)
{
    if (tree)
    {
        if (key < tree->key)
        {
            tree->left = Add(tree->left, key, value);
        }
        else if (key > tree->key)
        {
            tree->right = Add(tree->right, key, value);
        }
        else
        {
            tree->value = value;
        }
    }
    else
    {
        tree = new Node;
        tree->key = key;
        tree->value = value;
        tree->left = nullptr;
        tree->right = nullptr;
    }

    return tree;
}

Node* Remove(Node* tree, const string& key)
{
    if (tree)
    {
        if (key < tree->key)
        {
            tree->left = Remove(tree->left, key);
        }
        else if (key > tree->key)
        {
            tree->right = Remove(tree->right, key);
        }
        else
        {
            Node* max = FindMax(tree->left);
            if (max)
            {
                max->left = RemoveMax(tree->left, max);
                max->right = tree->right;
            }
            delete tree;
            tree = max;
        }
    }

    return tree;
}

Node* FindMax(Node* tree)
{
    if (tree && tree->right)
    {
        tree = FindMax(tree->right);
    }

    return tree;
}

Node* RemoveMax(Node* tree, Node* max)
{
    if (tree)
    {
        if (tree == max)
        {
            tree = max->left;
        }
        else
        {
            tree->right = RemoveMax(tree->right, max);
        }
    }

    return tree;
}

Node* Find(Node* tree, const string& key)
{
    if (tree)
    {
        if (key < tree->key)
        {
            tree = Find(tree->left, key);
        }
        else if (key > tree->key)
        {
            tree = Find(tree->right, key);
        }
    }

    return tree;
}

Node* Clear(Node* tree)
{
    if (tree)
    {
        tree->left = Clear(tree->left);
        tree->right = Clear(tree->right);
        delete tree;
        tree = nullptr;
    }

    return tree;
}

void Print(Node* tree, int& depth)
{
    if (tree)
    {
        cout << "[" << tree->key << "] = " << tree->value << endl;
        ++depth;
        for (int i = 0; i < depth; ++i)
        {
            cout << "    ";
        }
        cout << "Left:  ";
        Print(tree->left, depth);
        for (int i = 0; i < depth; ++i)
        {
            cout << "    ";
        }
        cout << "Right: ";
        Print(tree->right, depth);
        --depth;
    }
    else
    {
        cout << "Empty" << endl;
    }
}

