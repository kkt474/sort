// 1.初始化列表
// 无初始值
vector<int> nums1;
// 有初始值
vector<int> nums = {1,3,2,5,4};

// 2.访问元素  O(1)
int num = nums[1];
// 更新元素
nums[1] = 0;

// 3.插入与删除元素
// 清空列表
nums.clear()
// 尾部添加元素
nums.push_back(1);
nums.push_back(3);
nums.push_back(2);
nums.push_back(5);
nums.push_back(4);
// 在中间插入元素
nums.insert(nums.begin()+3,6); // 在索引3处插入数字6
// 删除元素
nums.erase(nums.begin()+3);  // 删除索引3处的元素

// 4.遍历列表
// 通过索引遍历列表
int count = 0;
for (int i = 0; i < nums.size(); i++){
    count += nums[i];
}
// 直接遍历列表元素
count = 0;
for (int num : nums) {
    count += num;
}

// 5.拼接列表
vector<int> nums1 = {6,8,7,10,9};
// 将列表nums1拼接到nums之后
nums.insert(nums.end(), nums1.begin(), nums1.end()); 

// 6.排序列表
sort(nums.begin(), nums.end());

// 7.列表实现
class MyList {
private:
     int* arr;
     int arrCapacity = 10; // 列表容量
     int arrSize = 0; // 列表长度
     int extendRatio = 2;
public:
    MyList(){
        arr = new int[arrCapacity];
    }

    ~MyList() {
        delete[] arr;
    }

    // 获取列表长度
    int size() {
        return arrSize;
    }

    // 获取列表容量
    int capacity() {
        return arrCapacity;
    }

    // 访问元素
    int get(int index) {
        if (index < 0 || index >= size()) {
            throw_out_of_range("索引越界");
        }
        return arr[index];
    }

    // 更新元素
    void set(int index, int num) {
        if (index < 0 || index >= size()) {
            throw_out_of_range("索引越界");
        } 
            arr[index] = num;
    }
    
    // 在尾部添加元素
    void add(int num) {
         // 元素数量超出容量时，触发扩容机制
         if (size() == capacity())
             extendCapacity();
        arr[size()] = num;
        // 更新元素数量
        arrSize++;
    }

    // 在中间插入元素
    void insert(int index, int num){
       if (index < 0 || index >= size())
            throw_out_of_range("索引越界");
        // 元素数量超出容量时，触发扩容机制
        if (size() == capacity())
             extendCapacity();
        for (int i = size() - 1; i >= index; i--){
            arr[i+1] = arr[i];
        }
        arr[index] = num;
        arrSize++;
    }

    // 删除元素
    int remove(int index) {
        if (index < 0 || index >= size())
            throw_out_of_range("索引越界");
        int num = arr[index];
    // 将索引index之后的元素都向前移动一位
    for (int j = index; j < size() - 1; j++) {
        arr[j] = arr[j+1];
    }
    // 更新元素数量
    arrSize--;
    // 返回被删除的元素
    return num;
    }

    // 列表扩容
    void extendCapacity() {
      int newCapacity = capacity() * extendRatio;
      int* tmp = arr;
      arr = new int[newCapacity];
      for (int i = 0; i < size(); i++){
        arr[i] = tmp[i];
      }
      delete[] tmp;
      arrCapacity = newCapacity;
    }

    // 将列表转换为vector用于打印
    vector<int> tovector() {
        vector<int> vec(size());
        for (int i = 0; i < size(); i++) {
            vec[i] = arr[i];
        }
        return vec;
    }


};
