#include <iostream>
#include "MathV.h"

//#define COMPILATION_ERROR

int main() {
	MathV v1(3);		
	const MathV v2(2);	

	v1.at(0) = 1;
	v1.at(1) = 2;
	const MathV v3 = v1;
	v1.at(1) = 0;
	v3.at(2) = 4;

	v1.print("v1: ");
	v2.print("v2: ");
	v3.print("v3: ");
    
	double prod = MathV::dot(v1, v3); 
	std::cout << "Dot product = " << prod << std::endl;
	std::cout << "Another dot product: " << std::endl;
	MathV::dot(v1,v2);

	
	double norm = static_cast<double>(v3); // == v3.norm();
	std::cout << "Norm = " << norm << ", " << v3.norm() << std::endl;
	
	MathV v4{v1};
	v4.add(v3);
	v4.print("v4 = v1 + v3: ");

	MathV v5 = std::move(v4);
	v5.print("v5: ");

	(v1.add(1)).print("v1 + 1 : ");

	#ifdef COMPILATION_ERROR
	MathV strange = 5;
	#endif
}

/*
// Output: ./Lab10
v1: [1, 0, 0]
v2: [0, 0]
v3: [1, 2, 4]
Dot product = 1
Another dot product: 
Error, vectors of different dimensions!
Norm = 4.58258, 4.58258
v4 = v1 + v3: [2, 2, 4]
v5: [2, 2, 4]
v1 + 1 : [2, 1, 1]
*/
