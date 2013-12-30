public class Hello {
	{
		System.out.println("Instance Initialization block");
	}

	Hello() {
		System.out.println("Hello Constructor");
	}

	public static void main(String[] args) {
		int i = 10;

		Hello n = new Hello();
		System.out.println("Hello");
		System.out.println(i);
		n = new Hello();

		int k = 0;
		switch (k) {
		case 2:
			System.out.println("Switch 2");
		default:
			System.out.println("Switch default");
		}

		if (null instanceof Object) {
			System.out.println("yes");
		} else {
			System.out.println("no");
		}

		// System.getProperties().list(System.out);
	}
}
