#include <iostream>
using namespace std;
int main() {
    int* data = new int[4];   // 初始容量 4
    int capacity = 4;         // 当前容量
    int size = 0;             // 已存元素个数
    cout << "请输入数字（-1 结束）：" << endl;

    int n;
    while (cin >> n && n != -1) {
        if (size == capacity) {
            capacity=capacity*2;
            // TODO: 扩容——新的容量 = 容量 * 2
            int*p=data;
            // 1. new 一块新内存
            int *p1=p;
            data=new int[capacity];
            for(int i=0;i<size;i++){
               
                data[i]=*p1;
                p1++;
            }
            // 2. 把旧数据拷贝过去
            // 3. delete[] 旧内存
            delete[] p;
        }
        data[size] = n;
        size++;
    }
    
    // 输出所有元素
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    delete[] data;  // 记得释放
}
