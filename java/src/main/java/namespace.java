public class namespace {
	private String member;
	private String m2;

	public String member() {
		return member;
	}

	public void member(String m) {
		this.member = m;
		this.m2 = m;
	}

	public static void main(String args[]) {
		new Kest().main();
	}
}

class Kest {
	public void main() {
		namespace ns = new namespace();
		ns.member("name ");
		// System.out.println(ns.member() + ns.m2);
	}
}
