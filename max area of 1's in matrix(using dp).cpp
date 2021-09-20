int maximalRectangle(char [][] matrix){
  if(matrix.length==0) return 0;

  int rows = matrix.length, cols = matrix[0].length, maxArea=0;
  //for each point topleft
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      //construct isValid
      bool[][] isValid = new bool[rows][cols];
      //for each point bottom right
      for(int x=i;x<rows;x++){
        for(int y=j;y<cols;y++){
          if(matrix[x][y]!='1') continue;
          //check if valid matrix
          isValid[x][y] = true;
          if(x>i) isValid[x][y] = isValid[x][y] && isValid[x-1][y];
          if(y>j) isValid[x][y] = isValid[x][y] && isValid[x][y-1];

          if(isValid[x][y]){
            int area = (x-i+1)*(y-j+1);
            maxArea = max(maxArea,area);
          }
        
        }
      }
    }
    return maxArea;
  }





}