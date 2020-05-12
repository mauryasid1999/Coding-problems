TreeNode<int>* maxDataNode(TreeNode<int>* root) {
  
 if(root==NULL)
 {return NULL;}
    TreeNode<int>* Maxnode=new TreeNode<int>(0);
    int max=0;

    for(int i=0;i<root->children.size();i++){
        if(max<maxDataNode(root->children[i])->data){
            max=maxDataNode(root->children[i])->data;
            Maxnode=maxDataNode(root->children[i]);
    }
    }
    if(Maxnode->data<root->data){
        Maxnode=root;
        return Maxnode;
    }
    return Maxnode;


    }
