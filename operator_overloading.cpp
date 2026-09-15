#include<iostream>
using namespace std;
class channel{
    int subscribers;
    int views;
public:
    channel(){
        subscribers=1000;
        views=2000;
    }
    channel(int s,int v){
        subscribers=s;
        views=v;
    }
    channel operator+(channel c){
        channel temp;
        temp.subscribers=subscribers+c.subscribers;
        temp.views=views+c.views;
        return temp;
    }
    void display(){
        cout<<"subscribers = "<<subscribers<<" , views = "<<views<<endl;
    }
};
int main() {
    channel c1(1200,2500);
    channel c2(800,2500);
    channel c3=c1+c2;
    cout<<"Parameterized constructor output :"<<endl;
    cout<<"********** S & V of 1st & 2nd Month **********"<<endl;
    c1.display();
    c2.display();
    cout<<"*************** Total S & V ***************"<<endl;
    c3.display();
    channel c4;
    cout<<endl<<"Default Constructor output :"<<endl;
    c4.display();

    return 0;
}
