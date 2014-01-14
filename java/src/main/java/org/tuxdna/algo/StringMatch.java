package org.tuxdna.algo;
public class StringMatch {

	public static boolean naiveMatch(String needle, String haystack) {
		boolean matched = false;
		if (needle == null || haystack == null) {
			return matched;
		}
		byte[] htk = haystack.getBytes();
		byte[] ndl = needle.getBytes();

		for (int i = 0; (i < htk.length - ndl.length + 1) && !matched; i++) {
			matched = true;
			for (int j = 0; j < ndl.length; j++) {
				if (ndl[j] != htk[i + j]) {
					System.out.println("HERE");
					matched = false;
					break;
				}
			}
		}
		return matched;
	}

	public static int naiveMatchAt(String needle, String haystack) {
		int matchIndex = -1;
		if (needle == null || haystack == null) {
			return matchIndex;
		}
		byte[] htk = haystack.getBytes();
		byte[] ndl = needle.getBytes();

		boolean matched = false;
		int i = 0;
		for (; (i < htk.length - ndl.length + 1) && !matched; i++) {
			matched = true;
			for (int j = 0; j < ndl.length; j++) {
				if (ndl[j] != htk[i + j]) {
					matched = false;
					break;
				}
			}
		}
		if (matched) {
			matchIndex = i - 1;
		}
		return matchIndex;
	}

	// very naive hash function
	private static int makeHash(byte[] s, int start, int count) {
		int hashValue = 0;
		for (int i = start; i < count; i++) {
			byte b = s[i];
			hashValue += (int) b;
		}
		return hashValue;
	}

	// very naive re-hash function
	private static int reHash(int orig, byte removed, byte added) {
		return orig - (int) removed + (int) added;
	}

	public static int RKMatch(String needle, String haystack) {
		int matchIndex = -1;
		if (needle == null || haystack == null) {
			return matchIndex;
		}
		byte[] target = haystack.getBytes();
		byte[] pattern = needle.getBytes();
		if (target.length < pattern.length)
			return matchIndex;

		int hashPattern = makeHash(pattern, 0, pattern.length);
		int hashTarget = makeHash(target, 0, pattern.length);

		int i = 0;
		for (; (i < target.length - pattern.length); i++) {
			if (hashTarget == hashPattern) {
				int j = 0;
				for (; j < pattern.length; j++) {
					if (pattern[j] != target[i + j]) {
						break;
					}
				}
				if (j == pattern.length) {
					matchIndex = i;
					break;
				}
			}
			hashTarget = reHash(hashTarget, target[i], target[i
					+ pattern.length]);
		}
		return matchIndex;
	}

	public static void main(String[] args) {
		String bigString = "a very strong word";
		String toSearch = " very strong wor";
		// String bigString = "abcd";
		// String toSearch = "bc";

		System.out.println("naive Match");
		System.out.println(naiveMatch(toSearch, bigString));
		System.out.println("naive Match with Index");
		System.out.println(naiveMatchAt(toSearch, bigString));
		System.out.println("Rabin Karp Match with Index");
		System.out.println(RKMatch(toSearch, bigString));
	}
}
