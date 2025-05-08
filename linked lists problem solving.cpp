#include<iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


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
