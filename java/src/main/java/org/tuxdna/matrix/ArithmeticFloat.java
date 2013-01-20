package org.tuxdna.matrix;

public class ArithmeticFloat extends Number implements IArithmetic<Float> {

	private static final long serialVersionUID = 1L;

	private Float v;

	public ArithmeticFloat(float v) {
		this.v = v;
	}

	public void add(Float a) {
		v += a;
	}

	public void sub(Float a) {
		v -= a;
	}

	public void mulBy(Float a) {
		v *= a;
	}

	public void divBy(Float a) {
		v /= a;
	}

	@Override
	public double doubleValue() {
		return (double) v;
	}

	@Override
	public float floatValue() {
		return v;
	}

	@Override
	public int intValue() {
		return (int) (float) v;
	}

	@Override
	public long longValue() {
		return (long) (float) v;
	}
	
	@Override
	public String toString() {
		return v.toString();
	}
}
