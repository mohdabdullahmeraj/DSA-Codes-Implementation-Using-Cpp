#include <bits/stdc++.h>
using namespace std;

class minHeap{
private:
	vector<int> heap;

	void heapify(int index){
		int smallest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < heap.size() && heap[left] < heap[smallest])
			smallest = left;

		if (right < heap.size() && heap[right] < heap[smallest])
			smallest = right;

		if (smallest != index){
			swap(heap[index], heap[smallest]);
			heapify(smallest);
		}
	}

	void heapifyUp(int index){
		while (index > 0 && heap[(index-1)/2] > heap[index]){
			swap(heap[index], heap[(index-1)/2]);
			index = (index-1)/2;
		}
	}

public:

	void insert(int value){
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}

	void deleteMax(){
		if (heap.size() == 0){
			cout << "Heap is empty!" << endl;
			return;
		}

		heap[0] = heap.back();
		heap.pop_back();

		if (heap.size() > 0){
			heapify(0);
		}
	}

	void printHeap(){
		for (int i=0; i< heap.size(); i++){
			cout << heap[i] << " ";
		}

		cout << endl;
	}
};

int main(){
	minHeap mh;

    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(30);
    mh.insert(40);

    cout << "Max Heap after insertion: ";
    mh.printHeap();

    mh.deleteMax();
    cout << "Max Heap after deletion: ";
    mh.printHeap();

    return 0;
}      

















