/*
题目描述

请实现两个函数，分别用来序列化和反序列化二叉树
*/


class Solution {
public:
  
    string itoa(int n) {
        string res;
        bool neg = n < 0;
        if (n == 0)
            return "0";
          
        while(n) {
            res += (n % 10) + '0';
            n /= 10;
        }
          
        if (neg) {
            res += '-';
        }
          
        reverse(res.begin(), res.end());
        return res;
    }
     ////fdsafdsafds
    int readNext(char *str, int &pos) {
        int res = 0;
        bool neg = (str[pos] == '-');
        if (str[pos] == '-')
            pos++;
          
        for(;str[pos] && str[pos] != ',';pos++) {
            res *= 10;
            res += str[pos] - '0';
        }
          
        // skip delim
        pos++;
        return neg ? -res : res;
    }
          
    char* Serialize(TreeNode *root) {  
       string str;
          
       stack<TreeNode *> nodeStack;
       nodeStack.push(root);
          
       while(!nodeStack.empty()) {
           TreeNode *node = nodeStack.top();
           nodeStack.pop();
              
           if (node == NULL) {
               str += "#,";
           } else {
               str += itoa(node->val) + ",";
               nodeStack.push(node->right);
               nodeStack.push(node->left);
           }
        }
          
        char *res = (char *)malloc(sizeof(char) * (str.size() + 1));
        for(int i = 0;i < str.size();i++) {
            res[i] = str[i];
        }
          
        res[str.size()] = '\0';
        return res;
    }
     ///dsafdsafsd
    TreeNode* Deserialize(char *str) {
        if (str[0] == '#')
            return NULL;
          
        int nextPos = 0;
        stack<TreeNode *> nodeStack;
        TreeNode *root = new TreeNode(readNext(str, nextPos));
        nodeStack.push(root);
        TreeNode *pre = root;
          
          
        while(str[nextPos] != '#') {
            pre->left = new TreeNode(readNext(str, nextPos));
            pre = pre->left;
            nodeStack.push(pre);
        }
        nextPos += 2;
          
          
        while(!nodeStack.empty()) {
            TreeNode *pre = nodeStack.top();
            nodeStack.pop();
          
            if (str[nextPos] != '#') {
                pre->right = new TreeNode(readNext(str, nextPos));
                pre = pre->right;
                nodeStack.push(pre);
                  
                while(str[nextPos] != '#') {
                    pre->left = new TreeNode(readNext(str, nextPos));
                    pre = pre->left;
                    nodeStack.push(pre);
                }
            }
            nextPos += 2;
        }
      
        return root;
    }
};
