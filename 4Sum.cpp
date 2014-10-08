class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if(num.size() < 4)
            return ret;
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size() - 3; i++) {
            if(i != 0 && num[i] == num[i - 1])
                continue;
            for(int j = i + 1; j < num.size() - 2; j++) {
                if(j != i + 1 && num[j] == num[j - 1])
                    continue;
                int start = j + 1;
                int end = num.size() - 1;
                int t = target - num[i] - num[j];
                while(start < end) {
                    if(num[start] + num[end] == t) {
                        vector<int> pass;
                        pass.push_back(num[i]);
                        pass.push_back(num[j]);
                        pass.push_back(num[start]);
                        pass.push_back(num[end]);
                        ret.push_back(pass);
                        start++;
                        end--;
                        while(left < right && num[start - 1] == num[start])
                            start++;
                        while(left < right && num[end + 1] == num[end])
                            end--;
                    }
                    else if(num[start] + num[end] > t)
                        end--;
                    else
                        start++;
                }
            }
        }
        
        return ret;
    }
};