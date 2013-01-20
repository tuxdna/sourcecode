package org.tuxdna.matrix;

public interface IVector<V extends Number> {
	/**
	 * @param index
	 * @return Value at index
	 */
	public V get(int index);

	/**
	 * @param index
	 * @param value
	 */
	public void put(int index, V value);
	
	public int length();

}
