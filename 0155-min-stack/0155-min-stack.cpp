class MinStack {
private:
    int min_below{ 0 };
    std::vector<std::pair<int,int>>vals;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if ( vals.empty() )
        {
            min_below = val;
        }
        else
        {
            min_below = std::min( min_below, val );
        }
        vals.push_back( { val, min_below } );
    }
    
    void pop() {
        vals.pop_back();
        if ( !vals.empty() )
            min_below = vals.back().second;
    }
    
    int top() {
        return vals.back().first;
    }
    
    int getMin() {
        return min_below;
 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */