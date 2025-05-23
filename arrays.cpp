//
// Created by robotics on 4/28/25.
//

#include <iostream>
#include <vector>
#include <cstring>

// Function to print array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void staticArrayExample() {
    std::cout << "Static Array Example" << std::endl;
    int staticArray[5] = {10, 20, 30, 40, 50};

    // Access elements
    std::cout << "Element at index 0: "<<staticArray[0]<< std::endl;
    // TODO: Acces element  at index 0


    staticArray[0] = 15;
    // TODO: Set the element at index 0 to 15

    // Print after modification
    std::cout << "New element at index 0: " <<staticArray[0]
              // TODO: Acces element  at index 0

              << std::endl;
}

void dynamicArrayExample() {
    std::cout << "\nDynamic Array Example" << std::endl;
    int* dynamicArray = new int[3];  // Dynamically allocate array

    // Adding elements
    dynamicArray[0] = 5;
    dynamicArray[1] = 10;
    dynamicArray[2] = 15;

    std::cout << "Initial dynamic array: ";
    printArray(dynamicArray, 3);
    // Resizing dynamic array manually
    int* largerArray = new int[5];
    for (int i = 0; i < 3; i++) {
        // TODO: copy contents of dynamicArray to largerArray
        largerArray[i] = dynamicArray[i];
    }

    // Instead of a for loop, memcpy can also be used as below
    // memcpy(largerArray, dynamicArray, 3 * sizeof(int));

    // Adding more elements to resized array
    largerArray[3] = 20;
    largerArray[4] = 25;

    // TODO: Delete the dynamicArray
    delete [] dynamicArray;

    // Use the new larger array
    dynamicArray = largerArray;

    std::cout << "Resized dynamic array: ";
    printArray(dynamicArray, 5);

    // TODO: Delete the dynamicArray
    delete[] dynamicArray;

}

void multiDimArrayExample() {
    std::cout << "\nMulti Dimensional Array Example" << std::endl;

    // Declare and initialize a 2D array
    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };

    // Show that the 2D array is stored in
    // contiguous memory

    // TODO: Access the address of the element at row 0, column 0
    std::cout << "Address of arr 0,0: " <<&arr[0][0]

              << std::endl;

    // TODO: Access the value of the element at row 0, column 0
    std::cout << "Value of arr 0,0: " <<arr[0][0]

              << std::endl;

    // TODO: Access the address of the element at row 1, column 0
    std::cout << "Address of arr 1,0: " <<&arr[1][0]

              << std::endl;

    // TODO: Access the value of the element at row 1, column 0
    std::cout << "Value of arr 1,0: " <<arr[1][0]

              << std::endl;

    // TODO: Study the code and comments below to understand how number of elements
    // are calculated in two different ways

    // Calculate the number of elements in one row
    // Subtract the address of the first element in the first row
    // from the address of the first element in the second row.
    // When two pointers of the same type are subtracted, the
    // difference is automatically divided by the size of the data type (sizeof(int)).
    // So this pointer arithmetic directly gives the number of elements.
    auto numEls = &arr[1][0] - &arr[0][0];
    std::cout << "There are " << numEls << " elements in one row" << std::endl;

    // Manual calculation: Show the actual memory address difference in bytes
    // We cast the pointers to uintptr_t to get the memory addresses in bytes
    uintptr_t addressDiff = reinterpret_cast<uintptr_t>(&arr[1][0]) - reinterpret_cast<uintptr_t>(&arr[0][0]);

    // Divide the byte difference by sizeof(int) to calculate the number of elements
    auto numElsPtrArithmetic = addressDiff / sizeof(int);
    std::cout << "There are " << numElsPtrArithmetic << " elements in one row (2nd method)" << std::endl;
}

void vectorExample() {
    // std::vector example
    std::cout << "\nstd::vector Example" << std::endl;
    std::vector<int> vec;

    // TODO: Add elements 100, 200 and 300 to the vector
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);

    std::cout << "Vector contents: ";
    for (int i = 0; i < vec.size(); i++) {
        // TODO: Print elements of the vector
        std::cout<<vec.at(i)<<std::endl;
    }


    // Accessing elements
    // TODO: Access vector element at index 1 by using []s
    std::cout<<vec[1]<<std::endl;

    // TODO: Access vector element at index 1 by using the 'at' method
    std::cout<<vec.at(1)<<std::endl;

    // TODO: Display vector capacity and size
    std::cout<<"vector capacity:" <<vec.capacity()<<std::endl;
    std::cout<<"Vector size: "<<vec.size()<<std::endl;

    // Add new elements to the vector to see how the size and capacity change
    // TODO: Store the current capacity in a variable called prev_capacity
    auto prev_capacity = vec.capacity();
    for (uint8_t i = 100; i < 255; ++i) {
        vec.push_back(i);

        // Display vector size and capacity when the capacity changes
        // Note how the capacity typically increases (often doubles)
        // when the current size reaches the existing capacity.
        // Also, note how the address associated with the beginning
        // of the vector changes when the capacity changes.
        // That is because when the vector grows beyond its current capacity,
        // it allocates a new, larger contiguous memory block, and the elements
        // are copied to this new memory location, causing the address to change.

        // TODO: When the current vector capacity is different than prev_capacity
        // print following values;

        std::cout<<"Address of element 0 : "<< &(vec.at(0))
        <<"    |     Vector Size: "<< vec.size()
        <<"    |    Vector capacity: "<< vec.capacity()<<std::endl;

        // The address of the element at index 0
        // vector size
        // vector capacity


    }
}

int main() {
    staticArrayExample();

    dynamicArrayExample();

    multiDimArrayExample();

    vectorExample();

    return 0;
}
