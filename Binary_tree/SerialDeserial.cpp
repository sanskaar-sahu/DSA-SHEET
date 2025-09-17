/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
        // Helper: split string by ','
    vector<string> split(const string &s) {
        vector<string> tokens;
        string temp;
        for(char c : s){
            if(c == ','){
                tokens.push_back(temp);
                temp.clear();
            } else temp.push_back(c);
        }
        if(!temp.empty()) tokens.push_back(temp); // last token
        return tokens;
    }

        // Helper: build tree from array representation
    TreeNode* build(vector<string>& nodes, int idx) {

        if(idx >= nodes.size() || nodes[idx] == "x") return NULL;

        TreeNode* node = new TreeNode(stoi(nodes[idx]));   //stoi = string to integer

        node->left = build(nodes, 2*idx + 1);

        node->right = build(nodes, 2*idx + 2);

        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if(cur){
                res += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else res += "x,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
          if(data.empty()) return NULL;
        vector<string> nodes = split(data);
        if(nodes[0] == "x") return NULL;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() && i < nodes.size()){
            TreeNode* cur = q.front(); q.pop();

            if(i < nodes.size() && nodes[i] != "x"){
                cur->left = new TreeNode(stoi(nodes[i]));
                q.push(cur->left);
            }
            i++;

            if(i < nodes.size() && nodes[i] != "x"){
                cur->right = new TreeNode(stoi(nodes[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;

    }
};

