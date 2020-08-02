class Tree {
    int key;
    Tree * left;
    Tree * right;
    
    public:
    Tree * insert(Tree * root, int key)
    {
        if(root==NULL)
        {
            Tree * newNode= new Tree();
            newNode->key=key;
            newNode->left=NULL;
            newNode->right=NULL;
            return newNode;
        }
        if(key<root->key)
            root->left=insert(root->left,key);
        else
            root->right=insert(root->right,key);
        return root;
    }
    
    bool search(Tree * root, int key)
    {
        if(root==NULL)
            return false;
        if(root->key==key)
            return true;
        if(key<root->key)
            return search(root->left,key);
        return search(root->right,key);
    }
    
    Tree * findMin(Tree * root)
    {
        Tree * current=root;
        while(current && current->left)
            current=current->left;
        return current;
    }
    
    Tree * deleteNode(Tree *root, int key)
    {
        if(root==NULL)
            return root;
        if(key<root->key)
            root->left=deleteNode(root->left,key);
        else
        {
            if(key>root->key)
                root->right=deleteNode(root->right,key);
            else
            {
                if(root->left==NULL)
                {
                    Tree * temp=root->right;
                    delete(root);
                    return temp;
                }
                else
                {
                    if(root->right==NULL)
                    {
                        Tree * temp=root->left;
                        delete(root);
                        return temp;
                    }
                    else
                    {
                        Tree * temp=findMin(root->right);
                        root->key=temp->key;
                        root->right=deleteNode(root->right,temp->key);
                    }
                }
            }
        }
        return root;
    }
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    Tree * root;
    Tree rootPtr;
    MyHashSet() {
        root=NULL;
    }
    
    void add(int key) {
        if(!(this->contains(key)))
            root=rootPtr.insert(root,key);
    }
    
    void remove(int key) {
        if(this->contains(key))
        {
            root=rootPtr.deleteNode(root,key);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(rootPtr.search(root,key))
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */