// prgorma that converts a decimal number to binary using recursion
//note: prolly gonna have to brush up on base 2 number system gg


#include<iostream>

using namespace std;

string to_binary(int num);

int main()
{
    cout<<"Enter number: ";
    int num;
    cin>>num;
    cout<<endl;

    string bin = to_binary(num);
    cout<<"Binary Representation: "<<bin<<endl;
    return 0;
}

string to_binary(int num)
{
    string bin_num = ""; //bin is short for binary;    here string bin_num is initialized to empty string, the "".

    while(num>0)
    {
        if(num%2==0)
        {
            bin_num="0"+bin_num; //concatenation of strings; this is saying whateveer was in bin_num, add a 0 to the front of it.if its even you place a 0 in front of the string and if its odd you place a 1 in front of the string.
        }

        else if(num%2==1)
        {
            bin_num="1"+bin_num;
        }

        num=num/2; //integer division; this is dividing num by 2 and updating num to be the result of that division. This effectively shifts the number to the right in binary representation, preparing it for the next iteration of the loop.So if num is 7, 7/2 is 3.5 but since its integer division it becomes 3. If num is 8, 8/2 is 4. This process continues until num becomes 0, at which point the loop terminates.
    }

    return bin_num;
}