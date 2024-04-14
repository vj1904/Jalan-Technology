#include <iostream>
#include <vector>

using namespace std;

vector<int> alternateOrder(vector<int>& nums) {
    vector<int> res;

    // Separate positive and negative numbers
    vector<int> pos, neg;
    for (int num : nums) {
        if (num > 0)
            pos.push_back(num);
        else
            neg.push_back(num);
    }

    auto posIter = pos.begin();
    auto negIter = neg.begin();
    while (posIter != pos.end() || negIter != neg.end()) {
        if (posIter != pos.end()) {
            res.push_back(*posIter);
            ++posIter;
        }
        if (negIter != neg.end()) {
            res.push_back(*negIter);
            ++negIter;
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = alternateOrder(nums);

    cout << "Alternate Arrangement: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
