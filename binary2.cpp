int NthRoot(int n, int m) {
  // Write your code here.
  if(n==1||m==1) return m;
  if(m==0) return 0;
  int low=0;
  int high=m;
  while(low<=high){
    int mid=(low+high)/2;
    int pow=1;
    for(int i=0;i<n;i++){
      pow*=mid;
      if(pow>m) break;
    }
    if(pow==m) return mid;
    else if (pow<m) low=mid+1;
    else high=mid-1;
  }
  return -1;
}
