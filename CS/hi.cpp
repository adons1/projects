#include <iostream>

using namespace std;

int main(){
    int number=0;
    int devider=2;
    int* arr=new int[10];
    for(int i=0;i<10;++i){
        *(arr+i)=0;
    }
    cout<<"Hello World";
    cin>>number;
    int clone_number=number;
    while(clone_number>0){
        if(clone_number % devider == 0){
            (*(arr+devider))++;
            clone_number/=devider;
        }
        else{
            devider++;
        }

    }
    for (int i = 0; i < 10; i++) {
        cout<<i<<"\t";
    }
    cout<<endl;
    for (int i = 0; i < 10; i++) {
        cout<<*(arr+i)<<"\t";
    }
    cout<<endl;

    delete[] arr;
    system("pause");
    return 0;
}
