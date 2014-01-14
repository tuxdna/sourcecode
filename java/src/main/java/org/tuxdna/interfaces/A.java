package org.tuxdna.interfaces;
public interface A {

	A DEFAULT = new DefaultAImpl();
	
	void say();
	
	final class DefaultAImpl implements A {
		public void say() {
			System.out.println("Default Say");
		}
	}
}
