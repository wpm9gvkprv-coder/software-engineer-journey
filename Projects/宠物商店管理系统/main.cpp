#include<iostream>
#include<string>
using namespace std;
class Pet{
    protected:
    string name;
    int age;
    double price;
    public:
   
    static int count;
    Pet(string n,int m,double p){
        name=n;
        age=m;
        price=p;
        count++;
    }
    virtual void speak()=0;
    virtual ~Pet(){
        count--;
    }
        
    friend ostream& operator<<(ostream& os,const Pet& pet);
     bool operator>(const Pet& other) const {
        return price>other.price;
    }
};
int  Pet::count=0;
ostream& operator<<(ostream& os,const Pet& pet){
    os<<pet.name<<" "<<pet.age<<" "<<pet.price<<" "<<endl;
    return os;
}
class Dog:public Pet{
    public:
    Dog(string n,int m,double p)
    :Pet(n,m,p){}
    void speak(){
        cout<<"汪汪！"<<endl;
    }
    void watchDoor(){
        cout<<"看门中..."<<endl;
    }
};
class Cat:public Pet{
    public:
    Cat(string n,int m,double p)
    :Pet(n,m,p){}
    void speak(){
        cout<<"喵"<<endl;
    }
    void catchMouse(){
        cout<<"抓老鼠..."<<endl;
    }
};
int main(){
    Dog tom("tom",3,40);
    Dog mike("mike",4,30);
    Cat jery("jery",2,15);
    Cat sis("sis",7,10);
    cout<<"宠物信息"<<endl<<tom<<mike<<jery<<sis<<endl;
    Pet* pets[]={&tom,&mike,&jery,&sis};
   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 - i; j++) {
        if (*pets[j] > *pets[j + 1]) {   // 用你写的 operator>
            // 交换指针
            Pet* temp = pets[j];
            pets[j] = pets[j + 1];
            pets[j + 1] = temp;
        }
    }
}

// 输出排序结果
cout<<"价格从小到大排序"<<endl;
for (int i = 0; i < 4; i++) {
    
    cout << *pets[i];
}
for(int i=0;i<4;i++){
    pets[i]->speak();
}
cout<<"宠物总数:"<<Pet::count<<endl;
}
