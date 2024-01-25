#######################################################################################  Question  ######################################################################################################

You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
Num1 = 1033 
Num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach Num2 from Num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
Num1 = 1033 
Num2 = 1033
Output:
0
Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1000<=Num1,Num2<=9999
Num1 and Num2 are prime numbers.



#######################################################################################  Solution  ######################################################################################################

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
 bool isPrime(int num){
        if(num<2) return 0;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return 0;
        }
        return 1;
    }
    int solve(int num1,int num2)
    {   
        if (num1 == num2) return 0;

        set<int> vis;
        queue<pair<int, int>> q;
        q.push({num1, 0});
        vis.insert(num1);
    
        while (!q.empty()) {
            int currNum = q.front().first;
            int dist = q.front().second;
            q.pop();
    
            for (int i = 0; i < 4; i++) {
                int oriNum = (int)(currNum /(pow(10, i))) % 10;
                for (int j = 0; j < 10; j++) {
                    if (j != oriNum) {
                        int newNum = currNum - (int)oriNum *(pow(10, i)) + (int)j * (pow(10, i));
                        if (isPrime(newNum) && vis.find(newNum) == vis.end() && newNum >= 1000 && newNum <= 9999) {
                            if (newNum == num2) return dist + 1;
                            q.push({newNum, dist + 1});
                            vis.insert(newNum);
                        }
                    }
                }
            }
        }
    
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
