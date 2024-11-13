#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 二分搜尋函式
template <typename T>
int binary_search(const vector<T>& arr, const T& target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // 沒有找到
}

int main() {
    string type;
    int n, q;

    // 讀取每筆測資
    while (cin >> type >> n >> q) {
        // 讀取已排序的資料
        vector<string> data;
        if (type == "i") {
            // 整數型態資料
            vector<int> int_data(n);
            for (int i = 0; i < n; ++i) {
                cin >> int_data[i];
            }

            // 處理每個查詢
            for (int i = 0; i < q; ++i) {
                int target;
                cin >> target;
                // 執行二分搜尋
                int result = binary_search(int_data, target);
                cout << result << endl;
            }
        }
        else if (type == "s") {
            // 字串型態資料
            vector<string> str_data(n);
            for (int i = 0; i < n; ++i) {
                cin >> str_data[i];
            }

            // 處理每個查詢
            for (int i = 0; i < q; ++i) {
                string target;
                cin >> target;
                // 執行二分搜尋
                int result = binary_search(str_data, target);
                cout << result << endl;
            }
        }
    }

    return 0;
}
