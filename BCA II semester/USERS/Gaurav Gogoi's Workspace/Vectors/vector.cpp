#include<iostream>
#include<vector> // STL : Standard template library within which the predefined code for vectors are written.
using namespace std;
int main(){
    vector <int> vec; // Declaring a vector data structure
    vec = {1,2,3}; // Initialising a vector data structure
    cout<<vec[0] <<endl; //printing vector data element contents
}

// Vectors are like array with indexing properties
// Vectors can also be declared and initialised like this
// vector <int> vec(3,0); here vec(number_of_data_elements,data_value to be initialised);

// vector <int> vec(3,0) structure in memory
// +----------------------------------+
// |          |             |         |
// |    0     |      0      |    0    | Data values initialised with 0 
// |          |             |         | Total 3 data space reserved at once
// +----------------------------------+
//   idx: 0      idx/: 1      idx: 2
/* Some of the vector functions include: 
    1. vector.size();
    2. vector.push_back;
    3. vector.pop_back();
    4. vector.front();
    5. vector.back();
    6. vector.at();
    7. vector.capacity();
*/
// Vectors are generally passed by value automatically in C++ functions as arguements. Therefore, in order to pass them as reference, we need to use "&" operator.