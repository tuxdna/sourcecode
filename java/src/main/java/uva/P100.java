package uva;

import java.util.Scanner;

public class P100 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {

			long start = sc.nextLong();
			long end = sc.nextLong();

			long max = 0;
			for (long i = start; i <= end; i++) {
				long n = i;
				long count = 1;

				while (n != 1) {
					if (n % 2 == 0) {
						n = n / 2;
					} else {
						n = 3 * n + 1;
					}

					count++;
				}
				if (count > max) {
					max = count;
				}
			}

			System.out.println(String.format("%d %d %d", start, end, max));
		}
	}

}
