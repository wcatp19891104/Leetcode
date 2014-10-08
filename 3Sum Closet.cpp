class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() == 3)
            return num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        int start;
        int end;
        int sum;
        int ret = num[0] + num[1] + num[2];
        
        for(int i = 0; i < num.size() - 2; i++) {
            start = i + 1;
            end = num.size() - 1;
            int t = target - num[i];
            sum = num[start] + num[end];
            while(start < end) {
                int temp = num[start] + num[end];
                if(abs(temp - t) < abs(sum - t))
                    sum = temp;
                if(temp == t)
                    return target;
                else if(temp > t)
                    end--;
                else
                    start++;
            }
            if(abs(sum - target + num[i]) < abs(ret - target))
                ret = sum + num[i];
        }
        return ret;
    }
};