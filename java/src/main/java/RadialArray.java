public class RadialArray {
	public static void main(String args[]) {
		final int N = 5;
		int a[][] = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 },
				{ 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 },
				{ 21, 22, 23, 24, 25 } };

		int left = 0, right = N - 1, top = 0, bottom = N - 1;
		while (left <= right && top <= bottom) {
			// top row
			for (int c = left; c <= right; c++) {
				System.out.println(a[top][c]);
			}
			top++;
			// right column
			for (int r = top; r <= bottom; r++) {
				System.out.println(a[r][right]);
			}
			right--;
			// bottom row
			for (int c = right; c >= left; c--) {
				System.out.println(a[bottom][c]);
			}
			bottom--;
			// left column
			for (int r = bottom; r >= top; r--) {
				System.out.println(a[r][left]);
			}
			left++;
		}
	}
}
