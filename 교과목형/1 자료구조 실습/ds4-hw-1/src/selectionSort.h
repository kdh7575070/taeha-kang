/*
 * selectionSort.h
 *
 *  Created on: 2020. 3. 25.
 *      Author: taeha
 */

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y) =(t))

void sort(int list[], int n){

	int i, j, min, temp;
	for(i=0; i<n-1; i++){
		min = i;
		for (j= i+1; j < n; j++)
			if(list[j]<list[min])
			min = j;
		SWAP(list[i], list[min], temp);
	}
}

#endif /* SELECTIONSORT_H_ */
