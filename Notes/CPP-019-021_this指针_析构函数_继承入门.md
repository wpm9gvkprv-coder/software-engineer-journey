# CPP-019~021：this 指针、析构函数、继承入门

**日期：** 2026-07-18  
**位置：** 阶段三 — 面向对象编程

---

## 一、this 指针

### 是什么

每个成员函数内部都有一个隐藏指针 `this`，指向**调用该函数的那个对象本身**。

```cpp
class Student {
    string name;
public:
    void setName(string name) {
        this->name = name;  // this->name 是成员变量，name 是参数
    }
};
```

编译器实际把成员函数做了转换：

```cpp
stu.setName("小明");
// 等价于：
Student::setName(&stu, "小明");
// this 就是 &stu
```

### 验证

```cpp
stu1.showThis();  // this == &stu1
stu2.showThis();  // this == &stu2
```

### 什么时候必须用

**参数名和成员变量名相同时**，用 `this->成员` 来区分：

```cpp
void setName(string name) {
    this->name = name;   // ✅ 明确说：把参数 name 赋给当前对象的 name
    // name = name;      // ❌ 两边都是参数，不会赋值给成员变量
}
```

---

## 二、析构函数（Destructor）

### 规则

| 规则 | 说明 |
|------|------|
| 函数名 | `~` + 类名（如 `~Student()`）|
| 参数 | **无参数**（不能重载，一个类只有一个）|
| 返回类型 | 无 |
| 调用时机 | 对象销毁时**自动调用** |
| 用途 | **释放资源**（`delete`、`fclose` 等） |

### 构造与析构顺序

```cpp
Demo a;  // ① 构造 a
Demo b;  // ② 构造 b
}         // ③ 析构 b（后进先出）
          // ④ 析构 a
```

**顺序规则：** 先构造的后析构（LIFO，后进先出）。

### RAII 实践

```cpp
class IntArray {
    int* data;
public:
    IntArray(int n) {
        data = new int[n];   // 构造时分配
    }
    ~IntArray() {
        delete[] data;       // 析构时自动释放
    }
};
// 用的时候完全不用操心 delete
```

---

## 三、protected 访问级别

| 访问级别 | 类内部 | 派生类（子类）| 外部 |
|---------|:-----:|:----------:|:----:|
| `private` | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ |

```cpp
class Person {
protected:
    string name;  // 子类内部可以访问，外部不行
};

class Student : public Person {
    void test() {
        name = "小明";  // ✅ 派生类成员函数内部可以访问
    }
};

int main() {
    Student stu;
    // stu.name = "小明";  // ❌ 外部不能访问 protected
}
```

---

## 四、继承（Inheritance）

### 解决的问题

提取共性到基类，消除重复代码：

```cpp
class Person {          // 基类——共同的部分
protected:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
};

class Student : public Person {  // 派生类——继承 + 扩展
    int score;
public:
    void setScore(int s) { score = s; }
};

class Teacher : public Person {  // 另一个派生类
    string subject;
public:
    void setSubject(string s) { subject = s; }
};
```

### 继承的好处

1. **消除重复代码**——公共属性和方法在基类写一次
2. **扩展能力**——子类可以加自己的东西
3. **表达"is-a"关系**——Student **是一个** Person

### 构造顺序：初始化列表

子类构造时，应通过**初始化列表**调用父类构造：

```cpp
class Student : public Person {
    int score;
public:
    Student(string n, int a, int s) 
        : Person(n, a)   // 先初始化父类部分
    {
        score = s;        // 再初始化自己的部分
    }
};
```

**执行顺序：**
```
① 调用 Person 的构造函数（初始化 name, age）
② 执行 Student 自己的构造函数体（初始化 score）
```

---

## 五、综合练习：动物继承体系

```cpp
class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}
    void sleep() { cout << "zzz..." << endl; }
};

class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}
    void bark() { cout << "汪汪！" << endl; }
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}
    void meow() { cout << "喵~" << endl; }
};
```

---

## 六、本章小结

| 概念 | 一句话 |
|------|--------|
| `this` | 成员函数里指向当前对象的指针 |
| 析构函数 | 对象销毁时自动调用，用于释放资源 |
| `protected` | 子类内部可见，外部不可见 |
| 继承 | 子类继承父类的数据和接口，可扩展 |
| 初始化列表 | `: 父类(参数)` 让父类初始化自己的部分 |
