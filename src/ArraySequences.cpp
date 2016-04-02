/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<malloc.h>

int * find_sequences(int *arr, int len)
{
	if (arr == NULL || len < 0)
		return NULL;
	int *result;
	int i = 0, x = 0, y = 0, d, p;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	result = (int *)malloc(6 * sizeof(int));
	for (i = 0; i < len; i++)
	{
		x = arr[i];
		y = arr[i + 1];
		d = y - x;
		p = i + 2;
		while (arr[p] == (y + d) && (p) < len)/*searching for first Arithematic progression*/
		{
			if (!flag1)
			{
				result[0] = i;/*start index of AP1*/
				flag1 = 1;
			}
			if (flag1)
			{
				result[1] = p;/*end index of AP1*/
			}
			y = y + d;
			p++;
        }
        i = p;

		x = arr[i];
		y = arr[i + 1];
		d = y - x;
		p = i + 2;
		while (arr[p] == (y + d) && (p) < len)/*searching for second Arithematic progression*/

		{

			if (!flag2)
			{
				result[2] = i;
				flag2 = 1;
			}
			if (flag2)
			{
				result[3] = p;/*start index of AP2*/
			}
			y = y + d;

			if (p == (len - 1))
			{

				result[3] = p;/*end index of AP2*/


			}

			p++;
		}

		i = p;

	}
	for (i = 0; i<len; i++)
	{
		x = arr[i];
		y = arr[i + 1];
		d = y / x;
		p = i + 2;


		while (arr[p] == (y*d) && (p) < len)/*searching for the geometric progression*/
		{

			if (!flag3)
			{
				result[4] = i;/*start index of GP*/
				flag3 = 1;
			}
			if (flag3)
			{
				result[5] = p;/*end index of GP*/
			}
			y = y*d;
			p++;


		}


	}


	return result;
}