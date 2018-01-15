// luỹ thừa trên giai thừa 
float LuyThua(float x , float n) 
  { 
        if(n == 1) 
        { 
              return x; 
        } 
        return LuyThua(x,n-1)*x; 
  } 
    
  float GiaiThua(float n) 
  { 
        if(n == 1) 
        { 
              return (float)1; 
        } 
        return GiaiThua(n-1)*n; 
  } 
    
  float LTChiaGT(float x , float n) 
  {         if(n == 1) 
        { 
              return x; 
        } 
        return LTChiaGT(x,n-1) + ((LuyThua(x,n-1)*x) / (GiaiThua(n-1)*n)); 
  } 
  //Tính S(n) = 1^2 + 2^2 + 3^2 + ... + (n-1)^2 + n^2 
  int Tinh(int n) 
  { 
                  if (n==1) 
                           return 1; 
                  return Tinh(n-1) + n*n; 
  } 
  //Tính S(n) = 1 + 1/2 + 1/3 + ... + 1/n 
  float Tinh(float n) 
  { 
                  if (n==1) 
                            return 1; 
                  return Tinh(n-1) + 1/n; 
  } 
  //Tính S(n) = 1/2 + 1/4 + ... + 1/2n 
  float Tinh(float n){
  if (n==1)
	return 0.5;
	return Tinh(n-1) + 1/(2*n);
}
//Tính S(n) = 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2) 
float Tinh(float n) 
  { 
                  if (n==1) 
                                  return 0.5; 
                  return Tinh(n-1) + (2*n+1)/(2*n+2); 
  } 
  //Tính S(x,n) = x^2 + x^4 +.... + x^2n 
  double bai742(int x, int n) 
  { 
              if (n==1) 
              { 
                          return pow(x,2*n); 
              } 
              return bai742(x,n-1) + pow(x,2*n); 
  }