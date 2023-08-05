/*
Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character,
return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
*/
char nonrepeatingCharacter(string S)
{
       //Your code here
       unordered_map<char, int> hash;
       for(int i=0; i<S.size(); i++){
           hash[S[i]]++;
       }
       for(int i=0; i<S.size(); i++){
           if(hash[S[i]]==1)
              return S[i];
       }
       return '$';
}