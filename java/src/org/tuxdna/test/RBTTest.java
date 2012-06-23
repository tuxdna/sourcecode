package org.tuxdna.test;

import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Test;
import org.tuxdna.RBT;

public class RBTTest {

	@Test
	public void testInsert() {
		RBT tree = new RBT();
		// RBT.Node node = null;
		tree.insert(1);
		assertTrue(-1 != tree.checkBlackHeight());
		assertEquals(tree.searchNode(1).color, RBT.Color.BLACK);

		tree.insert(2);
		assertTrue(-1 != tree.checkBlackHeight());

		assertEquals(tree.searchNode(2).color, RBT.Color.RED);

		tree.insert(3);
		assertTrue(-1 != tree.checkBlackHeight());

		assertEquals(tree.searchNode(1).color, RBT.Color.RED);
		assertEquals(tree.searchNode(2).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(3).color, RBT.Color.RED);

		tree.insert(4);
		assertTrue(-1 != tree.checkBlackHeight());

		assertEquals(tree.searchNode(1).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(2).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(3).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(4).color, RBT.Color.RED);

		tree.insert(5);
		assertTrue(-1 != tree.checkBlackHeight());

		assertEquals(tree.searchNode(1).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(2).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(3).color, RBT.Color.RED);
		assertEquals(tree.searchNode(4).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(5).color, RBT.Color.RED);

		tree.insert(7);
		assertTrue(-1 != tree.checkBlackHeight());

		assertEquals(tree.searchNode(7).color, RBT.Color.RED);
		assertEquals(tree.searchNode(5).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(4).color, RBT.Color.RED);
		assertEquals(tree.searchNode(3).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(2).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(1).color, RBT.Color.BLACK);

		tree.insert(6);
		assertTrue(-1 != tree.checkBlackHeight());
		assertEquals(tree.searchNode(6).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(7).color, RBT.Color.RED);
		assertEquals(tree.searchNode(5).color, RBT.Color.RED);
		assertEquals(tree.searchNode(4).color, RBT.Color.RED);
		assertEquals(tree.searchNode(3).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(2).color, RBT.Color.BLACK);
		assertEquals(tree.searchNode(1).color, RBT.Color.BLACK);

		tree.delete(2);
		assertTrue(-1 != tree.checkBlackHeight());
	}

	@Test
	public void testInsertDelete() {
		RBT tree = new RBT();
		tree.insert(218);
		tree.insert(61);
		tree.insert(57);
		tree.insert(163);
		tree.insert(296);
		tree.insert(216);
		tree.insert(79);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
		tree.delete(218);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());

	}

	@Test
	public void testInsertDeleteOne() {
		RBT tree = new RBT();
		tree.insert(2);
		tree.insert(1);
		tree.insert(3);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
		tree.delete(3);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
		tree.delete(2);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
		tree.delete(1);
		assertTrue(tree.isRedValid());
		assertTrue(-1 != tree.checkBlackHeight());
	}

	@Test
	public void testDeleteLeftRight() {
		RBT tree = new RBT();
		int array[] = { 288, 101, 84, 222, 125, 63, 275, 143 };
		for (int i = 0; i < array.length; i++) {
			tree.insert(array[i]);
		}

		Arrays.sort(array);
		for (int low = 0, high = array.length - 1; low < high;) {
			// System.out.println("Deleting: " + array[low]);
			tree.delete(array[low]);
			// tree.printInPre();
			low++;
			assertTrue(tree.isRedValid());
			assertTrue(-1 != tree.checkBlackHeight());
			if (low > high)
				break;
			// System.out.println("Deleting: " + array[high]);
			tree.delete(array[high]);
			// tree.printInPre();
			high--;
			assertTrue(tree.isRedValid());
			assertTrue(-1 != tree.checkBlackHeight());
		}
	}

	@Test
	public void testDeleteLeftRightDuplicateKeys() {
		RBT tree = new RBT();
		int array[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		for (int i = 0; i < array.length; i++) {
			tree.insert(array[i]);
		}

		Arrays.sort(array);
		for (int low = 0, high = array.length - 1; low < high;) {
			// System.out.println("Deleting: " + array[low]);
			tree.delete(array[low]);
			// tree.printInPre();
			low++;
			assertTrue(tree.isRedValid());
			assertTrue(-1 != tree.checkBlackHeight());
			if (low > high)
				break;
			// System.out.println("Deleting: " + array[high]);
			tree.delete(array[high]);
			// tree.printInPre();
			high--;
			assertTrue(tree.isRedValid());
			assertTrue(-1 != tree.checkBlackHeight());
		}
	}

	@Test
	public void testTreeSizeAtInsert() {
		int a[] = { 50, 25, 15, 10, 5, 35, 40, 45, 20, 47, 48 };
		RBT tree = new RBT();
		for (int i = 0; i < a.length; i++) {
			//System.out.println("Inserting: " + a[i]);
			tree.insert(a[i]);
			//tree.printInPre();
			assertTrue(tree.size() == i + 1);
		}
	}

	@Test
	public void testTreeSizeAtDelete() {
		int a[] = { 9, 25, 26, 6, 13, 1, 3, 8, 25, 20};
		RBT tree = new RBT();
		for (int i = 0; i < a.length; i++) {
			tree.insert(a[i]);
		}
		for (int i = 0; i < a.length; i++) {
			//System.out.println("Deleting: " + a[i]);
			tree.delete(a[i]);
			//tree.printInPre();
			if (!tree.isRedValid() && tree.checkBlackHeight() == -1) {
				throw new RuntimeException("Deletion failed");
			}
			if (tree.size() != a.length-i-1 ) {
				//System.out.println("                       >> Tree size is wrong!");
				throw new RuntimeException("Tree size is wrong!");
			}
		}
	}

	@Test
	public void testRank() {
		RBT tree = new RBT();
		// RBT.Node node = null;
		tree.insert(1);
		assertEquals(tree.rank(1), 0);

		tree.insert(2);
		assertEquals(tree.rank(2), 1);

		tree.insert(3);
		assertEquals(tree.rank(3), 2);

		tree.insert(4);
		assertEquals(tree.rank(4), 3);

		tree.insert(5);
		assertEquals(tree.rank(5), 4);
		tree.insert(7);
		assertEquals(tree.rank(7), 5);
		tree.insert(6);
		assertEquals(tree.rank(6), 5);
		assertEquals(tree.rank(7), 6);
		
		tree.delete(2);
		assertEquals(tree.rank(3), 1);

		assertEquals(tree.rank(16), -1);
	}

	@Test
	public void testSelect() {
		int a[] = { 50, 25, 15, 10, 5, 35, 40, 45, 20, 47, 48 };
		RBT tree = new RBT();
		for (int i = 0; i < a.length; i++) {
			tree.insert(a[i]);
		}
		assertEquals(tree.select(16), null);
		assertEquals(tree.select(0).data, 5);
		assertEquals(tree.select(1).data, 10);
		assertEquals(tree.select(2).data, 15);
		assertEquals(tree.select(3).data, 20);
		assertEquals(tree.select(4).data, 25);
		assertEquals(tree.select(5).data, 35);
		assertEquals(tree.select(6).data, 40);
		assertEquals(tree.select(7).data, 45);
		assertEquals(tree.select(8).data, 47);
		assertEquals(tree.select(9).data, 48);
		assertEquals(tree.select(10).data, 50);
	}
}
