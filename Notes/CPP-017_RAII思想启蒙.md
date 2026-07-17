# CPP-017：RAII 思想启蒙

**日期：** 2026-07-17  
**位置：** 阶段二 — 深入理解内存

---

## 一、什么是 RAII？

**RAII = Resource Acquisition Is Initialization（资源获取即初始化）**

核心思想：**把资源的生命周期绑定到对象的生命周期上。**

- 构造函数 → 获取资源（`new`、`fopen`、`malloc`）
- 析构函数 → 释放资源（`delete`、`fclose`、`free`）
- 对象出作用域 → 自动销毁 → 自动释放资源

## 二、为什么需要 RAII？

对比动态数组手动管理和 RAII 方式：

```cpp
// 手动管理 —— 容易出错
int* data = new int[n];
// ... 使用 ...
delete[] data;           // 忘了就是内存泄漏

// RAII 方式 —— 自动释放
IntArray arr(n);         // 构造时 new
// ... 使用 ...
// 出作用域自动 delete ✅
```

## 三、RAII 的关键优势

无论正常退出还是异常提前返回，资源都会释放：

```cpp
void process() {
    FileHandler f("data.txt");  // 构造时 fopen
    if (/* 错误 */) {
        return;                 // ✅ f 销毁时自动 fclose
    }
    // ... 处理 ...
}                               // ✅ 正常退出也自动 fclose
```

**手动管理做不到这一点：**
```cpp
void process() {
    File* f = fopen("data.txt");
    if (/* 错误 */) {
        return;                 // ❌ 忘了 fclose！
    }
    fclose(f);
}
```

## 四、一句话总结

> **谁申请，谁释放；构造获取，析构归还。对象死，资源亡。**

## 五、后续关联

| 学到后面会看到 | 本质 |
|---------------|------|
| `std::vector` | 动态数组的 RAII 封装 |
| `std::string` | 字符串的 RAII 封装 |
| `std::unique_ptr` | 单个堆对象的 RAII 封装 |
| 智能指针 | 自动管理 new/delete |

RAII 是 **C++ 最核心的设计哲学**，没有之一。
