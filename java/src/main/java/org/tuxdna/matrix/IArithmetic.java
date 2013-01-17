package org.tuxdna.matrix;

public interface IArithmetic <V extends Number> {
	void add(V a);
	void sub(V a);
	void mulBy(V a);
	void divBy(V a);
}
