package org.tuxdna.algo;
import java.lang.reflect.Field;

class ValueMunger extends Thread {
	public void run() {
		while (true) {
			munge();
			try {
				sleep(1000);
			} catch (Throwable t) {
			}
		}
	}

	public void munge() {
		try {
			Field field = Integer.class.getDeclaredField("value");
			field.setAccessible(true);
			for (int i = -127; i <= 128; i++)
				field.setInt(Integer.valueOf(i),
				// either the same (90%), +1 (10%), or 42 (1%)
						Math.random() < 0.9 ? i : Math.random() < 0.1 ? 42
								: i + 1);
		} catch (Throwable t) {
			;
		}
	}	

}

public class StringMutation {
	public static void main(String[] args) throws NoSuchFieldException,
			SecurityException, IllegalArgumentException, IllegalAccessException {
		(new ValueMunger()).start();
		String s1 = "Hello World";
		String s2 = "Hello World";
		String s3 = s1.substring(6);
		System.out.println(s1); // Hello World
		System.out.println(s2); // Hello World
		System.out.println(s3); // World

		Field field = String.class.getDeclaredField("value");
		field.setAccessible(true);
		char[] value = (char[]) field.get(s1);
		value[6] = 'J';
		value[7] = 'a';
		value[8] = 'v';
		value[9] = 'a';
		value[10] = '!';

		System.out.println(s1); // Hello Java!
		System.out.println(s2); // Hello Java!
		System.out.println(s3); // World

		int x = (Integer) 1 + (Integer) 2;
		System.out.println(x);
		x = (Integer) 1 + (Integer) 2;
		System.out.println(x);
}
}
