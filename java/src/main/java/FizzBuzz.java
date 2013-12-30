import java.util.Scanner;

public class FizzBuzz {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		for (int i = 1; i <= N; i++) {
			boolean fb = false;
			if (i % 3 == 0) {
				System.out.print("Fizz");
				fb = true;
			}
			if (i % 5 == 0) {
				System.out.print("Buzz");
				fb = true;
			}
			if (!fb) {
				System.out.print(i);
			}
			System.out.println();
		}
	}
}
