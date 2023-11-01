#include<stdio.h>
int main(){
    float W=20,temp,p=0.0;//n-->no. of items,W-->weight limit of sack
    int i,n,j;
    float profit[] = {21,24,15};//profit of each element
    float weight[] = {15,18,10};//weight of each element
    n = sizeof(weight)/sizeof(weight[0]);
    
    for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(weight[j] < weight[i])   
            {    
                  // for arranging the weights in increasing order 
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp; 

                 // swapping the corresponding profits of items
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;  
            }     
        }     
    }

    for(i=0;i<n;i++){
        if(W>0 && weight[i]<W){
        W = W - weight[i];
        p = p + profit[i];
        }
        else if(W>0){        
            float fraction = W / weight[i];
            p += profit[i] * fraction;
        break;
        }
    }
    
    printf("Total profit : ");
    printf("%.2f",p);

    return 0;
}