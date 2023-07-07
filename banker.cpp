#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<vector<int>> max = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
    vector<vector<int>> allocation = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
    vector<vector<int>> need = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };
    vector<int> available = { 3,3,2 };

    vector<int> safe_bool_list = { 0,0,0,0,0 };
    vector<int> safe_list; // 安全序列

    int num; // 请求资源的编号
    int a, b, c; // 请求的资源个数
    cout << "请输入请求资源的编号：";
    cin >> num;
    cout << "请输入请求资源a的个数：";
    cin >> a;
    cout << "请输入请求资源b的个数：";
    cin >> b;
    cout << "请输入请求资源c的个数：";
    cin >> c;
    if (a > available[0] || b > available[1] || c > available[2]) {
        cout << "超出已有资源，请求失败" << endl;
        return 0;
    }
    if (a + allocation[num][0] > max[num][0] || b + allocation[num][1] > max[num][2] || c + allocation[num][2] > max[num][2]) {
        cout << "超出已有资源，请求失败" << endl;
        return 0;
    }
    need[num][0] -= a;
    need[num][1] -= b;
    need[num][2] -= c;
    allocation[num][0] += a;
    allocation[num][1] += b;
    allocation[num][2] += c;
    available[0] -= a;
    available[1] -= b;
    available[2] -= c;
    bool flag = 1; // 标志：本次循环有没有被加入安全序列的
    while (flag) {
        flag = 0;
        for (int i = 0; i < need.size(); i++) {
            if (available[0] >= need[i][0] &&
                available[1] >= need[i][1] &&
                available[2] >= need[i][2] &&
                safe_bool_list[i] == 0) {
                available[0] += allocation[i][0];
                available[1] += allocation[i][1];
                available[2] += allocation[i][2];
                safe_list.push_back(i);
                safe_bool_list[i] = 1;
                flag = 1;
            }
        }
    }
    if (safe_list.size() < need.size()) { // 安全序列中元素个数小于所有进程数
        cout << "无安全序列，不满足要求" << endl;
        return 0;
    }
    cout << "可以分配，安全序列如下：" << endl;
    for (int i = 0; i < max.size(); i++)  // 打印安全序列
        cout << safe_list[i] << " ";
    return 0;
}