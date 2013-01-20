package org.tuxdna.matrix;

import java.util.ArrayList;
import java.util.List;

public class ArrayDenseMatrix<V extends Number> implements IMatrix<V> {

	private List<List<V>> mat = null;
	private int rowCount, columnCount;

	public ArrayDenseMatrix(int rows, int columns) {
		this.rowCount = rows;
		this.columnCount = columns;
		this.mat = new ArrayList<List<V>>(rows);
		for(int i =0; i<columns; i++) {
			this.mat.add(i,new ArrayList<V>(columns));
		}
	}

	public V get(int row, int col) {
		if (row < 0 || col < 0 || row >= this.rowCount
				|| col >= this.columnCount) {
			return null;
		}
		List<V>  rowList = this.mat.get(row);
		return rowList.get(col);
	}

	public void put(int row, int col, V value) {
		if (row < 0 || col < 0 || row >= this.rowCount
				|| col >= this.columnCount) {
			return;
		}
		List<V>  rowList = this.mat.get(row);
		rowList.add(col, value);
	}

	public IVector<V> getRowVector(int row) {
		return new ArrayDenseRowVector(row);
	}

	public IVector<V> getColumnVector(int col) {
		return new ArrayDenseColumnVector(col);
	}

	public void putRow(int row, IVector<V> rowVector) {
		ArrayDenseRowVector currRowVec = new ArrayDenseRowVector(row);
		for(int i = 0; i < rowVector.length(); i++) {
			currRowVec.put(i, rowVector.get(i));
		}
	}

	public void putColumn(int col, IVector<V> columnVector) {
		// TODO Auto-generated method stub
	}
	
	class ArrayDenseRowVector implements IVector<V> {

		private int rowId;
		public ArrayDenseRowVector(int rowId) {
			this.rowId = rowId;
		}
		
		public V get(int index) {
			return mat.get(rowId).get(index);
		}

		public void put(int index, V value) {
			mat.get(rowId).add(index, value);
		}

		public int length() {
			return mat.get(rowId).size();
		}
	}

	class ArrayDenseColumnVector implements IVector<V> {

		private int columnId;
		public ArrayDenseColumnVector(int columnId) {
			this.columnId = columnId;
		}
		
		public V get(int index) {
			return mat.get(index).get(columnId);
		}

		public void put(int index, V value) {
			mat.get(index).add(columnId, value);
		}

		public int length() {
			return rowCount;
		}
	}

}
