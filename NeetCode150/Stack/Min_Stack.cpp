class MinStack {
public:
    typedef struct node
    {
        int value;
        int minUntilNow;
        node* next;
    }node;

    MinStack() : topN(nullptr){}
    
    void push(int val)
    {
        node* n = new node();
        n->value = n->minUntilNow = val;
        n->next = nullptr;

        if(topN != nullptr)
        {
            n->minUntilNow = min(n->value, topN->minUntilNow);
            n->next = topN;
        }
        
        topN = n;
    }
    
    void pop()
    {
        topN = topN->next;
    }
    
    int top()
    {
        return topN->value;
    }
    
    int getMin()
    {
        return topN->minUntilNow;
    }

private:
    node* topN;
};
