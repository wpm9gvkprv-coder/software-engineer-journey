#include <iostream>
int main() {
    int n;
    std::cout << "你想输入几个分数？";
    std::cin >> n;
    
    int* scores = new int[n];   // 运行期决定大小！
    for (int i = 0; i < n; i++) {
        std::cout << "分数 " << i+1 << ": ";
        std::cin >> scores[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += scores[i];
    }
    std::cout << "平均分: " << (double)sum / n << std::endl;
    
    delete[] scores;   // 用完释放
    return 0;
}

