package org.tuxdna;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class GenericBST<T extends Comparable<T>> {
	class Node {
		T data;
		public Node left;
		public Node right;

		public Node(T data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}

	// first implement a basic BST
	// insert : DONE
	// delete : DONE
	// find : DONE

	private Node root;

	public GenericBST() {
		root = null;
	}

	public void insert(T v) {
		root = insert(root, v);
	}

	private Node insert(Node tree, T v) {
		if (null == tree)
			return new Node(v);
		int cmp = v.compareTo(tree.data);
		if (cmp < 0)
			tree.left = insert(tree.left, v);
		else
			tree.right = insert(tree.right, v);
		return tree;
	}

	public T min() {
		Node n = min(root);
		if (n == null)
			return null;
		return n.data;
	}

	private Node min(Node node) {
		if (node.left == null)
			return node;
		else
			return min(node.left);
	}

	// return the node which we get after deleting a node with minimum value in
	// the subtree
	private Node deleteMin(Node node) {
		assert (node != null);
		if (node.left == null)
			return node.right;
		node.left = deleteMin(node.left);
		return node;
	}

	public void delete(T v) {
		root = delete(root, v);
	}

	public Node delete(Node node, T v) {
		if (node == null)
			return null;
		int cmp = v.compareTo(node.data);
		if (cmp < 0)
			node.left = delete(node.left, v);
		else if (cmp > 0)
			node.right = delete(node.right, v);
		else {
			if (null == node.left)
				return node.right;
			if (null == node.right)
				return node.left;
			Node t = node; // back up the deleted node
			node = min(t.right);
			node.right = deleteMin(t.right);
			node.left = t.left;
		}
		return node;
	}

	public boolean find(T v) {
		return find(root, v) != null;
	}

	private Node find(Node node, T v) {
		if (null == node) {
			return null;
		}
		int cmp = v.compareTo(node.data);
		if (cmp < 0) {
			return find(node.left, v);
		}
		if (cmp > 0) {
			return find(node.right, v);
		}
		return node;
	}

	public List<T> inorder() {
		List<T> list = new ArrayList<T>();
		inorder(root, list);
		return list;
	}

	private void inorder(Node node, List<T> list) {
		if (null == node)
			return;
		inorder(node.left, list);
		// System.out.println(node.data + " ");
		list.add(node.data);
		inorder(node.right, list);
	}

	public static void p(String s) {
		System.out.print(s);
	}

	public static void pln(String s) {
		System.out.println(s);
	}

	public static void pln() {
		System.out.println("");
	}

	public static void printList(List<?> l) {
		for (Object i : l) {
			p(i + " ");
		}
		pln();
	}
	
	public static void main(String[] argv) {
		testIntegers();
		testStrings();
		
	}
	public static void testStrings() {
		GenericBST<String> tree = new GenericBST<String>();
		RandomString randomString = new RandomString(10);
		Random random = new Random();
		String[] values = new String[10];
		for (int i = 0; i < 10; i++) {
			String v = values[i] = randomString.nextString();
			p(v + " ");
			tree.insert(v);
		}

		pln();
		pln("Inorder Traversal:");
		printList(tree.inorder());

		for (int i = 0; i < 10; i++) {
			String nextval = values[random.nextInt(10)];
			p("Deleting: " + nextval + " ");
			if (tree.find(nextval)) {
				pln("Node FOUND!");
			} else {
				pln("Node NOT found");
			}
			tree.delete(nextval);
			p("Inorder Traversal: ");
			printList(tree.inorder());
			pln();
		}
	}	
	public static void testIntegers() {
		GenericBST<Integer> tree = new GenericBST<Integer>();
		Random random = new Random();
		int[] values = new int[10];
		for (int i = 0; i < 10; i++) {
			int v = values[i] = random.nextInt(100);
			p(v + " ");
			tree.insert(v);
		}

		pln();
		pln("Inorder Traversal:");
		printList(tree.inorder());

		for (int i = 0; i < 10; i++) {
			int nextval = values[random.nextInt(10)];
			p("Deleting: " + nextval + " ");
			if (tree.find(nextval)) {
				pln("Node FOUND!");
			} else {
				pln("Node NOT found");
			}
			tree.delete(nextval);
			p("Inorder Traversal: ");
			printList(tree.inorder());
			pln();
		}
	}
}
