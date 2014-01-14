package org.tuxdna.interfaces.nesting;

public class NestingInterfaces {
	public class BImp implements A.B {
		public void f() {
		}
	}

	class CImp implements A.C {
		public void f() {
		}
	}

	// Cannot implement a private interface except
	// within that interface's defining class:
	// ! class DImp implements A.D {
	// ! public void f() {}
	// ! }
	class EImp implements E {
		public void g() {
		}
	}

	class EGImp implements E.G {
		public void f() {
		}
	}

	class EImp2 implements E {
		public void g() {
		}

		class EG implements E.G {
			public void f() {
			}
		}
	}

	public static void main(String[] args) {
		A a = new A();
		// Can't access A.D:
		// ! A.D ad = a.getD();
		// Doesn't return anything but A.D:
		// ! A.DImp2 di2 = a.getD();
		// Cannot access a member of the interface:
		// ! a.getD().f();
		// Only another A can do anything with getD():
		A a2 = new A();
		a2.receiveD(a.getD());
	}
} // /:~

