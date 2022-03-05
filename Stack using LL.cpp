class stack{
    // stack using ll
    class Node{
        public:
            Node* next;
            
            Node(_val){
              int val = _val;
              next = NULL;
            }
    };
    
    Node* head = NULL;
    void push(int _val){
        Node* newnode = new Node(_val);
        newnode->next = head;
        head = newnode;
    }
    
    void pop(){
        if(head == NULL) return false;
 
        Node* curr = head;
        head = curr->next;
        curr->next = NULL;
    return true;
    }
};

