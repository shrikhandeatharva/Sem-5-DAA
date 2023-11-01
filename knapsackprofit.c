#include<stdio.h>
int main(){
    float W=20,temp,p=0.0;//n-->no. of items,W-->weight limit of sack
    int i,n,j;
    float profit[] = {25,24,15};//profit of each element
    float weight[] = {15,18,10};//weight of each element
    n = sizeof(weight)/sizeof(weight[0]);
    

    for(i = 0; i < n; i++)    //sort the items according to their profit in decreasing order
    {    
      for(j = i+1; j < n; j++)    
        {    
               if(profit[j] > profit[i]){
                
                   // Swap profit elements
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                  // Swap corresponding weight elements
                  temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;  

               }
                
        }     
    }

    for(i=0;i<n;i++){
        if(W>0 && weight[i]<W){
        W = W - weight[i];
        p = p + profit[i];
        }
        else if(W>0){        
            // p = p + ((float)profit[j]*((float)W/(float)weight[j]));
            float fraction = W / weight[i];//same as above commented statement but dont know why the above one is not working
            p += profit[i] * fraction;
        break;
        }
    }
    
    printf("Total profit : ");
    printf("%.2f",p);

    return 0;
}