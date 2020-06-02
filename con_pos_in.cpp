
BinaryTreeNode<int>* helper(int *postorder,int postart,int poend,int* inorder,int instart,int inend )
{
    if(postart>poend || instart>inend){return NULL;}
    int val=postorder[poend];
    BinaryTreeNode<int>* temp=new BinaryTreeNode<int>(val);
    int k=0;
    for(int i=instart;i<=inend;i++){
        if(inorder[i]==val){
            k=i;
            break;
        }
    }
    int p=k-instart;

    temp->left=helper(postorder,postart,postart+p-1,inorder,instart,instart+p-1);
    temp->right=helper(postorder,postart+p,poend-1,inorder,instart+p+1,inend);

    return temp;
}



BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here

    int postart=0;
    int poend=postLength-1;
    int instart=0;
    int inend=inLength-1;
    return helper(postorder,postart,poend,inorder,instart,inend);


}
