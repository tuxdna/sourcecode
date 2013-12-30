import java.util.BitSet;
import java.util.Scanner;

/**
 * Give a number N and binary digits d(0) to d(N-1)
 * 
 * Also a flip(L, R) operation which flips/toggles all the bits from d(L) to
 * d(R). Find maximum number of ones that can be obtained on any one single flip
 * operation.
 * 
 * Example Input: N = 8, d = (10010010)
 * 
 * Output: Max ones = 6
 */
public class SolutionBruteForce {

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

		// logic for range in which we get max 1s
		if (verbose)
			System.out.println("on (_,_) -> " + bstostring(d, N));

		int S = 0;
		int table[][] = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				BitSet copy = (BitSet) d.clone();
				copy.flip(i, j);
				int s = copy.cardinality();
				if (verbose)
					System.out.println("on (" + i + "," + j + ") -> "
							+ bstostring(copy, N) + " => " + s);

				table[i][j] = s;
				S = Math.max(S, s);
			}
		}

		for (int i = 0; i < N; i++) {
			System.out.print(i + ": ");
			for (int j = 0; j < N; j++) {
				System.out.print(table[i][j] + " ");
			}
			System.out.println();
		}
		sc.close();
		System.out.println(S);
	}

}
