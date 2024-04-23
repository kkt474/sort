#include <iostream>

// 选择排序
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    // 
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++){
            if (nums[j] < nums[k]) 
               k = j;
        }
        // 将该元素与未排序区间的首个元素交换
        swap(nums[i], nums[k]);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

// 插入排序
void insertionSort(vector<int>& nums) {
    // 初始状态下，数组的第一个元素已经完成排序
    for (int i = 1; i < nums.size(); i++) {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = base;
    }
}