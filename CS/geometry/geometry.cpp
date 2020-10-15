#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point{
        double x;
        double y;
};
struct Circle{
    int radius;
    Point center;

    void Print(){
        cout<<"CIRCLE:"<<endl;
        cout<<"Radius:"<< radius<<"\tCenter_x:"<< center.x <<"\tCenter_y:"<< center.y<<endl<<endl;
    }
};
struct Rectangle{
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Point center;
    short position_begin;
    short clockwise;
    void Print(){
        cout<<"RECTANGLE"<<endl;
        cout<<"p1_x:"<< p1.x <<"\tp1_y:"<< p1.y<<endl;
        cout<<"p2_x:"<< p2.x <<"\tp2_y:"<< p2.y<<endl;
        cout<<"p3_x:"<< p3.x <<"\tp3_y:"<< p3.y<<endl;
        cout<<"p4_x:"<< p4.x <<"\tp4_y:"<< p4.y<<endl;
        cout<<"center_X:"<< center.x <<"\tcenter_y:"<< center.y<<endl;
        cout<<"Clockwise:"<<clockwise<<endl;
        cout<<"Position_begin:"<<position_begin<<endl;
        cout<<endl;
    }
    void Clockwise(){
        if(p2.x-p1.x>0){
            if(p3.y-p1.y>0){
                clockwise = 0;
            }
            else{
                clockwise = 1;
            }
        }

        if(p2.x-p1.x<0){
            if(p3.y-p1.y>0){
                clockwise = 1;
            }
            else{
                clockwise = 0;
            }
        }

        if(p2.x-p1.x == 0){
            if (p3.x - p1.x > 0){
                if(p2.y-p1.y>0){
                    clockwise = 1;
                }
                else{
                    clockwise = 0;
                }
            }
            else{
                if(p2.y-p1.y>0){
                    clockwise = 0;
                }
                else{
                    clockwise = 1;
                }
            }

        }
    }
    void PositionBegin(){
        if((p3.x > p1.x)&&(p3.y > p1.y)){
            position_begin=3;
        }
        if((p3.x > p1.x)&&(p3.y < p1.y)){
            position_begin=0;
        }
        if((p3.x < p1.x)&&(p3.y > p1.y)){
            position_begin=2;
        }
        if((p3.x < p1.x)&&(p3.y < p1.y)){
            position_begin=1;
        }
    }
    void Center(){
        center.x= (p1.x+p2.x+p3.x+p4.x)/4.0;
        center.y= (p1.y+p2.y+p3.y+p4.y)/4.0;
    }
};
double sqr(double x){
    return x*x;
}
int main()
{
	ifstream fin;
	ofstream fout;
    Point centers[3];
	fin.open("input.txt");
	fout.open("output.txt");
    int n=0;
    int type;
    Circle circle;
    Circle circle_buffer;
    Rectangle rectangle;
    Rectangle rectangle_buffer;
    int result=0;
    int count=0;
    fin>>n;
    //---------------------------------------------------------
    for(int i=0; i<n; ++i){
        fin>>type;
        cout<<type<< endl;
        //---------------------------------------------------------
        if(type==0){

            fin>>circle.radius;

            fin>>circle.center.x;
            fin>>circle.center.y;
            centers[count%3].x=circle.center.x;
            centers[count%3].y=circle.center.y;
            count++;
            circle.Print();
        }
        //---------------------------------------------------------
        if(type==1){


            fin>>rectangle.p1.x;
            fin>>rectangle.p1.y;

            fin>>rectangle.p2.x;
            fin>>rectangle.p2.y;

            fin>>rectangle.p3.x;
            fin>>rectangle.p3.y;

            fin>>rectangle.p4.x;
            fin>>rectangle.p4.y;
            
            rectangle.Clockwise();
            rectangle.PositionBegin();
            rectangle.Center();
            centers[count%3].x=rectangle.center.x;
            centers[count%3].y=rectangle.center.y;
            count++;
            rectangle.Print();
        }
        if (count > 2 ){
                cout<< centers[1].x <<"\t"<< centers[0].x<<"\t" <<(centers[1].x-centers[0].x)<< endl;
                cout<< centers[2].y <<"\t"<< centers[1].y<<"\t"<< (centers[2].y-centers[1].y)<< endl;
                cout<< centers[2].x <<"\t"<< centers[1].x<<"\t"<< (centers[2].x-centers[1].x)<< endl;
                cout<< centers[1].y <<"\t"<< centers[0].y<<"\t"<< (centers[1].y-centers[0].y)<< endl;

                result = ((centers[1].x-centers[0].x)*(centers[2].y-centers[1].y))-((centers[2].x-centers[1].x)*(centers[1].y-centers[0].y));
                cout<<result<<endl;
                if(result!=0){
                    cout<<"No";
                    break;
                }
                else{
                    if(i== n-1){
                        cout<<"Yes";
                    }
                    //break;
                }
        }


        //---------------------------------------------------------
    }
    if (count<=2){
        cout<<"Yes"<<endl;
    }

//---------------------------------------------------------
	fin.close();
	fout.close();

    return 0;
}
