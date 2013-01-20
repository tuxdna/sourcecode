public class MinHeap {
	private int[] array;
	private int freeIndex = 0;

	public MinHeap() {
		array = new int[10];
		freeIndex = 0;
	}

	public boolean insert(int value) {
		if (freeIndex == array.length) {
			return false;
		}
		array[freeIndex] = value;
		moveMinUpwards(freeIndex);
		freeIndex++;
		return true;
	}

	private void moveMinUpwards(int index) {
		if (index <= 0) {
			return;
		}
		boolean finished = false;
		while (!finished) {
			int parentIndex = (index - 1) / 2;
			if (array[index] < array[parentIndex]) {
				exchange(index, parentIndex);
			} else {
				finished = true;
			}
		}
	}

	private void exchange(int i, int j) {
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	public boolean isEmpty() {
		return freeIndex <= 0;
	}

	int extractMin() {
		freeIndex--;
		// swap min location and the highest index location
		exchange(0, freeIndex);
		// now minimum value is at highest index location
		int minElem = array[freeIndex];
		heapifyDownwards(0);
		return minElem;
	}

	private void heapifyDownwards(int index) {
		if (index >= freeIndex)
			return;

		int smallerIndex;

		int leftIndex = index * 2 + 1;
		int rightIndex = index * 2 + 2;

		// bounds check
		if (leftIndex >= freeIndex) {
			return;
		} else if (rightIndex >= freeIndex) {
			smallerIndex = leftIndex;
		} else {
			smallerIndex = (array[leftIndex] < array[rightIndex]) ? leftIndex
					: rightIndex;
		}

		if (array[smallerIndex] < array[index]) {
			exchange(smallerIndex, index);
			heapifyDownwards(smallerIndex);
		}
	}

	public void print() {
		for (int i = 0; i < freeIndex; i++) {
			System.out.print(array[i] + ", ");
		}
		System.out.println();
	}

	public static void main(String args[]) {

		MinHeap mh = new MinHeap();
		int[] input = { 3, 6, 1, 8, 4, 9 };

		System.out.println("Before any insert");
		mh.print();
		for (int v : input) {
			mh.insert(v);
			System.out.println("After insert: " + v);
			mh.print();
		}

		while (!mh.isEmpty()) {
			int v = mh.extractMin();
			System.out.println("After delete: " + v);
			mh.print();
		}

	}
}
