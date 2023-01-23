class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1) return n;
        ListNode *head=NULL,*tail=NULL;
        for(int i=1;i<=n;i++)
        {
            ListNode* temp=new ListNode(i);
            if(head==NULL)
                head=tail=temp;
            else
            {
                tail->next=temp;
                tail=temp;
            }
        }
         tail->next=head;
        tail=head->next;
        return helper(head,tail,k);        
    }
private :
    int helper(ListNode* head,ListNode *tail,int k)
    {
        if(head!=NULL && head->next==head)
            return head->val;
        for(int i=0;i<k-1;i++)
        {
          tail=tail->next;
        }
     head->next=tail->next;
     tail->next=NULL;
     tail=head;
        return helper(head,tail,k);
    }
};
