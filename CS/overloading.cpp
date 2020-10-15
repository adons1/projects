#include <iostream>
#include <string>
#define I std::cin>>
#define O std::cout<<
#define E <<std::endl
#define S std::string

class Man{
    protected:
        S man;
    public:
        Man():man("cholovik"){
            O "Man constructed"+(*this).man E;
        }
};
class Person:Man{
    private:
        int one = 5;
        int second;
    public:
        Person(int valuee)
            :Man(),
             second(valuee){
                O "constructed"<<this->second E;
            }
    public:
        int getOne(){
            return this->one;
        }
};
int* add(int& x, double y){
    O x E;
    O y E;
    return &x;
}
void print(int* (*functor)(int&, double), int q){
    functor(q, 4.0);
}
int main()
{

    int q;
    print(add, 5);
    O "Hello" E;
    Person pers(32000);
    O pers.getOne() E;
    try{
        throw -1;
    }
    catch(int iii){
        if(iii==-1){
            #ifdef E
            #ifndef O
            O "Exception" E;
            #endif
            #endif
        }
    }
	return 0;
}
