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
    vector<int> safe_list; // ��ȫ����

    int num; // ������Դ�ı��
    int a, b, c; // �������Դ����
    cout << "������������Դ�ı�ţ�";
    cin >> num;
    cout << "������������Դa�ĸ�����";
    cin >> a;
    cout << "������������Դb�ĸ�����";
    cin >> b;
    cout << "������������Դc�ĸ�����";
    cin >> c;
    if (a > available[0] || b > available[1] || c > available[2]) {
        cout << "����������Դ������ʧ��" << endl;
        return 0;
    }
    if (a + allocation[num][0] > max[num][0] || b + allocation[num][1] > max[num][2] || c + allocation[num][2] > max[num][2]) {
        cout << "����������Դ������ʧ��" << endl;
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
    bool flag = 1; // ��־������ѭ����û�б����밲ȫ���е�
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
    if (safe_list.size() < need.size()) { // ��ȫ������Ԫ�ظ���С�����н�����
        cout << "�ް�ȫ���У�������Ҫ��" << endl;
        return 0;
    }
    cout << "���Է��䣬��ȫ�������£�" << endl;
    for (int i = 0; i < max.size(); i++)  // ��ӡ��ȫ����
        cout << safe_list[i] << " ";
    return 0;
}