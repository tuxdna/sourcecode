package org.tuxdna.matrix;

public interface IMatrix<V extends Number> {
	public V get(int row, int col);

	public void put(int row, int col, V value);

	public IVector<V> getRowVector(int row);

	public IVector<V> getColumnVector(int col);

	public void putRow(int row, IVector<V> rowVector);

	public void putColumn(int col, IVector<V> columnVector);
}
