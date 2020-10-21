#include <iostream>
#include <string>
#define I std::cin>>
#define O std::cout<<
#define E <<std::endl
#define E_E <<std::endl<<


using namespace std;

void push(int*, int);
void print(int*);
void pop(int*);
bool my_is_empty(int*);
void _help_realese_mode(int*, string, int*);
int* _help_reallocate(int*, int);

int main(){
    int n=10;
    string command="";
    int value;
    int* values=new int[n+1];
    for (int i=0;i<n;++i){
        *(values+i)=0;
    }
    *(values)=1;
    for(int i=0; i< 100; ++i){
        push(values, i);
        if(i%2==0){
            pop(values);
        }
    }
    print(values);
    return 0;
}
void _help_realese_mode(int* values, string command, int* value){
    while (true){
        O "command:";
        I command;
        if(command=="push"){
            O "value:";
            I *value;
            push(values, *value);
            print(values);
        }
        if(command=="pop"){
            pop(values);
            print(values);
        }
        if(command=="exit"){
            return;
        }
        if((command!="pop")&&(command!="push")&&(command!="exit")){
            O "wrong command" E;
        }

    }
}
void print(int* values){
    O endl;
    for (int i=0;i<*values;++i){
        O *(values+i)<<"\t";
    }
    O endl;
}
void push(int* values, int value){

    if((*values+1)% 11 != 0){
        *(values+*(values))=value;
        (*values)++;
    }
    else{
        *(values+*(values))=value;
        (*values)++;
        values=_help_reallocate(values, 10);
    }

}
void pop(int* values){
    if(!(my_is_empty(values))){
        (*values)--;
        if((*values)% 11 == 0){
            values= _help_reallocate(values, 0);
        }
    }
    else{
        O "there is nothing to pop, because stack is empty!" E;
    }
}
bool my_is_empty(int* values){
    return ((*values) == 1) ? true: false;
}
int* _help_reallocate(int* values, int alloc){
    int* _help_array=new int[(*values)+alloc];
    for (int i=0; i<*values; ++i){
        *(_help_array+i)=*(values+i);
    }
    //delete[] values;
    O "realocated"<<alloc E;
    return _help_array;
}
