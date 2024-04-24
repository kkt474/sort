// 初始化队列
queue<int> queue;
// 元素入队
queue.push(1);
queue.push(3);
queue.push(2);
queue.push(5);
queue.push(4);
// 访问队首元素
int front = queue.front();
//元素出队
queue.pop();
// 获取队列的长度
int size = queue.size();
//  判断队列是否为空
bool empty = queue.empty();

// 基于链表的实现
class LinkedListQueue {
private:
       ListNode* front, *rear;
       int queSize;

public:
      LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
      }

      ~LinkedListQueue() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(front);
      }

      // 获取队列的长度
      int size() {
        return queSize;
      }

      //  判断队列是否为空
      bool isEmpty() {
        return queSize == 0;
      }

      // 入队
      void push(int num)  {
        // 在尾节点后添加num
        ListNode* node = new ListNode(num);
        // 如果队列为空，则令头、尾节点都指向该节点
        if (front == nullptr) {
            front = node;
            rear = node;
        } else {
            // 如果队列不为空，则将该节点添加至尾节点
            rear->next = node;
            rear = node;
        }
        queSize++;
      }

      // 出队
      int pop() {
        int num =peek();
        // 删除头节点
        ListNode* tmp = front;
        front = front->next;
        // 释放内存
        delete tmp;
        queSize--;
        return num;
      }

      // 访问队首元素
      int peek() {
        if (size() == 0) {
            throw_out_of_range("队列为空");
        }
        return front->val;
      }

      // 将链表转化为Vector并返回
      vector<int> toVecotr(){
        ListNode* node = front;
        vector<inr> res(szie());
        for (int i = 0; i < res.size(); i++) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
      }    
};

//  基于环形数组实现的队列
class ArrayQueue {
private:
       int* nums;  // 用于存储队列元素的数组
       int front;
       int queSize; // 队列长度
       int queCapacity;  // 队列容量

public:
       ArrayQueue(int capacity) {
        // 初始化数组
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
       } 

       ~ArrayQueue() {
        delete[] nums;
       }

       // 获取队列容量
       int capacity() {
        return queCapacity;
       }

       // 获取队列的长度
       int size() {
        return queSize;
       }

       // 判断队列是否为空
       bool isEmpty() {
        return size() == 0;
       }

       // 入队
       void push(int num) {
        if (queSize == queCapacity) {
            cout << "队列已满" << endl;
            return;
        }
        // 计算尾指针，指向队尾元素索引+1
        // 通过取余操作实现rear越过数组尾部返回到头部
        int rear = (front + queSize) % queCapacity;
        // 将num添加至队尾
        nums[rear] = num;
        queSize++;        
       }

       // 出队
       int pop() {
        int num = peek();
        // 队首指针向后移动一位，若越过尾部，则返回到数组头部
        front = (front + 1) % queCapacity;
        queSize--;
        return num;
       }

       // 访问队首元素
       int peek() {
        if (isEmpty()) {
            throw_out_of_range("队列为空");
        }
        return nums[front];
       }

       // 将数组转化为Vecotr并返回
       vector<int> toVector() {
        // 仅转换有效长度范围内的列表元素
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++){
            arr[i] = nums[j%queCapacity];
        }
        return arr;
       }
};