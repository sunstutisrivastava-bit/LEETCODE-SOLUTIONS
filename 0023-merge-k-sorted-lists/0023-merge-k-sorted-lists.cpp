class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,
                       vector<ListNode*>,
                       compare> pq;

        // Put first node of every list into heap
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* curr = pq.top();
            pq.pop();

            // Add it to answer
            tail->next = curr;
            tail = curr;

            // Add next node from same list
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};