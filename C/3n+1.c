/*
* 3n + 1
*/
#include <stdio.h>

int main(){
	int i, j, k, curr_cycle_length, max_length, num, tmp;
	int temp_i;
    int temp_j;
	
	while(scanf ("%d %d", &i, &j) != EOF){
		max_length = 0;
		
		temp_i=i;
        temp_j=j;
        if(i>j)
        {
            tmp=temp_i;
            temp_i=temp_j;
            temp_j=tmp;
        }
		
		for(k = temp_i; k <= temp_j; k++){
			curr_cycle_length = 1;	
			num = k;
			while(num != 1){
				if(num%2 == 0)
					num = num >> 1;
				else
					num = 3*num+1;
				curr_cycle_length++;
			}
			if(curr_cycle_length > max_length)
				max_length = curr_cycle_length;					
				
		}
		
		printf("%d %d %d\n", i, j, max_length);
	}
	
	return 0;
}