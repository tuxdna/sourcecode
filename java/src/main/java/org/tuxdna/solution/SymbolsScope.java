package org.tuxdna.solution;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

class InvalidInput extends RuntimeException {
	private static final long serialVersionUID = -72166879438009238L;
}

public class SymbolsScope {

	class NotFound extends RuntimeException {
		private static final long serialVersionUID = 885889498533281860L;
	}

	private HashMap<String, Integer> scopes[] = null;
	private int currentScope = -1;

	@SuppressWarnings("unchecked")
	public SymbolsScope() {
		scopes = (HashMap<String, Integer>[]) new HashMap[1000];
		currentScope = -1;
	}

	public void enterScope() {
		currentScope++;
		scopes[currentScope] = new HashMap<String, Integer>();
	}

	public void leaveScope() {
		scopes[currentScope] = null;
		currentScope--;
	}

	public boolean enteredScope() {
		return currentScope >= 0;
	}

	public int resolveSymbol(String s) throws NotFound {
		for (int i = currentScope; i >= 0; i--) {
			HashMap<String, Integer> m = scopes[i];
			// System.out.println(i + ": " + m);
			if (m.containsKey(s))
				return m.get(s);
		}
		throw new NotFound();
	}

	public void enlistScopes() {
		for (int i = currentScope; i >= 0; i--) {
			printScope(i);
		}
	}

	public void printScope(int i) {
		HashMap<String, Integer> m = scopes[i];
		System.out.println("  SCOPE " + i + ": " + m);
	}

	public void assign(String k, int v) {
		HashMap<String, Integer> m = scopes[currentScope];
		m.put(k, v);
	}

	public static void process(List<String> lines) {
		SymbolsScope ss = new SymbolsScope();
		int lineNumber = 0;
		boolean keepRunning = true;
		while (keepRunning && (lineNumber < lines.size())) {
			String l = lines.get(lineNumber);
			l = l.trim();
			if ("[".equals(l)) {
				ss.enterScope();
			} else if ("]".equals(l)) {
				ss.leaveScope();
			} else {

				// only proceed if we have entered atleast 1 scope
				if (!ss.enteredScope()) {
					throw new InvalidInput();
				}

				String k[] = l.split("\\s+");
				if (k.length != 2)
					throw new InvalidInput();
				if ("print".equalsIgnoreCase(k[0])) {
					String sym = k[1];
					int v = 0;
					try {
						v = ss.resolveSymbol(sym);
					} catch (NotFound e) {
						// ignore
					}
					System.out.println(v);
				} else {
					String sym = k[0];
					int value = 0;
					try {
						value = Integer.parseInt(k[1]);
					} catch (NumberFormatException nfe) {
						try {
							value = ss.resolveSymbol(k[1]);
						} catch (NotFound e) {
							throw new InvalidInput();
						}
					}
					ss.assign(sym, value);
				}
			}

			if (!ss.enteredScope())
				keepRunning = false;
			lineNumber++;
		}

	}

	public static void test() {
		List<String> lines = new ArrayList<String>();
		String lns[] = { "[", "a 10", "print a", "b 20", "[", "a 10",
				"print a", "print b", "b 23", "print b", "b a", "print b",
				"b 23", "]", "print a", "print b", "print c", "]" };
		lines = Arrays.asList(lns);
		process(lines);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<String> lines = new ArrayList<String>();
		while (scanner.hasNext()) {
			lines.add(scanner.nextLine());
		}
		process(lines);
	}
}
