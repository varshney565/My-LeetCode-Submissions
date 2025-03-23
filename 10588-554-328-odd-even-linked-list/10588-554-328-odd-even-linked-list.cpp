class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead =nullptr, *evenTail = nullptr, *oddHead = nullptr, *oddTail = nullptr;
        ListNode* current = head;
        int index = 1;
        while(current != nullptr){
            if(index%2 == 1) {
              //odd list
              if(oddHead == nullptr) {    
                oddHead = current;
                oddTail = current;
              } else {
                oddTail->next = current;
                oddTail = current;
              }
            }else {
                //even list
                if(evenHead == nullptr) {
                    evenHead = current;
                    evenTail = current;
                }else {
                    evenTail->next = current;
                    evenTail = current;
                }
            }
            current = current->next;
            index++;
        }
        if(oddTail != nullptr) oddTail->next = evenHead;
        if(evenTail != nullptr) evenTail->next = nullptr;
        return oddHead;
    }
};