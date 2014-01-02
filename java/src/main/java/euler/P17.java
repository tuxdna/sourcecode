package euler;


public class P17 {
	static String[] names = { "zero", "one", "two", "three", "four", "five",
			"six", "seven", "eight", "nine", "ten", "eleven", "twelve",
			"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
			"eighteen", "nineteen", "twenty" };

	public static String spellNumber(int n) {
		if (n >= 1000) {
			int place = n / 1000;
			int remaining = n % 1000;

			String rv = names[place] + " " + "thousand";
			if (remaining > 0) {
				rv = rv + " " + spellNumber(remaining);
			}
			return rv;
		}

		if (n >= 100) {
			int place = n / 100;
			int remaining = n % 100;
			String rv = names[place] + " hundred";
			if (remaining > 0) {
				rv = rv + " and " + spellNumber(remaining);
			}
			return rv;
		}

		if (n > 20) {
			int remaining = n % 10;
			int decade = n / 10;
			String place = "";
			switch (decade) {
			case 2:
				place = "twenty";
				break;
			case 3:
				place = "thirty";
				break;
			case 4:
				place = "forty";
				break;
			case 5:
				place = "fifty";
				break;
			case 6:
				place = "sixty";
				break;
			case 7:
				place = "seventy";
				break;
			case 8:
				place = "eighty";
				break;
			case 9:
				place = "ninety";
				break;

			}
			String rv = place;
			if (remaining > 0) {
				rv = rv + " " + spellNumber(remaining);
			}
			return rv;

		}

		if (n >= 0 && n <= 20) {
			return names[n];
		}
		return "";

	}

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 1; i <= 1000; i++) {
			String spelling = spellNumber(i);
			String replaced = spelling.replaceAll(" ", "");
			sum += replaced.length();
			System.out.println(sum + ": " + spelling + " -> " + replaced);
		}
	}

	public static void main1(String[] args) {
		int numbers[] = { 0, 6, 10, 11, 20, 22, 69, 100, 121, 342, 390, 1001,
				2000 };
		for (int n : numbers) {
			System.out.println(n + " -> " + spellNumber(n));
		}
	}



}
