template <class temp>
class TreeNode{
  public:
    TreeNode();
    TreeNode(temp k);
    ~TreeNode();

    temp key;

    TreeNode *left;
    TreeNode *right;
};

template <class temp>
TreeNode<temp>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class temp>
TreeNode<temp>::TreeNode(temp k){
  key = k;
  left = NULL;
  right = NULL;
}

template <class temp>
TreeNode<temp>::~TreeNode(){
  //delete current??
}

template <class temp>
class bstTable{
  private:
    TreeNode *root;

  public:
    bstTable();
    ~bstTable();

    bool searchNode(temp value);
    void insertNode(temp value);
    bool deleteNode(temp k);

    bool isEmpty();
    unsigned int getSize();
    temp getMin();
    temp getMax();
    temp recPrint(TreeNode *node);

    TreeNode* getSuccessor(TreeNode *d);


};

bstTable<temp>::bstTable(){
  root = NULL;
}

bstTable<temp>::~bstTable(){
  //iterate and deleted => 0(n)
}

template <class temp>
void bstTable<temp>::insertNode(temp value){
  TreeNode *node = new TreeNode(value);
  if(isEmpty()){
    root = node;
  }
  else{
    TreeNode *current = root;
    TreeNode *parent = NULL;

    while(true){
      parent = current;

      if(value < current-> key){
        current = current->left;
        if(current == NULL){
          parent->left = node;
          break;
        }
      }
      else{
        current = current->right;
        if(current = NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class temp>
bool bstTable<temp>::searchNode(temp value){
  if(isEmpty())
    return false;
  else{
    TreeNode *current = root;
    while(current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;

      if(current == NULL)
        return false;
    }
  }
  return true;
}

template <class temp>
bool bstTable<temp>::deleteNode(temp k){
  if(isEmpty())
    return false;

  TreeNode *current = root;
  TreeNode *parent = root;
  bool ifLeftChild = true;

  while(current->key != k){
    parent = current;

    if(k < current->key){
      ifLeftChild = true;
      current = current->left;
    }
    else{
      ifLeftChild = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    }
  }
  //if we make it here, we found our key/value
  //now delete
  //case: node to delete has no children, AKA the leaf node
  if(current->left == NULL && current->right == NULL){
    if(current == root){
      root = NULL;
    }
    else if(ifLeftChild){
      parent->left = NULL;
    }
    else{
      //right child
      parent->right == NULL;
    }
  }
  //case: node to delete has one child, determine if node is left or right child
  else if(current->right == NULL){
    //node has one child and is a leaf
    //no right child
    if(current == root){
      root = current->left;
    }
    else if(ifLeftChild){
      parent->left = current->left;
    }
    else{
      parent->right = current->left;
    }
  }
  else if(current->left == NULL){
    //node has one child and is a leaf
    //no left child
    if(current == root){
      root = current->right;
    }
    else if(ifLeftChild){
      parent->left = current->right;
    }
    else{
      parent->right = current->right;
    }
  }
  else{
    //node to delete has two children
    TreeNode *successor = getSuccessor(current);
    if(current == root){
      root = successor;
    }
    else if(ifLeftChild){
      parent->left = sucessor;
    }
    else{
      parent->right = successor;
    }
    successor->left = current->left;
  }
  //delete current
  return true;
}

template <class temp>
bool bstTable<temp>::isEmpty(){
  if(root == NULL){
    return true;
  }else{
    return false;
  }
}

template <class temp>
int bstTable<temp>::getSize(){

}

template <class temp>
temp bstTable<temp>::getMin(){

}

template <class temp>
temp bstTable<temp>::getMax(){
  TreeNode *current = root;
  if(isEmpty())
    return null;

  while(current->right != NULL){
    current = current->right;
  }
  return current->key;
}

template <class temp>
temp bstTable<temp>::recPrint(TreeNode *node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->key << endl;
    recPrint(node->right);
  }
}

template<class temp>
void bstTable<temp>::printEntireTree(){
  recPrint(root);
}

template <class temp>
TreeNode* bstTable<temp>::getSuccessor(TreeNode *d){
  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
