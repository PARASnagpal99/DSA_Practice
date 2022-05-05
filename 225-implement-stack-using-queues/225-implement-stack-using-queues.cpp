class MyStack {
private : 
    queue<int>q1 ;
  //  queue<int>q2 ;
public:
    MyStack() {
        // queue<int>q1 ;
        // queue<int>q2 ;
    }
    
    void push(int x) {
        q1.push(x);
        for(int i=0 ; i<q1.size()-1 ; ++i){
            int x = q1.front() ;
            q1.pop();
            q1.push(x);
        }
    }
    
    int pop() {
        // int x = q1.size() ;
        // for(int i=0 ; i<x-1 ; ++i){
        //     int val = q1.front() ;
        //     q1.pop();
        //     q2.push(val);
        // }
        // int ans = q1.front() ;
        // q1.pop() ;
        // q1 = q2 ;
        // while(!q2.empty()){
        //     q2.pop() ;
        // }
        // return ans ;
        int x = q1.front() ;
        q1.pop() ;
        return x ;
    }
    
    int top() {
        // int x = q1.size() ;
        // for(int i=0 ; i<x-1 ; ++i){
        //     int val = q1.front() ;
        //     q1.pop();
        //     q2.push(val);
        // }
        // int ans = q1.front() ;
        // q1 = q2 ;
        // q1.push(ans) ;
        // while(!q2.empty()){
        //     q2.pop() ;
        // }
        // return ans ;
        int x = q1.front() ;
        return x ;
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */