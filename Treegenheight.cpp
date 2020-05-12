
int height(TreeNode<int>* root) {

    if(root==NULL)
    {return 0;}
    if(root->children.size()==0){
        return 1;
    }

  int h;
    int p=0;
    for(int i=0;i<root->children.size();i++){
 	h= height(root->children[i]);
   if(h>p){
       p=h;
   }
}
     return p+1;
}

#include <queue>
#include "solution.h"

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << height(root) << endl;
}
