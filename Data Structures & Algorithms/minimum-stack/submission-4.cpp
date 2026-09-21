class MinStack {
    
    int* data = nullptr;
    int min = 0;
    size_t tracker = 0;
    multiset<int>order;
public:
    MinStack()
    {
        data = new int[300001];
    }
    
    void push(int val) 
    {
        data[tracker++] = val;
        order.insert(val);
    }
    
    
       void pop() {
       order.erase(order.find(data[tracker - 1]));
       tracker--;
        }  
    
    
    int top() {
        return data[tracker - 1];
    }
    
    int getMin() 
    {
        if(order.empty())
        {
            return 0;
        }
        else 
            return *order.begin();
    }
};
