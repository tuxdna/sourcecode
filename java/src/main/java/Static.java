class Base {
	static public void foo() {
		System.out.println("In Base::foo");
	}
}

class Derived extends Base {
	static public void foo() {
		System.out.println("In Derived::foo");
	}
}

class Static {
	public static void main(String[] s) {
		Base b = null;
		b.foo();
		((Derived) b).foo();
	}
}
