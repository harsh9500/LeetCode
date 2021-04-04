class MyCircularQueue {
public:
    int front, rear;
    int q[1000];
    int max_size;
    MyCircularQueue(int k) {
        max_size=k;
        // memset(q,sizeof(q),-1);
        for(int i=0;i<1000;i++)
            q[i]=-1;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        if(this->isFull())
            return false;
        if(front == -1 && rear == -1) // First element in the queue
        {
            front=0;
        }
        rear++;
        if(rear==max_size)
        {
            rear=0;
        }
        q[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty())
            return false;
        if(front==rear)
        {
            front=-2;
            rear=-1;
        }
        front++;
        if(front==max_size)
            front=0;
        return true;
    }
    
    int Front() {
        return front == -1 ? -1 : q[front];
    }
    
    int Rear() {
        return rear == -1 ? -1 : q[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(front == rear+1)
            return true;
        if(front == 0 && rear==max_size-1)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */