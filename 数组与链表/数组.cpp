// 数组
// 1.初始化数组
// 存储在栈上
int arr[5];
int nums[5] = {1,3,2,5,4};
// 存储在堆上
int* arr1 = new int[5];
int* nums1 = new int[5]{1,3,2,5,4};

// 2.访问元素
// 随机访问元素
int randomAccess(int* nums, int size) {
    int randomIndex = rand() % 10;
    int randomNum = nums[randomIndex];
    return randomNum;
}

// 3.插入元素
void insert(int *nums, int size, int num, int index){
    for(int i = size - 1; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = num;
}

// 4.删除元素
void remove(int* num, int size; int index) {
    for (int i = index; i < size - 1; i++){
        nums[i] = nums[i+1];
    }
}

// 5.遍历数组
void traverse(int* nums, int size) {
    int count = 0;
    for (int i = 0; i < size; i++){
        count += nums[i];
    }
}

// 6.查找元素
int find(int* nums, int size, int target){
    for (int i = 0; i < size; i++) {
        if (nums[i] == target)
           return i;
    }
    return -1;
}

// 7.扩容数组
int* extend(int* nums, int size, int enlarge){
    // 初始化一个扩展长度后数组
    int* res = new int[size + enlarge];
    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i++) {
        res[i] = nums[i];
    }
    // 释放内存
    delete[] nums;
    // 返回扩展后的数组
    return res;
}
