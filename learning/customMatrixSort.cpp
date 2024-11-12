Here, we domonstrate how to solve 2d matrix as per defined objective. i.e; sort by column or by row, here we sort by column.
Which results in sorted matrix.

For Input: 
1 4
10 15
7 10

Your Output: 
1 4
7 10
10 15

class cus {
    public:
        bool operator()(const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0];
        }
};


sort(arr.begin(), arr.end(), cus());