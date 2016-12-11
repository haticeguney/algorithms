#include <stdio.h>
 
/* This structure is used to return 
 two values from a function */
struct MaxMin {
    int min;
    int max;
}; 
 
/* Implementation of tournament method using recursion */
struct MaxMin getMinMax(int *array, int left, int right) {
    struct MaxMin result, resultLeft, resultRight;       
    int mid;
    
    result.max = array[left];
    result.min = array[left];
   
    if(right == left)
        return result; 
    /* Split the array into two equal sub arrays and 
    recursively find max and min in both sub array */
    mid = (left + right)/2;  
    resultLeft = getMinMax(array, left, mid);
    resultRight = getMinMax(array, mid+1, right);  
    
    /* Take the maximum of both sub array */
    if (resultLeft.max > resultRight.max)
       result.max = resultLeft.max;
    else
       result.max = resultRight.max;    
     
    /* Take the minimum of both sub array */
    if (resultLeft.min < resultRight.min)
       result.min = resultLeft.min;
    else
       result.min = resultRight.min;     
  
    /* Return the maximum and minimum of whole array */
    return result;
}
 
int main(){
    int array[9] = {7, 3, 9, 7, -3, -1, 4, 0, 7}; 
 
    struct MaxMin maxmin = getMinMax(array, 0, 8); 
     
    printf("Maximum = %d\n", maxmin.max);
    printf("Minimum = %d\n", maxmin.min);
     
    return 0;
}