class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        
        int pos = 2;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        while (next != NULL) {
            
            // Check critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first == -1) {
                    // First critical point
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - last);
                }
                
                last = pos;
            }
            
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }
        
        // Fewer than 2 critical points
        if (first == last)
            return ans;
        
        ans[0] = minDist;
        ans[1] = last - first;
        
        return ans;
    }
};