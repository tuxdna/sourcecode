package org.tuxdna.solution;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class CouponGenerator {

	static class SubsetSum {

		private int s[], target;

		public SubsetSum(int s[], int value) {
			this.s = s;
			this.target = value;
		}

		public boolean subsetSum(int sum, int i, List<Integer> rv) {
			if (sum == this.target)
				return true;
			if (i >= s.length)
				return false;
			int t = sum + s[i];

			if (subsetSum(t, i + 1, rv)) {
				rv.add(i);
				return true;
			}
			if (subsetSum(sum, i + 1, rv)) {
				return true;
			}
			return false;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = Integer.parseInt(scanner.nextLine());
		Map<String, Integer> entries = new HashMap<String, Integer>();
		for (int i = 0; i < N; i++) {
			String line = scanner.nextLine().trim();
			String kv[] = line.split("\\s+");
			entries.put(kv[0], Integer.parseInt(kv[1]));
		}

		while (true) {
			String line = scanner.nextLine().trim();
			if ("END".equals(line))
				break;
			String kv[] = line.split("\\s+");
			int target = Integer.parseInt(kv[0]);
			int costs[] = new int[kv.length - 1];
			String names[] = new String[kv.length - 1];
			int index = 0;
			for (int i = 1; i < kv.length; i++) {
				String itemName = kv[i];
				if (!itemName.startsWith("!")) {
					int c = entries.get(itemName);
					String n = kv[i];
					costs[index] = c;
					names[index] = n;
					index++;
				}
			}

			List<Integer> itemIndices = new ArrayList<Integer>();
			SubsetSum ss = new SubsetSum(costs, target);
			boolean hs = ss.subsetSum(0, 0, itemIndices);
			if (hs) {
				Collections.reverse(itemIndices);
				for (Integer i : itemIndices) {
					System.out.print(names[i] + " ");
				}
			}

			System.out.println();
		}
	}
}
