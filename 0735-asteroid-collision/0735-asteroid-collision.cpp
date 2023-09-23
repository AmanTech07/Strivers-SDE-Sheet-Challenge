class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> sk;
        int n = v.size();
        for(int i=0; i<n; i++) {
            if(sk.empty() || v[i]>0 || sk.top()<0) sk.push(v[i]);
            else {
                while(1) {
                    if(sk.empty() || sk.top()<0) {
                        sk.push(v[i]);
                        break;
                    }
                    else {
                        if(sk.top()<abs(v[i])) sk.pop();
                        else  {
                            if(sk.top()==abs(v[i])) sk.pop();
                            break;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while(!sk.empty()) {
            ans.push_back(sk.top());
            sk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};