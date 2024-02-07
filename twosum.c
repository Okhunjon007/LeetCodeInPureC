/*Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Constraints:
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *  -10^9 <= target <= 10^9
 *  Only one valid answer exists.*/


/*Approach: store the index of the array elements as value and the value of the index as key in a hashtable*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SIZE 31

typedef struct Node{
	int32_t key;
	int32_t val;
	struct Node *next;
}Node;

Node *hashtable[SIZE];

void initialize(void)
{
	for(int8_t i=0;i<SIZE;i++)
	{
		hashtable[i]=NULL;
	}
}

int8_t hashcode(int32_t key)
{
	int64_t newkey=2*pow(10,9)+key;
	return newkey%SIZE;
}

void insert(int32_t key, int16_t val)
{
	Node *tmp=(Node *)malloc(sizeof(Node));//verify memory allocation
	tmp->key=key;
	tmp->val=val;
	tmp->next=NULL;

	int8_t index=hashcode(key);
	if(hashtable[index]==NULL)
	{
		hashtable[index]=tmp;
	}
	else{
		Node *cur=hashtable[index];
		while(cur->next!=NULL)
			cur=cur->next;
		cur->next=tmp;
	}
}

int8_t search(int32_t key, int16_t *val)
{
	int8_t index=hashcode(key);
	Node *cur=hashtable[index];
	while(cur!=NULL)
	{
		if(cur->key==key)
		{
			*val=cur->val;
			return 1;
		}
		else
			cur=cur->next;
	}
	return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize=2;
	int16_t index;
	int *res=(int *)malloc(sizeof(int)*2);
	initialize();
	for(int16_t i=0;i<numsSize;i++)
	{
		if(search(target-nums[i], &index))
		{
			res[0]=index;
			res[1]=i;
			return res;
		}
		else{
			insert(nums[i], i);
		}
	}
	return -1;
}
