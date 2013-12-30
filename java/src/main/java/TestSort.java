/* Designer: Son Pham
    Dated: 10/26/2000
    Implemented and tested: 10/26/2000
    Objective: to sort an array of records on the field key
         using heap sort and eliminate all rows of the same key
         
 */

class TestSort {
	private static final int NUM_ITEMS = 7;

	// to print the int array from 0..size, where size < a.length.
	public static void print(int[] a, int Length) {
		for (int i = 0; i < Length; i++)
			System.out.print(i + ":" + a[i] + " | ");
	}

	public static void main(String[] args) {
		// get array and print it out; make some duplicates.
		int[] a = new int[NUM_ITEMS];
		int half = 2;
		for (int i = 0; i < half; i++)
			a[i] = i;
		for (int i = half; i < a.length; i++)
			a[i] = i - half;
		System.out.print("\nOriginal");
		print(a, a.length);

		// Sort the array and print it out
		int LastIndex = Sort.heapsort2(a);
		System.out.print("\nSorted array");
		print(a, LastIndex);
	}// end of main

}// End of class TestSort

