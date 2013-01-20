public class MinLongDoubleHeap {
	
	class LongDoublePair {
		public long key;
		public double value;
		public LongDoublePair(long key, double value) {
			this.key = key;
			this.value = value;
		}
	}
	
	private long[] keys;
	private double[] values;
	private int freeIndex = 0;

	public MinLongDoubleHeap() {
		int MAX_SIZE = 10;
		keys = new long[MAX_SIZE];
		values = new double[MAX_SIZE];
		freeIndex = 0;
	}

	public boolean insert(long key, double value) {
		if (freeIndex == keys.length) {
			return false;
		}
		keys[freeIndex] = key;
		values[freeIndex] = value;
		
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
			if (keys[index] < keys[parentIndex]) {
				exchange(index, parentIndex);
			} else {
				finished = true;
			}
		}
	}

	private void exchange(int i, int j) {
		long tmp = keys[i];
		keys[i] = keys[j];
		keys[j] = tmp;
		
		double vtmp = values[i];
		values[i] = values[j];
		values[j] = vtmp;
	}

	public boolean isEmpty() {
		return freeIndex <= 0;
	}

	LongDoublePair extractMin() {
		freeIndex--;
		// swap min location and the highest index location
		exchange(0, freeIndex);
		// now minimum value is at highest index location
		long minElem = keys[freeIndex];
		double minValue = values[freeIndex];
		heapifyDownwards(0);
		LongDoublePair pair = new LongDoublePair(minElem, minValue);
		return pair;
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
			smallerIndex = (keys[leftIndex] < keys[rightIndex]) ? leftIndex
					: rightIndex;
		}

		if (keys[smallerIndex] < keys[index]) {
			exchange(smallerIndex, index);
			heapifyDownwards(smallerIndex);
		}
	}

	public void print() {
		for (int i = 0; i < freeIndex; i++) {
			System.out.print(keys[i] + ":"+values[i]+", ");
		}
		System.out.println();
	}

	public static void main(String args[]) {

		MinLongDoubleHeap mh = new MinLongDoubleHeap();
		long[] keys   = { 3, 6, 1, 8, 4, 9, 1 };
		double[] values = { 3.0, 0.6, 1.31, 9.8, 5.4, 0.09, 2.0 };

		System.out.println("Before any insert");
		mh.print();
		for (int i = 0; i < keys.length; i++) {
			long key = keys[i];
			double value = values[i];
			mh.insert(key, value);
			System.out.println("After insert: " + key);
			mh.print();
		}

		while (!mh.isEmpty()) {
			LongDoublePair pair = mh.extractMin();
			System.out.println("After delete: " + pair.key);
			mh.print();
		}
	}
}
