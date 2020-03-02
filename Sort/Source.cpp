#include<iostream>
#include<array>
#include<chrono>
#include<vector>
#include<windows.h>
#include<iostream>
#include<chrono>
#include<windows.h>
#include<deque>
#include<list>
#include<forward_list>
class Timer {
	using clock_t = std::chrono::steady_clock;
	using timepoint_t = clock_t::time_point;
private:
	timepoint_t begin;
public:
	Timer()
	{
		start();
	}
	~Timer() noexcept
	{
	}
	void start() {
		begin = clock_t::now();
	}
	void stop() {
		auto end = clock_t::now();
		std::cout << std::chrono::duration_cast <std::chrono::milliseconds>

			(end - begin).count() << std::endl;

	}

};
int main() 
{
	Timer t = Timer();
	std::array<int, 30000> myArray;
	for (int i = 0; i < 30000; ++i) {
		myArray[i] = 30000 - i;
	}
	t.stop();
	std::cout << "Array: " << std::endl;
	t.start();
	std::sort(myArray.begin(), myArray.end());
	t.stop();
	std::vector<int> myVector;
	for (int i = 0; i < 30000; ++i) {
		myVector.push_back(30000 - i);
	}
	std::cout << "Vector: " << std::endl;
	t.start();
	std::sort(myVector.rbegin(), myVector.rend());
	t.stop();
	std::deque<int> myDeque;
	for (int i = 0; i < 30000; ++i) {
		myDeque.push_back(30000 - i);
	}
	std::cout << "Deque: " << std::endl;
	t.start();
	std::sort(myDeque.rbegin(), myDeque.rend());
	t.stop();
	
	std::list<int> myList;
	for (int i = 0; i < 30000; ++i) {
		myList.push_back(30000 - i);
	}
	std::cout << "MyList: " << std::endl;
	t.start();
	myList.sort();
	t.stop();
	std::forward_list<int> myforward_List;

	for (int i = 0; i < 30000; ++i) {
		myforward_List.push_front(30000 - i);
	}
	std::cout << "forwardList: " << std::endl;
	t.start();
	myforward_List.sort();
	t.stop();
	system("pause");


}