/*Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, 
you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have
appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append 
'#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/

string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char, int> hash;
		    hash[A[0]]++;
		    
		    queue<char> q;
		    q.push(A[0]);
		    
		    string s;
		    s.push_back(A[0]);
		    int j = 0;
		    
		    for(int i=1; i<A.size(); i++){
		        hash[A[i]]++;
		        ++j;
                if(hash[A[i]]==1)
                   q.push(A[i]);
                while(!q.empty()){
                    if(hash[q.front()]==1){
                        s += q.front();
                        break;
                    }
                    q.pop();
                } 
                if(q.empty())
                   s += '#';
		    }
		   return s;
}

//Expected Time Complexity: O(n)
//Expected Space Complexity: O(n)