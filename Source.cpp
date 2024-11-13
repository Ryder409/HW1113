#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// �G���j�M�禡
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
    return -1; // �S�����
}

int main() {
    string type;
    int n, q;

    // Ū���C������
    while (cin >> type >> n >> q) {
        // Ū���w�ƧǪ����
        vector<string> data;
        if (type == "i") {
            // ��ƫ��A���
            vector<int> int_data(n);
            for (int i = 0; i < n; ++i) {
                cin >> int_data[i];
            }

            // �B�z�C�Ӭd��
            for (int i = 0; i < q; ++i) {
                int target;
                cin >> target;
                // ����G���j�M
                int result = binary_search(int_data, target);
                cout << result << endl;
            }
        }
        else if (type == "s") {
            // �r�ꫬ�A���
            vector<string> str_data(n);
            for (int i = 0; i < n; ++i) {
                cin >> str_data[i];
            }

            // �B�z�C�Ӭd��
            for (int i = 0; i < q; ++i) {
                string target;
                cin >> target;
                // ����G���j�M
                int result = binary_search(str_data, target);
                cout << result << endl;
            }
        }
    }

    return 0;
}
