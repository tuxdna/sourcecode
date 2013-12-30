class FinallyReturn {
	public static void main(String[] s) {
		System.out.println("some() returns: " + some());
	}

	static Boolean some() {
		while (true) {
			try {
				return true;
			} finally {
				break;
			}
		}
		return false;
	}
}
