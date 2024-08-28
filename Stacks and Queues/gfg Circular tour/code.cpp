/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int start = 0;
       int total_petrol = 0;
       int total_distance = 0;
       int curr_balance = 0;
       
       for(int i=0;i<n;i++){
           total_petrol+=p[i].petrol;
           total_distance+=p[i].distance;
           curr_balance +=(p[i].petrol-p[i].distance);
           
           if(curr_balance<0){
               start = i+1;
               curr_balance = 0;
               
           }
       }
       
       if(total_petrol >= total_distance)
           return start;
       return -1;
    }
};