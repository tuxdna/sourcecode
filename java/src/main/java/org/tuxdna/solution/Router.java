package org.tuxdna.solution;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Rule {
	public String m0, m1, dest;
	public long ip, netmask;

	Rule() {
		m0 = m1 = dest = null;
	}

	public boolean match(String ipString) {
		long queryIp = stringToIntIp(ipString);
		if ((queryIp & this.netmask) == this.ip) {
			return true;
		}
		return false;
	}

	public static String intToStringIp(long queryIp) {
		return ((queryIp >> 24) & 0xff) + "." + ((queryIp >> 16) & 0xff) + "."
				+ ((queryIp >> 8) & 0xff) + "." + ((queryIp) & 0xff);
	}

	public static long stringToIntIp(String ip) {
		long k = 0;
		String c[] = ip.split("\\.");
		if (c.length != 4)
			throw new RuntimeException("");
		for (int i = 0; i < c.length; i++) {
			int v = Integer.parseInt(c[i]);
			k <<= 8;
			k |= v;
			// System.out.println(c[i] + ":" + v + ":" + k);
		}
		return k;
	}

	@Override
	public String toString() {
		return Rule.intToStringIp(this.ip) + "/"
				+ Rule.intToStringIp(this.netmask) + " -> " + this.dest;
	}
}

public class Router {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String defaultDestination = null;
		List<Rule> rules = new ArrayList<Rule>();
		// System.out.println(ipToInt("255.255.255.255"));
		// System.out.println();
		// System.out.println(ipToInt("0.0.0.255"));
		// System.exit(0);
		int N = scanner.nextInt();
		for (int i = 0; i < N; i++) {
			// rule
			// 1 - matcher
			// 2 - destination
			String m0 = scanner.next().trim();
			String m1 = null;
			String dest = null;
			if ("default".equalsIgnoreCase(m0)) {
				defaultDestination = scanner.next();
				break;
			}
			m1 = scanner.next().trim();
			dest = scanner.next();
			// convert m0 and m1 to integers
			Rule rule = new Rule();
			rule.m0 = m0;
			rule.m1 = m1;
			rule.dest = dest;
			rule.ip = Rule.stringToIntIp(m0);
			rule.netmask = Rule.stringToIntIp(m1);
			rules.add(rule);
		}

		int M = scanner.nextInt();
		for (int i = 0; i < M; i++) {
			String q = scanner.next().trim();
			String match = null;
			String output = null;
			// match q in all the rules
			// System.out.println("Matching : " + q);
			for (Rule r : rules) {
				// System.out.println(" with: " + r);

				if (r.match(q)) {
					match = r.dest;
					break;
				}
			}

			if (match != null) {
				output = match;
			} else {
				if (defaultDestination != null) {
					output = defaultDestination;
				} else {
					output = "NO ROUTE DEFINED";
				}
			}
			System.out.println(output);
		}
	}
}
