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

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
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






