

/**
 * Creates a simple neuron layer using dot product.
 * 
 * Associated tutorial https://www.youtube.com/watch?v=tMrbN67U9d4
 */

#include <iostream>
#include <vector>
#include <numeric>

using std::vector;
using std::inner_product;



int main() {

	vector<double> inputs = {1.0, 2.0, 3.0, 2.5};
	vector<vector<double>> weights = 
	{
		{0.2, 0.8, -0.5, 1.0},
		{0.5, -0.91, 0.26, -0.5},
		{-0.26, -0.27, 0.17, 0.87}
	};

    vector<double> biases = {2.0, 3.0, 0.5};
	vector<double> output;
	
	for(size_t i=0; i<weights.size() /* OR i<inputs.size() */; i++)
		output.push_back(inner_product(inputs.begin(), inputs.end(), weights[i].begin(), biases[i]));
	
	
	std::cout << "[";
	std::cout << output[0] << ", ";
	std::cout << output[1] << ", ";
	std::cout << output[2] << "]" << std::endl;
}
