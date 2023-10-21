class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int> nums;
        string token;
        int o1, o2;
        for(int i=0; i<tokens.size(); i++)
        {
            token = tokens[i];
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                o1 = nums.top();
                nums.pop();
                o2 = nums.top();
                nums.pop();
                if(token == "+")
                    nums.push(o2 + o1);
                if(token == "-")
                    nums.push(o2 - o1);
                if(token == "*")
                    nums.push(o2 * o1);
                if(token == "/")
                    nums.push(o2 / o1);
            }
            else 
                nums.push(stoi(token));
        }
        return nums.top();
        
    }
};