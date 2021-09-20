//Brute force - check all the substring one by one to see if it had no duplicate charater

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();

      int res = 0;
      for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
          if(checkRepetition(s,i,j)){
            res = max(res, j-i+1);
          }
        }
      }
      return res;    
    }

    bool checkRepetition(string& s, int start, int end){
      vector<int> chars(128);

      for(int i=start;i<=end;i++){
        char c = s[i];
        chars[c]++;
        if(chars[c]>1){
          return false;
        }
      }
      return true;
    }
};


//Optimized (sliding window)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
      vector<int> chars(128);
      //left and right boundaries
      int left = 0;
      int right = 0;

      int res = 0;
      
      while(right < s.length()){
        char r = s[right];
        chars[r]++;

        while(chars[r]>1){
          char l = s[left];
          chars[l]--;
          left++;
        }
        res = max(res, right - left + 1);
        right++;
      }
      return res;        
    }
};


//optimized sliding window
class Solution{
  public:

  int lengthOfLongestSubstring(string s){

    vector<int> chars(128, -1);

    int left = 0;
    int right = 0;

    int res = 0;

    while(right < s.length()){
      char r = s[right];

      int index = chars[r];
      if(index !=-1 and index >= left and index < right){
        left = index + 1;
      }
      res = max(res, right - left + 1);

      chars[r] = right;
      right++;
    }
    return res;
  }
};