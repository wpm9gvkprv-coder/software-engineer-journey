#include <iostream>
int main() {
    // 栈：自动管理
    for (int i = 0; i < 5; i++) {
        int stackVar = i;        // 每次循环进来创建，出去销毁
        std::cout << "栈: " << stackVar << std::endl;
    }
    // 这里 stackVar 已经没了
    
    // 堆：手动管理
    int* p = new int(42);        // 在堆上分配一个 int，值为 42
    std::cout << "堆: " << *p << std::endl;
    delete p;                    // 手动释放——还仓库
    // delete 之后 *p 就是非法访问了
    
    return 0;
}
