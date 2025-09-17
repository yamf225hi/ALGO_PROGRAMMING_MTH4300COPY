#include <iostream>
using namespace std;


// int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    if(num%2==0 && num%3==0)
    {
        test_conditions(num);
    }
    else if(num%2==0 || num%3==0)
    {
        cout<<"(number is dividible by 2 or 3)";
    }
    else
    {
        cout<<"(number is not dividible by 2 or 3)";
    }

    return 0;
}



void test_conditions(int num)
{
    if(num%2 ==0 && num%3==0)
{
cout<<"(number is dividible by 2 and 3)";

    else if(num%3 ==0)
{
        cout<<"(number is dividible by 3 only)";

    }
    else 
    {
        cout<<"(number is not dividible by 2 or 3";
    }
}
