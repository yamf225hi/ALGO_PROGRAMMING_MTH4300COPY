#include<iostream>
#include<algorithm>

using namespace std;

int product_pi(int n, int i);
int n_choose_k(int n, int k);
void power_set(int set[], int size);
int** subset_with_k_elems(int arr[], int size_arr, int k);
void power_set_recursive(int arr[], int size, int index);

int main()
{
    int set[3]={1,2,3};
    power_set_recursive(set, sizeof(set)/sizeof(set[0]), sizeof(set)/sizeof(set[0])-1);
    return 0;
}


void power_set(int set[], int size)
{
    //this gotta be a 3d array(maybe)
    int **p_s=new int*[size];
    for(int i=1; i<size;i++)
        subset_with_k_elems(set,size,i);

    // for(int row=0;row<size;row++)
    //     for(int col; col<n_choose_k(size, row+1);col++)
    //         cout<<p_s[row][col]<<" ";

    // for(int row = 0; row < size; row++)
    // {
    //     delete[] p_s[row];
    //     p_s[row]=nullptr;
    // }
    // delete[] p_s;
    // p_s=nullptr;
}


int** subset_with_k_elems(int arr[], int size_arr, int k)
{
    int size_sub_arr=n_choose_k(size_arr,k);
    int** sub_arr= new int*[size_sub_arr];
    for(int i=0;i<size_sub_arr;i++)
        sub_arr[i]=new int[k];
    
    for(int row=0;row<;row++)
        for(int col=0;col<;col++)
            sub_arr[row][col]=;

    return sub_arr;
}


int product_pi(int n, int i)
{
    if(n<=0)
        return -1;

    int product=n;
    for(; i<n; i++)
        product = product*i;
    return product;
}


//combination
int n_choose_k(int n, int k)
{
    return product_pi(n,max(k,n-k)+1)/product_pi(min(k,n-k),1);
}

//recursive
void power_set_recursive(int arr[], int size, int index)
{
    if(index == 0)
    {
        cout<<"{}";
        return;
    }

    int curr_powerset[2];     

    


}