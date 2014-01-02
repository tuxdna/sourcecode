package euler;

public class P14 {

	static final int CACHE_SIZE = 100 * 1000000;
	static int[] cache = new int[CACHE_SIZE];

	static int cobaltz(int n) {
		int rv;
		if (n > 0 && n < CACHE_SIZE && cache[n] != 0) {
			return cache[n];
		}
		if (n == 1) {
			rv = 1;
		} else if (n % 2 == 0) {
			rv = 1 + cobaltz(n / 2);
		} else {
			rv = 1 + cobaltz(3 * n + 1);
		}
		if (n > 0 && n < CACHE_SIZE) {
			cache[n] = rv;
		}
		return rv;
	}

	public static void main2(String[] args) {
		int max = 1;
		for (int n = 1; n <= 1000000; n++) {
			int chainLength = cobaltz(n);
			System.out.println(n + " " + chainLength);
			if (chainLength > max) {
				max = chainLength;
			}
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		long max = 0;
		for (long i = 1; i < 1000000; i++) {
			long n = i;
			long count = 1;

			// System.out.print(n + ", ");
			while (n != 1) {
				if (n % 2 == 0) {
					n = n / 2;
				} else {
					n = 3 * n + 1;
				}

				count++;
				// System.out.print(n + ", ");
			}
			if (count > max) {
				System.out.println(": " + i + " -> " + count);
				max = count;
			}
		}
	}

}
