#include<iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    MyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    int get(int index) {
        if (index < 0 || index >= length) return -1;

        Node* cur;
        if (index <= length / 2) {
            cur = head;
            for (int i = 0; i < index; ++i)
                cur = cur->next;
        } else {
            cur = tail;
            for (int i = length - 1; i > index; --i)
                cur = cur->prev;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;

        if (index == 0) {
            addAtHead(val);
        } else if (index == length) {
            addAtTail(val);
        } else {
            Node* cur = head;
            for (int i = 0; i < index; ++i)
                cur = cur->next;

            Node* newNode = new Node(val);
            newNode->prev = cur->prev;
            newNode->next = cur;
            cur->prev->next = newNode;
            cur->prev = newNode;
            length++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;

        Node* cur = head;
        for (int i = 0; i < index; ++i)
            cur = cur->next;

        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;

        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;

        delete cur;
        length--;
    }

    ~MyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

///////////////////////////
class Solution {
public:
    void print(ListNode* head)
    {
        ListNode* cur = head;
        while (cur)
        {
            std::cout << cur->val;
            cur = cur->next;
        }
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head, * fast = head->next;
        //reach mid of list
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the second half
        ListNode* NewHead = slow->next;
        ListNode* left = nullptr, * right = NewHead;
        while (right)
        {
            ListNode* temp = right->next;
            right->next = left;
            left = right;
            right = temp;
            
        }
       // disconnect the list
        slow->next = nullptr;

        //merge two lists

        ListNode* first = head, * second = left;
        while (first && second)
        {   
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
bool isPalindrome(ListNode* head) {
   vector<int>v;
   ListNode*cur=head;
    while(cur)
    {
        v.push_back(cur->val);
        cur=cur->next;
    }
    int left=0,right=v.size()-1;
        while(left<right)
            {
                if(v[left]!=v[right])
                    return false;
                    left++;
                    right--;
            }
            return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }

    }
};
int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s1;
    s1.print(node1);
    s1.reorderList(node1);
    s1.print(node1);
}
