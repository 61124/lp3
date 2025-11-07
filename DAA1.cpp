#include<iostream>
using namespace std;

int recFib(int n){
    if(n<=1){
        return n;
    }
    else{
        return recFib(n-1)+recFib(n-2);
    }
}

void iterFib(int n){
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

void towerOfHanoi(int n , char source,char destination, char aux){
    if(n==1){
        cout<<"Move disk 1 from "<<source<<" "<<"to"<<" "<<destination<<endl;
        return;
    }
        towerOfHanoi(n-1, source, aux,destination);
        cout<<"Move disk "<<n<<" "<<"from "<<source<<" to "<<destination<<endl;;
        towerOfHanoi(n-1,aux,destination,source);
    
}

int main(){
    int choice;
    int n;
    while(1){
        cout<<"\n1.Recursive Fibonacci\n2.Iterative fibonacci\n3.tower of hanoi\n0. Exit\nEnter your choice: ";
        cin>>choice;
        if(choice==1){
            cout<<"Enter the value of n"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<recFib(i)<<" ";
            }
        }
        else if (choice==2){
            cout<<"Enter the value of n"<<endl;
            cin>>n;
            iterFib(n);
        }
        else if (choice==3){
            cout<<"Enter the number of disks"<<endl;
            cin>>n;
            towerOfHanoi(n,'A','B','C');
        }
        else if (choice==0){
            cout<<"Thank you!";
            break;
        }
        else{
            cout<<"Invalid choice, please try again."<<endl;
        }
    }
    return 0;
}