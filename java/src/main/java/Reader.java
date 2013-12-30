import java.io.*;

public class Reader {
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			String str = br.readLine();
			System.out.println(str);
		} catch (java.io.IOException e) {
			//
		}
	}
}
