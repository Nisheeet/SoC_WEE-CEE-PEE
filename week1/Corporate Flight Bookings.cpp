class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> d(n+1);
        for(vector<int>& book: bookings){
            d[book[0]-1] += book[2];
            d[book[1]] -= book[2];
        }
        for(int i=1; i<n; i++){
            d[i] += d[i-1];
        }
        d.resize(n);
        return d;
    }
};