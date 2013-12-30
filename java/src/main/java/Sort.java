// class Sort includes heap sort with elimination of duplicates
class Sort {
	public static int heapsort2(int[] a) {
		int Length = a.length;
		int rootA = Length - 1; // position of root in the Array

		for (int i = Length / 2; i > 0; i--)
			/* buildHeap */
			percDown2(a, i, Length);
		int LastIndex = 0;// init new length of the sorted array

		// first time to swap
		int temp = a[rootA]; // hold the root after swap
		a[rootA] = a[0];// delete root: the last index in the array
		a[0] = temp;
		LastIndex++;
		System.out.print("\nLastIndex=" + LastIndex);
		// second and after with elimination of duplicates.
		for (int i = rootA; i > 0; i--) /* sorting, need i =1 */
		{// i = size of array
			System.out.print("\nPD1Before" + (i) + ">>");
			TestSort.print(a, a.length);
			percDown2(a, 1, i); // 1 and i are two ends
			// of children-parent tree
			System.out.print("\nPD1 After" + (i) + ">>");
			TestSort.print(a, a.length);

			// add codes to remove duplicates.
			if (a[rootA] == temp) {

				a[rootA] = a[Length - i]; // move last element up
				System.out.print("Dup");
			} else if (Length - i == LastIndex) {
				temp = a[rootA];
				swapReferences(a, rootA, Length - i);
				LastIndex++;
				System.out.print("IN 1");

			} else {
				a[LastIndex] = a[rootA];
				a[rootA] = a[Length - i];
				temp = a[LastIndex];
				LastIndex++;
				System.out.print("IN 3");

			}
		} // end For
		System.out.print("\nNewlength:" + LastIndex);

		return LastIndex;
	} // end of heapsort2

	// i is the parent root where the heap need to be fixed,
	// N = last index the child can be=size of the considered array
	private static void percDown2(int[] a, int i, int N) {
		int Length = a.length;
		int parent = i;
		int child = 2 * i;
		int tmp = a[a.length - i];

		while (child <= N) {
			if (child < N)
				if (a[Length - child] > a[Length - 1 - child])
					child++;
			if (a[Length - child] < tmp)
				a[Length - parent] = a[Length - child];
			else
				break;

			parent = child;
			child = 2 * parent;
		}
		a[Length - parent] = tmp;
		System.out.print("\nPD at " + (Length - i) + ":");
		TestSort.print(a, Length);
	}// end of perdown2

	public static void swapReferences(int[] a, int i1, int i2) {
		int tmp = a[i1];
		a[i1] = a[i2];
		a[i2] = tmp;
	}

}// end of class Sort
