/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

struct Tuple{
    TreeNode* node;
    int level;
};

public:
    vector<int> largestValues(TreeNode* root) {
        TreeNode* temp = root;
        vector<int> answer; 
        queue<Tuple> q; 
        Tuple tuple;
        tuple.node = temp;
        tuple.level = 0;

        if(temp == NULL){
            return answer;
        }

        q.push(tuple);
        int max = temp->val;
        int currentlevel = 0;
        while(!q.empty()){
            temp = q.front().node;

            if(temp != NULL){
                cout<<temp->val<< " " << q.front().level << endl;
            }
        
            if (currentlevel != q.front().level ){
                currentlevel = q.front().level;
                answer.push_back(max);
                max = temp->val;
            }
            if (temp->val > max ){
                max = temp->val;
            }

            if (temp->left != NULL) {q.push({temp->left, q.front().level+1}); }
            if (temp-> right != NULL) {q.push({temp->right, q.front().level+1});}
            q.pop();
        }
        answer.push_back(max);
        return answer;
    }
};
