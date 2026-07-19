#include<iostream>
using namespace std;
class Animal{
    protected:
    string name;
    int age;
    public:
    Animal(string n,int a){
        name=n;
        age=a;
    }

    void sleep(){
        cout<<"zzz..."<<endl;
    }
     virtual void speak()=0;
     virtual ~Animal(){}
  
};
 void makeItSpeak(Animal* p) {
    p->speak();   // 不管传来的是 Dog 还是 Cat，都能正确调用
}
class Dog:public Animal{
    public:
    Dog(string n,int a)
    :Animal(n,a){}
    void bark(){
        cout<<"汪汪！"<<endl;
    }
    void speak(){
        cout<<"汪汪！"<<endl;
    }

};
class Cat:public Animal
{

public:
Cat(string n,int a)
:Animal(n,a){}
   void meow(){
    cout<<"喵~"<<endl;
   }
   void speak(){
    cout<<"喵"<<endl;
   }
};
int main(){
    Dog dog("dagou",4);
    Cat cat("tom",3);
makeItSpeak(&dog);
    makeItSpeak(&cat);   // 喵~
}
