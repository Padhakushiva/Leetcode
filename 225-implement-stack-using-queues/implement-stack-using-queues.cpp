class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);

        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};