/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        bool list1_is_done = false;
        bool list2_is_done = false;

        if (list1 == nullptr && list2 == nullptr)
        {
            return list1;
        }
        else if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode* headNode = list1;
        if (list1->val <= list2->val)
        {
            if (list1->next != nullptr)
            {
                list1 = list1->next;
            }
            else
            {
                list1_is_done = true;
            }
        }
        else
        {
            headNode = list2;

            if (list2->next != nullptr)
            {
                list2 = list2->next;
            }
            else
            {
                list2_is_done = true;
            }
        }

        ListNode* currNode = headNode;
        while(!list1_is_done && !list2_is_done)
        {
            if (list1->val <= list2->val)
            {
                currNode->next = list1;
                currNode = currNode->next;
                if (list1->next == nullptr)
                {
                    list1_is_done = true;
                    break;
                }
                else
                {
                    list1 = list1->next;
                }
            }
            else
            {
                currNode->next = list2;
                currNode = currNode->next;
                if (list2->next == nullptr)
                {
                    list2_is_done = true;
                    break;
                }
                else
                {
                    list2 = list2->next;
                }
            }
        }

        if (list1_is_done)
        {
            currNode->next = list2;
            return headNode;
        }
        else
        {
            currNode->next = list1;
            return headNode;
        }
    }
};