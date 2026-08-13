class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size(),sum=0,j=0;
        vector<int> res(n); 
        for(int i=0;i<n;i++) {
            if(operations[i]=="D") {
                int prev = res[j-1]*2;
                res[j++] = prev;
            }
            else if(operations[i]=="C") 
                j--;
            else if(operations[i]=="+") {
                res[j] = res[j-1]+res[j-2];
                j++;
            }
            else 
                res[j++] = stoi(operations[i]);
        }
        
        for(int i=0;i<j;i++)
            sum += res[i];
        return sum;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)