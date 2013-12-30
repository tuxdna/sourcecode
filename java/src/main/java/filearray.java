import java.io.*;

public class filearray {
	public static void main(String args[]) throws IOException {
		String[][] strings = {
				{ "player1", "player2", "player3", "player4", "player5",
						"player6" },
				{ "name1", "name2", "name3", "name4", "name5", "name6" } };
		for (int i = 0; i < strings.length; i++)
			System.out.println(strings[i][0]);
	}
}
