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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headNode;
        ListNode* currNode1 = l1;
        ListNode* currNode2 = l2;

        bool l1_is_done = false;
        bool l2_is_done = false;

        int cnt1 = 1;
        int cnt2 = 1;

        while(currNode1->next != nullptr)
        {
            currNode1 = currNode1->next;
            cnt1++;
        }
        while(currNode2->next != nullptr)
        {
            currNode2 = currNode2->next;
            cnt2++;
        }

        currNode1 = l1;
        currNode2 = l2;

        //printf("%d   %d\n", cnt1, cnt2);

        if (cnt1 >= cnt2)
        {
            headNode = l2;
        }
        else
        {
            headNode = l1;
        }

        int over;

        while(1)
        {
            over = (currNode1->val + currNode2->val)/10;

            if (cnt1 >= cnt2)
            {
                currNode2->val = (currNode1->val + currNode2->val)%10;
            }
            else
            {
                currNode1->val = (currNode1->val + currNode2->val)%10;
            }
            
            if (over >= 1 && currNode1->next != nullptr)
            {
                currNode1->next->val += 1;
            }
            else if (over >= 1 && currNode2->next != nullptr)
            {
                currNode2->next->val += 1;
            }

            if(currNode2->next == nullptr)
            {
                l2_is_done = true;
                break;
            }
            else if (currNode1->next == nullptr)
            {
                l1_is_done = true;
                break;
            }

            currNode1 = currNode1->next;
            currNode2 = currNode2->next;
        }

        if (l1_is_done)
        {
            currNode1->next = currNode2->next;

            if(over >= 1 && currNode1->next == nullptr)
            {
                ListNode* extra = new ListNode(1);
                currNode1->next = extra;
            }
            else if(over)
            {
                currNode1 = currNode1->next;
                while(currNode1->next != nullptr)
                {
                    if(currNode1->val / 10 >= 1)
                    {
                        currNode1->next->val += 1;
                    }
                    currNode1->val %= 10;
                    currNode1 = currNode1->next; 
                }
                
                if(currNode1->val / 10 >= 1)
                {
                    currNode1->val %= 10;
                    ListNode* extra = new ListNode(1);
                    currNode1->next = extra;
                }
                
            }
        }
        else if (l2_is_done)
        {
            currNode2->next = currNode1->next;

            if(over >= 1 && currNode2->next == nullptr)
            {
                ListNode* extra = new ListNode(1);
                currNode2->next = extra;
            }
            else if(over)
            {
                currNode2 = currNode2->next;
                while(currNode2->next != nullptr)
                {
                    if(currNode2->val / 10 >= 1)
                    {
                        currNode2->next->val += 1;
                    }
                    currNode2->val %= 10;
                    currNode2 = currNode2->next; 
                }
                
                if(currNode2->val / 10 >= 1)
                {
                    currNode2->val %= 10;
                    ListNode* extra = new ListNode(1);
                    currNode2->next = extra;
                }
                
            }
            
        }

        return headNode;
    }
};