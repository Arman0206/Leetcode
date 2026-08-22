class SeatManager {
public:
//s contain all the seats that are unreserved at current instant
set<int> s;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        s.insert(i);

    }
    
    int reserve() {
        // find the lowest unreserved seat
        int x=(*(s.begin()));
        // remove it from unreserved seat set/list
        s.erase(x);
        return x;
    }
    
    void unreserve(int seatNumber) {
        // add this to unresrved list
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */