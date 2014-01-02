package euler;

import java.util.BitSet;
import java.util.Set;
import java.util.TreeSet;

public class P12 {

	static long sumN(long n) {
		return n * (n + 1) / 2;
	}

	static int sumN(int n) {
		return n * (n + 1) / 2;
	}

	static BitSet factors = new BitSet();

	static int factorsCount(int n) {
		factors.clear();
		factors.set(1);
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				factors.set(i);
			}
		}
		factors.set(n);
		return factors.cardinality();
	}

	static int factorsCount2(int n) {
		int idx = 0;
		idx++;
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				idx++;
			}
		}
		idx++;
		return idx;
	}

	static Set<Long> factors(long n) {
		Set<Long> factors = new TreeSet<Long>();
		factors.add(1l);
		for (long i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				factors.add(i);
			}
		}
		factors.add(n);
		return factors;
	}

	public static void main(String[] args) {
		long max = Long.MIN_VALUE;
		for (int i = 10000; i <= 100000; i++) {
			int s = sumN(i);
			int numFactors = factorsCount2(s);
			max = Math.max(max, numFactors);
			System.out.println(String.format("%d, %d, %d, %d", i, s,
					numFactors, max));
			if (numFactors >= 500) {
				break;
			}
		}
	}
}
