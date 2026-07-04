class MinStack {
private:
    stack<long> st;
    long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(0);
            min = val;
        } else {
            st.push((long)val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (st.empty()) return; 

        long topValue = st.top();
        st.pop();
        if (topValue < 0) {
            min = min - topValue;
        }
    }
    
    int top() {
        long topValue = st.top();
        return topValue > 0 ? (int)(topValue + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};