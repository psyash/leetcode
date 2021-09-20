
vector<int> twoSum(vector<int> &nums, int target){
  unordered_map<int,int> hash;
  vector<int> res;

  for(int i=0;i<nums.size();i++){
    int numberToFind = target - nums[i];
    //if number is found in hashmap
    if(hash.find(numberToFind) != hash.end()){
      res.push_back(hash[numberToFind]);
      res.push_back(i);
      return res;
    }
    //if number not found
    hash[nums[i]] = i;
  }
  return res;
}
