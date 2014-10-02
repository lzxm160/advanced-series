class Solution 
{
public:
    void removeOne(vector<int>& bits) {
        if(bits.size() <= 1) {
            return ;
        }
        int left = bits[0];
        vector<int>::iterator iter = bits.begin();
        while(iter != bits.end() && *iter <= left) {
            iter++; 
        }
        if (iter == bits.end()) {
            bits.erase(bits.begin());
        }
        else
        {
            bits.erase(iter);
        }
    }
    int removeK(int num, int k) {
        int res = 0;
        vector<int> bits;
        while (num > 0) {
            bits.push_back(num%10);
            num /= 10;
        }
        
        reverse(bits.begin(), bits.end());
        if(k >= bits.size()) {
            return 0;
        } 
        for (int i = 0; i < k; i++) {
            removeOne(bits);
        }
        for (int i = 0; i < bits.size(); i++) {
            res = res *10 + bits[i];
        }
        return res;
    }
};

