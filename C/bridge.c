/*
Bridge
*/
#include <stdio.h>

void csort(int array[], const int end, const int max, const int min)
{
  int i;
  const int range = max-min+1;
  int count[range+1], scratch[end];
 
  for(i=0; i<range+1; i++) count[i] = 0;
 
  /* Set the value of count[i] to the number of elements in array with value i+min-1. */
  for(i=0; i<end; i++) { int c = array[i]+1-min; count[c]++; }
 
  /* Update count[i] to be the number of elements with value less than i+min. */
  for(i=1; i<range; i++) count[i] += count[i-1];
 
  /* Copy the elements of array into scratch in stable sorted order. */
  for(i=(end-1); i>=0; i--) {
    int c = array[i]-min;
    int s = count[c];
    scratch[s] = array[i];
    /* Increment count so that the next element with the same value as the current element is placed into its own position in scratch. */
    count[c]++;
  }
 
  for(i=0; i<end; i++) array[i] = scratch[i];
}

int main(){
	int n, i, numDst=0, tTotal=0, j=0, numCasos;
	scanf("%d\n\n", &numCasos);
	while(numCasos>0) {
		/* lee num personas */
		scanf("%d\n", &n);
		/* lee tiempos de paso */
		int t[1001];
		for (i=0; i<n; i++) scanf("%d\n", &t[i]);
		/* ordena los tiempos de paso */
		csort(t, n, 100, 1);
				
		int pasos[10000][2];
		int A = t[0], B;
		if (n>1) B = t[1];
		while( n - numDst >3 ) {
			/* mientras queden mas de 3 a la izq */
			int C = t[n-numDst-2], D = t[n-numDst-1];
			if ( 2*B+A+D > 2*A + C + D ) {  
				/* vuelve siempre A */
				tTotal += 2*A+C+D;
				pasos[j+0][0]=A; pasos[j+0][1]=D; 
				pasos[j+1][0]=A; pasos[j+1][1]=0;
				pasos[j+2][0]=A; pasos[j+2][1]=C; 
				pasos[j+3][0]=A; pasos[j+3][1]=0;
				
			}
			else { 
				/* vuelve primero A y luego B */
				tTotal += 2*B+A+D;
				pasos[j+0][0]=A; pasos[j+0][1]=B; 
				pasos[j+1][0]=A; pasos[j+1][1]=0;
				pasos[j+2][0]=C; pasos[j+2][1]=D; 
				pasos[j+3][0]=B; pasos[j+3][1]=0;
			}
			numDst += 2;
			j += 4;
		}
		if (n-numDst == 3) {
			/* quedan 3 a la izquierda */
			int C = t[n-numDst-1];
			pasos[j+0][0]=A; pasos[j+0][1]=C; 
			pasos[j+1][0]=A; pasos[j+1][1]=0;
			pasos[j+2][0]=A; pasos[j+2][1]=B;
			tTotal += C + A + B;
			j += 3;
				
		}
		else if (n-numDst == 2) {
			/* quedan 2 a la izquierda */
			pasos[j+0][0]=A; pasos[j+0][1]=B;
			j++;
			tTotal += B;
		}
		else { /* solo queda 1 */
			pasos[j+0][0]=A; pasos[j+0][1]=0;
			j++;
			tTotal += A;
		}
		
		printf("%d\n", tTotal);
		for (i=0; i<j; i++) {
			if(i == j-1){
				if (pasos[i][1] == 0) printf("%d", pasos[i][0]);
				else printf("%d %d", pasos[i][0], pasos[i][1]);
			}
			else
				if (pasos[i][1] == 0) printf("%d\n", pasos[i][0]);
				else 
				printf("%d %d\n", pasos[i][0], pasos[i][1]);
		}
		
		numCasos--;
		
		if (numCasos != 0) {
			scanf("\n");
			printf("\n\n");
			tTotal=0; j=0;
			numDst = 0;
		}
	
	}
	
	return (0);
}
