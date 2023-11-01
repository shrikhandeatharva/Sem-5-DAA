#include<stdio.h>
int main(){
    float W=20,temp,p=0.0;//n-->no. of items,W-->weight limit of sack
    int i,n,j;
    float profit[] = {25,24,15};//profit of each element
    float weight[] = {18,15,10};//weight of each element
    n = sizeof(weight)/sizeof(weight[0]);
    float pbyw[n];//for storing profit by weight ratio of each item

    for(i=0;i<n;i++){
        pbyw[i] = (profit[i]/weight[i]);
    }

    for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(pbyw[j] > pbyw[i])   // for arranging the ratios in decreasing order 
            {    
                temp = pbyw[i];    
                pbyw[i] = pbyw[j];    
                pbyw[j] = temp;  

                   // Swap corresponding profit and weight elements
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

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