public class Counter extends Thread {
	public void run() {
		System.out.println("Thread running");
		System.out.println("exiting now.");
	}

	public static void main(String args[]) {
		Counter ctr = new Counter();
		ctr.start();
	}
}
