

public void findSumZero(int [] arr){

  int sumArray [] = new int[arr.length];

  sumArray[0] =  arr[0];

  for(int i=1 ; i<arr.length ; i++){
    sumArray[i] = sumArray[i-1] + arr[i];
  }

  for(int i=0;i<sumArray.length;i++){
    for(int j = i+1; j<sumArray.length;j++){
      if(sumArray[i] == sumArray[j] || sumArray[j] == 0){
	print(i,j,arr);
      }
    }
  }
}

    public void print(int i,int j,int [] arr){
      System.out.print("subArray is");
      for (int k = i; k<=j;k++){
	System.out.print(arr[k] + " ");
      }
      System.out.println();
    }
