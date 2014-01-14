package euler;

public class P26 {
	private static boolean isPrime(int n) {
		boolean prime = true;
		for (int i = 2; i < n / 2; i++) {
			if (n % i == 0) {
				prime = false;
				break;
			}
		}
		return prime;
	}

	public static void main(String[] args) {
		// largest prime <= 1000
		int targetNumber = 2;
		for (int i = 1000; i > 1; i--) {
			if (isPrime(i)) {
				System.out.println(i);
				targetNumber = i;
				break;
			}
		}

		// https://en.wikipedia.org/wiki/Repeating_decimal#Cyclic_numbers
		// repeating decimals of 1 / p = p - 1
		System.out.println(targetNumber - 1);

		// TODO: Not complete yet
	}
}
