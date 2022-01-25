#include <iostream>
using namespace std;

//Abstract class to create a Leftist Min-Heap Node
template <class T>

class LeftistNode
{
public:
    int element;
    LeftistNode* left;
    LeftistNode* right;
    int spl;
    LeftistNode(const T & element, LeftistNode* lt = NULL, LeftistNode* rt = NULL, int np = 0)
    {
        this->element = element;
        right = rt;
        left = lt;
        spl = np;
    }
};

//Abstract class that creates and initializes methods, root node, and basic functions for Leftist Heap
template <class T>

class LeftistHeap
{
public:
    LeftistHeap();
    LeftistHeap(const LeftistHeap &rhs);
    
    bool isEmpty();
    void insert(const T &x);
    int findMin();
    void deleteRoot();
    void merge(LeftistHeap &rhs);
    void showLH();
    void formatLH(LeftistNode<T>* n, int lvl);
    void showSPL();
    void formatSPL(LeftistNode<T>* n, int lvl);
    
private:
    LeftistNode<T>* root;
    LeftistNode<T>* merge1(LeftistNode<T>* h1, LeftistNode<T>* h2);
    LeftistNode<T>* merge2(LeftistNode<T>* h1, LeftistNode<T>* h2);
    void swapChildren( LeftistNode<T>* t );
};

//Default constructor
template<class T>

LeftistHeap<T>::LeftistHeap()
{
    root = NULL;
}

//Merge methods, first method calls 'merge1', second method calls 'merge2.'
//merge2 method swaps the children.
template <class T>

void LeftistHeap<T>::merge(LeftistHeap &rhs)
{
    if( this == &rhs)
        return;
    root = merge1(root, rhs.root);
    rhs.root = NULL;
}

template <class T>

LeftistNode<T>* LeftistHeap<T>::merge1(LeftistNode<T>* h1, LeftistNode<T>* h2)
{
    if( h1 == NULL )
        return h2;
    if( h2 == NULL )
        return h1;
    if( h1->element < h2->element )
        return merge2(h1, h2);
    else
        return merge2(h2, h1);
}

template <class T>

LeftistNode<T>* LeftistHeap<T>::merge2(LeftistNode<T>* h1, LeftistNode<T>* h2)
{
    if( h1->left == NULL)
        h1->left = h2;
    else
    {
        h1->right = merge1( h1->right, h2 );

        if( h1->left->spl < h1->right->spl )
            swapChildren( h1 );
        h1->spl = h1->right->spl + 1;
    }
    return h1;
}

//Method to insert data type into the heap
template<class T>

void LeftistHeap<T>::insert(const T &x)
{
    root = merge1(new LeftistNode<T>(x), root);
}

//Method to delete the min element(root)
template<class T>

void LeftistHeap<T>::deleteRoot()
{
    LeftistNode<T>* oldroot = root;
    root = merge1(root->left, root->right);
    delete oldroot;
}

//Swaps two children nodes
template<class T>

void LeftistHeap<T>::swapChildren(LeftistNode<T>* t)
{
    LeftistNode<T>* tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

template<class T>

bool LeftistHeap<T>::isEmpty()
{
    return root == NULL;
}

template<class T>

int LeftistHeap<T>::findMin()
{
    return root->element;
}

//Methods to visually display tree using "Reverse inorder tree traversal"
//displaying either the elements (showLH) or the spl values (showSPL)
template<class T>

void LeftistHeap<T>::showLH()
{
    if( root == 0 )
        cout << "Empty Tree" << endl;
    else
    {
        cout << endl;
        formatLH(root, 1);
    }
}

template<class T>

void LeftistHeap<T>::formatLH(LeftistNode<T>* n, int level)
{
    int j;
    
    if ( n != 0 )
    {
        formatLH(n->right, level+1);
        
        for( j = 0; j < level; j++ )
            cout << "\t";
        
        cout << "" << n->element;
        
        if((n->left != 0) && (n->right != 0))
            cout << "<";
        else if( n->right != 0 )
            cout << "/";
        else if( n->left != 0 )
            cout << "\\";

        cout << endl;
        formatLH(n->left, level+1);
    }
}

template<class T>

void LeftistHeap<T>::showSPL()
{
    if( root == 0 )
        cout << "Empty Tree" << endl;
    else
    {
        cout << endl;
        formatSPL(root, 1);
    }
}

template<class T>

void LeftistHeap<T>::formatSPL(LeftistNode<T> *n, int level)
{
    int j;
    
    if ( n != 0 )
    {
        formatSPL(n->right, level+1);
        for( j = 0; j < level; j++ )
            cout << "\t";
        cout << "" << n->spl;
        if((n->left != 0) && (n->right != 0))
            cout << "<";
        else if( n->right != 0 )
            cout << "/";
        else if( n->left != 0 )
            cout << "\\";
        cout << endl;
        formatSPL(n->left, level+1);
    }
}
