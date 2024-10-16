//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;
    int size = 0;

  public:
    void push(int x) {
        StackNode *temp = new StackNode(x);
        temp -> next = top;
        top = temp;
        size = size + 1;
    }
    
    int pop() {
        if(top == NULL) return -1;
        StackNode *temp = top;
        int poppedValue = top -> data;
        top = top -> next;
        delete temp;
        size = size - 1;
        return poppedValue;
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
}

// } Driver Code Ends