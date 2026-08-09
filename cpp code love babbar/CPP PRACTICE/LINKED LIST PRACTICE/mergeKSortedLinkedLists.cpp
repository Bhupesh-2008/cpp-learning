#include <iostream>
#include <vector>
#include <queue> // Typically needed for the optimal Min-Heap approach

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare{
    public: 
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val>b->val;
        }
};

// Function to merge K sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;

    int k= lists.size();
    if(k==0) return NULL;
    for(int i=0; i<k; i++){
        if(lists[i]!=NULL) minHeap.push(lists[i]);
    }

    ListNode* head= NULL;
    ListNode* tail= NULL;

    while(minHeap.size()>0){
        ListNode* top= minHeap.top();
        minHeap.pop();
        if(head==NULL){
            //answer ll is empty
            head= top;
            tail= top;
            if(head->next) minHeap.push(tail->next);
        }else{
            // insert at ll
            tail->next= top;
            tail= top;
            if(tail->next) minHeap.push(tail->next); 
        }
    }
    
    return head; // Return the head of the merged linked list
}

// Helper function to build a linked list from standard input
ListNode* buildList(int n) {
    if (n == 0) return nullptr;
    
    int val;
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    // Read the number of linked lists
    cin >> k;

    vector<ListNode*> lists(k);
    for (int i = 0; i < k; i++) {
        int n;
        // Read the number of elements in the current linked list
        cin >> n;
        
        // Build the linked list and store its head
        lists[i] = buildList(n);
    }

    // Call your function
    ListNode* mergedHead = mergeKLists(lists);
    
    // Print the final merged linked list
    printList(mergedHead);

    return 0;
}