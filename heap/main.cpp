#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;




void MakeHeap(int *a, int input) {
    int a2[input];
    int index2[input];
    for(int i = 0; i < input; i++) {
        index2[i] = -1;
    }
    for(int i = 0; i < input; i++) {
        
        int max = 0;
        int index = 0;
        for(int j = 0; j < input; j++) {
            if(a[j] > max) {
                bool check = true;
                for(int i = 0; i < input; i++) {
                    if(j == index2[i]) {
                      check = false;
                    }
                }
                if(check == true) {
                   max = a[j];
                   index = j; 
                }
            }
        }
        
        index2[i] = index;
        a2[i] = max;
    }
    a = a2;
    for(int i = 0; i < input; i++) {
        cout << a[i] <<  " ";
    }
    cout << endl;
}

/*void inOrdrr(int *a, int input) {
    for(int i = 0; i < input; i++) {
        for(int j = 1; j < input; j++) {
            if(a[i] < a[j])
        }
    }
}*/


void makeHeap(int *a, int input) {
    int a2[input+1];
    int heaparr[input+1];
    for(int i = 1; i < input+1; i++) {
        a2[i] = a[i-1];
    }
    
    for(int i = 1; i < input+1; i++) {
        int right =  a2[i*2];
        int left = a2[i*2+1];
    }

}

void swap(int &j, int &k) {
    int temp = j;
    j = k;
    k = temp;
}



void printHeap() {
    cout << a[0];
    
    while(k < size) {
        cout << a[k];
        k++;
        if(k > )
    }
}

int main()
{
    while(true) {
       int input;
       cin >> input;
       
       int arr[input];
       for(int i = 0; i < input; i++) {
           cin >> arr[i];
       }
       MakeHeap(arr, input);
       
       
       cin.get();
    }
   
   
    
}






