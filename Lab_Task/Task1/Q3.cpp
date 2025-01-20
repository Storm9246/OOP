// Q3: Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.You can return the answer in any order.
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

#include<iostream>

using namespace std;

int main()
{
    int num, target;
    bool flag = false;
    cout << "Enter the size of Array: " ;
    cin >> num;

    int* array = new int[num];
    if(!array)
    {
        cout << "memory error";
        return 1;
    }

    for(int i = 0; i < num; i++)
    {
        cout << "enter element " << i+1 << ": ";
        cin >> array[i];
    }

    cout << "Enter target: ";
    cin >> target;
    
    int i, j;

    for(i = 0; i < num; i++)
    {
        for(j = i + 1; j < num; j++)
        {
            if((array[i]+array[j]) == target)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            break;
        }
    }

    cout << "[" << i << "," << j << "]"; 



}