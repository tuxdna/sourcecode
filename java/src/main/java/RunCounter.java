public class RunCounter implements Runnable {
	public void run() {
		System.out.println("Thread running");
		System.out.println("exiting now.");
	}

	public static void main(String args[]) {
		Thread t = new Thread(new RunCounter());
		t.run();
	}
}
