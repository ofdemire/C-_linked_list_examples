#include <iostream>

template <typename T>
void rec_selection(T array[], std::size_t begin, std::size_t last ){

	T largest_val{array[0]};
	std::size_t largest_index{0};


	for(std::size_t k{begin}; k <last;++k){
		if(largest_val < array[k]){

			largest_val=array[k];
			largest_index = k;
		}
	}

	T temp=array[last-1];
	array[last-1]=array[largest_index];
	array[largest_index]=temp;

	if(last > begin+2)
		rec_selection(array,begin,last-1);
}


int main(){

	int arr[4]{8,0,-6,-7};

	rec_selection(arr,0,4);

	for(int i{0}; i< 4;++i)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}