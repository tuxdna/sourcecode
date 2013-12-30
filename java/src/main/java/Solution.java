import java.util.BitSet;
import java.util.Scanner;

public class Solution {
	static int[][] table = null;
	static int maxAll = 0;

	private static String bstostring(BitSet set, int N) {
		StringBuilder sb = new StringBuilder();
		sb.append("{");
		for (int i = 0; i < N; i++) {
			if (set.get(i)) {
				sb.append("1,");
			} else {
				sb.append("0,");
			}
		}
		sb.append("}");
		return sb.toString();
	}

	static void flipCount(int L, int R, BitSet set) {
		if (L > R)
			return;
		if (L == R) {
			int onesCount = 0;
			if (set.get(L) == false) {
				// if we flip this we get count of 1
				onesCount = 1;
			} else {
				onesCount = 0;
			}
			table[L][R] = onesCount;
		}

		// otherwise partition
		for (int i = L; i <= R; i++) {
			flipCount(L, i, set);
			flipCount(i + 1, R, set);
			int max = Math.max(table[L][R], table[L][i] + table[i + 1][R]);
			table[L][R] = max;
			maxAll = Math.max(maxAll, max);
		}
	}

	public static void main(String[] args) {
		boolean verbose = true;
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		BitSet d = new BitSet(N);

		for (int i = 0; i < N; i++) {
			int bit = sc.nextInt();
			// set the bit
			if (bit == 1)
				d.set(i);
		}

		int S = 0;
		table = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				table[i][j] = 0;
			}
		}

		// logic for range in which we get max 1s
		if (verbose)
			System.out.println("on (_,_) -> " + bstostring(d, N));

		// for (int i = 0; i < N; i++) {
		// for (int j = i; j < N; j++) {
		// BitSet copy = (BitSet) d.clone();
		// copy.flip(i, j);
		// int s = copy.cardinality();
		// if (verbose)
		// System.out.println("on (" + i + "," + j + ") -> "
		// + bstostring(copy, N) + " => " + s);
		//
		// S = Math.max(S, s);
		// }
		// }

		flipCount(0, N - 1, d);
		S = maxAll;
		sc.close();
		System.out.println(S);
	}

}
