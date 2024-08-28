class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> PLE(n);
        vector<int> NLE(n);
        stack<int> s;
        const int MOD = 1e9 + 7;

        for(int i=0;i<n;++i){
            while(!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            
            if(s.empty())
                PLE[i] = -1;
            else
                PLE[i] = s.top();
            s.push(i);
        }

        while(!s.empty())
            s.pop();

        for(int i=n-1;i>=0;--i){
            while(!s.empty() && arr[s.top()] > arr[i])
                s.pop();
            if(s.empty())
                NLE[i] = n;
            else
                NLE[i] = s.top();
            s.push(i);
        }

        long long sum = 0;
        for(int i=0;i<n;++i){
            long long left = i - PLE[i];
            long long right = NLE[i] - i;
            sum = (sum + arr[i] * left * right)%MOD;
        }

        return sum;
    }
};