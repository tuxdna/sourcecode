package org.tuxdna.matrix;

import junit.framework.TestCase;
import org.apache.log4j.Logger;
import org.tuxdna.matrix.ArithmeticFloat;
import org.tuxdna.matrix.ArrayDenseMatrix;
import org.tuxdna.matrix.IMatrix;
import org.tuxdna.matrix.IVector;

/**
 * @author tuxdna@gmail.com
 * 
 */
public class ArrayDenseMatrixText extends TestCase {

	private static Logger logger = Logger.getLogger(ArrayDenseMatrixText.class);

	public void test1() {
		int rows = 3, columns = 5;
		IMatrix<ArithmeticFloat> mat = new ArrayDenseMatrix<ArithmeticFloat>(3,
				5);
		for (int r = 0; r < rows; r++)
			for (int c = 0; c < columns; c++)
				mat.put(r, c, new ArithmeticFloat((float) (r*rows + c)));
		
		IVector<ArithmeticFloat> rowVec = mat.getRowVector(0);
		for(int i=0; i< rowVec.length(); i++) {
			ArithmeticFloat v = rowVec.get(i);
			System.out.print(v);
			v.add((float) 1);
			System.out.print("  " + v);
			v.mulBy((float) -3);
			System.out.print("  " + v);
			v.divBy((float) 3);
			System.out.print("  " + v);
			v.sub((float) 1);
			System.out.println("  "+v);
		}

		IVector<ArithmeticFloat> colVec = mat.getColumnVector(0);
		for(int i=0; i< colVec.length(); i++) {
			ArithmeticFloat v = colVec.get(i);
			System.out.print(v);
			v.add((float) 1);
			System.out.print("  " + v);
			v.mulBy((float) -3);
			System.out.print("  " + v);
			v.divBy((float) 3);
			System.out.print("  " + v);
			v.sub((float) 1);
			System.out.println("  "+v);
		}

	}

}
