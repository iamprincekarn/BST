
 class BSTiterator{
     private:
     stack<TreeNode*>myStack;
     bool reverse = true;
     public:
     BSTiterator(TreeNode*root,bool isReverse){
         reverse = isReverse;
         pushAll(root,reverse);
     }
     bool hasNext()
     {
         return !myStack.empty();
     }
     int next()
     {
        
        TreeNode*node = myStack.top();
        myStack.pop();
        if(reverse == true) pushAll(node->left,reverse);
        else pushAll(node->right,reverse);
        return node->val;
     }
     private:
     void pushAll(TreeNode*node,bool reverse)
     {
        while(node!=NULL)
        {
            myStack.push(node);
            if(reverse)
            node = node->right;
            else
            node = node->left;
        }
     }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i =l.next();
        int j = r.next();
        while(i<j)
        {
            if(i+j == k)
            return true;
            else if(i+j<k)
            i = l.next();
            else
            j = r.next();
        }
        return false;
    }
};










