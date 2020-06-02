BinaryTreeNode<int>* helper(int *preorder,int prestart,int preend,int *inorder,int instart,int inend){

    if(prestart>preend || instart>inend)
    {
        return NULL;
    }

    int val=preorder[prestart];
BinaryTreeNode<int>* temp= new BinaryTreeNode<int>(val);
    int k=0;
    for(int i=instart;i<=inend;i++){
        if(inorder[i]==val){
            k=i;
            break;
        }

    }

    temp->left=helper(preorder,prestart+1,prestart+(k-instart),inorder,instart,k-1);
    temp->right=helper(preorder,prestart+(k-instart)+1,preend,inorder,k+1,inend);
    return temp;



}



BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here

  //  if(root==NULL){return NULL;}

   int  prestart=0;
    int preend=preLength-1;
    int instart=0;
    int inend=inLength-1;

    return helper(preorder,prestart,preend,inorder,instart,inend);
}
