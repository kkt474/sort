struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(nullptr) {}
};

// 1.初始化链表
ListNode* n0 = new ListNode(1);
ListNode* n1 = new ListNode(3);
ListNode* n2 = new ListNode(2);
ListNode* n3 = new ListNode(5);
ListNode* n4 = new ListNode(4);
// 构建节点之间的引用
n0->next = n1;
n1->next = n2;
n2->next = n3;
n3->next = n4;

// 2.插入节点  O(1)
// 在链表的节点n0之后插入节点p
void insert(ListNode* n0, ListNode* p){
    ListNode* n1 = n0->next;
    p->next = n1;
    n0->next = p;
}

// 3.删除节点
// 删除链表的节点n0之后的首个节点
void remove(ListNode* n0){
    if (n0->next == nullptr)
        return;
    ListNode* p = n0->next;
    LIstNode* n1 = p->next;
    n0->next = n1;
    // 释放内存
    delete p;
}

// 4.访问节点 O(n)
ListNode* access(ListNode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head = nullptr)
          return nullptr;
        head = head->next;
    }
    return head;
}

// 5.查找节点
int find(ListNode* head, int target){
    int index = 0;
    while(head != nullptr){
        if (head->val == target)
           return index;
        head = head->next;
        index++;
    }
    return -1;
}
