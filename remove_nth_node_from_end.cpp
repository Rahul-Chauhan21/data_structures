ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* dummy_head = new ListNode(-1);
    dummy_head->next=A;
    ListNode* fast=dummy_head;
    ListNode* slow=dummy_head;
    B++;
    while(B--&&fast)fast=fast->next;
    while(fast)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy_head->next;
}
