#include<iostream>

int partition(int a[], int p, int r){
    int pivot = a[r], i = p - 1; // Initialize i to p - 1
    for(int j = p; j < r; j++){  // Fix the loop condition
        if(a[j] <= pivot){
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    int temp = a[r];
    a[r] = a[i+1];
    a[i+1] = temp;
    return i + 1; // Return the updated pivot position
}

void quickSort(int a[], int p, int r){
    if(p < r){ // Fix the loop condition
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int main(){
    int n, i;
    std::cin >> n;
    int a[n];
    for(i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    std::cout << "My unsorted list" << std::endl;
    for(i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    
    quickSort(a, 0, n - 1);
    
    std::cout << "\nMy sorted list" << std::endl; // Added a newline character
    for(i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    
    return 0;
}

