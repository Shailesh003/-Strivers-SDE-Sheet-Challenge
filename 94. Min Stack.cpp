#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<pair<int,int>> st;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(st.empty()){
				st.push({num,num});
				return;
			}
			if(st.top().second>num){
                st.push({num, num});
            }
			else{
				st.push({num,st.top().second});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{	if(st.empty())return -1;
			int ans=st.top().first;
			st.pop();
			return ans;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{	if(st.empty())return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{   if(st.empty())return -1;
			return st.top().second;
		}
};