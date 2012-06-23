package org.tuxdna;

/**
 * @author tuxdna
 * @see https://tuxdna.wordpress.com/
 */
public class RBT {
	public enum Color {
		RED, BLACK;
	};

	public class Node {
		public int data;
		public Color color;
		public Node left, right;
		public Node parent;
		public int N;

		public Node(int v) {
			initialize();
			data = v;
			N = 1;
		}

		public void initialize() {
			color = Color.BLACK;
			left = right = parent = null;
			N = 0;
		}
	};

	private Node root;

	public RBT() {
		root = null;
	}

	public boolean search(int value) {
		Node h = searchNode(value);
		return h != null;
	}

	private int getNodeHeight(Node h) {
		if (h == null)
			return 0;
		return Math.max(getNodeHeight(h.left), getNodeHeight(h.right)) + 1;
	}

	public int height() {
		return getNodeHeight(root);
	}

	private int size(Node h) {
		if (h == null)
			return 0;
		return h.N;
	}

	// number of nodes between interval [lo, hi]
	public int size(int lo, int hi) {
		int rankLow = 0;
		int rankHigh = 0;

		if (root == null)
			return 0;
		Node k = root, p = null;
		// search for lo
		while (k != null) {
			p = k;
			if (lo < k.data) k = k.left;
			else if (lo > k.data) k = k.right;
			else break;

		}

		// if k is null, we didnt find the lo node
		if (k == null) {
			if (lo < p.data) rankLow = rank(p);
			else rankLow = rank(p) + 1;
		} else {
			rankLow = rank(lo);
		}

		k = root;
		p = null;
		// search for hi
		while (k != null) {
			p = k;
			if (hi < k.data) k = k.left;
			else if (hi > k.data) k = k.right;
			else break;
		}

		// if k is null, we didnt find the hi node
		if (k == null) {
			if (hi < p.data) rankHigh = rank(p) + 1;
			else rankHigh = rank(p);
		} else {
			rankLow = rank(lo);
		}

		return rankHigh - rankLow + 1;
	}

	public int size() {
		return size(root);
	}

	public void print() {
		print(root, 1);
	}

	private void print(Node n, int level) {

	}

	private void print(Node h) {
		if (h != null)
			System.out.print(h.data + "(" + h.color.toString() + ":" + h.N
					+ ") ");
	}

	public Node select(int index) {
		return select(root, index + 1);
	}

	private Node select(Node x, int i) {
		if (x == null)
			return null;

		int r = size(x.left) + 1;
		if (i == r) {
			return x;
		} else if (i < r) {
			return select(x.left, i);
		} else {
			return select(x.right, i - r);
		}
	}

	public int rank(int data) {
		Node n = searchNode(data);
		if (null == n)
			return -1;
		return rank(n) - 1;
	}

	private int rank(Node x) {
		int r = size(x.left) + 1;
		Node y = x;
		while (y != root) {
			if (y == y.parent.right) {
				r = r + size(y.parent.left) + 1;
			}
			y = y.parent;
		}
		return r;
	}

	public void printInorder() {
		printInorderTraversal(root);
	}

	private void printInorderTraversal(Node h) {
		if (h == null)
			return;
		printInorderTraversal(h.left);
		print(h);
		printInorderTraversal(h.right);
	}

	private void printPreorderTraversal(Node h) {
		if (h == null)
			return;
		print(h);
		printPreorderTraversal(h.left);
		printPreorderTraversal(h.right);

	}

	public void printPreorder() {
		printPreorderTraversal(root);
	}

	public void printInPre() {
		System.out.print(" INORDER: ");
		printInorder();
		System.out.println();
		System.out.print(" PREORDER: ");
		printPreorder();
		System.out.println();
	}

	public Node searchNode(int value) {
		Node h = root;
		Node foundNode = null;
		while (h != null) {
			if (value < h.data) {
				h = h.left;
			} else if (value > h.data) {
				h = h.right;
			} else if (value == h.data) {
				foundNode = h;
				break;
			}
		}
		return foundNode;
	}

	public RBT insert(int value) {
		Node y = null;
		Node x = root;
		// search for insert position
		while (x != null) {
			y = x;
			if (value < x.data) {
				x = x.left;
			} else {
				x = x.right;
			}
		}

		// now add a node
		Node z = new Node(value);
		z.parent = y;
		if (y == null) { // empty tree
			root = z;
		} else {
			if (z.data < y.data) {
				y.left = z;
			} else {
				y.right = z;
			}
		}
		z.color = Color.RED;
		if (z.parent != null) {
			Node p = z.parent;
			p.N = size(p.left) + size(p.right) + 1;
		}

		rbInsertFixup(z);
		return this;

	}

	private void rbInsertFixup(Node z) {
		while (getColor(z.parent) == Color.RED) {
			if (!(hasParent(z) && hasParent(z.parent))) {
				break;
			}

			Node p = z.parent;
			p.N = size(p.left) + size(p.right) + 1;

			if (z.parent == z.parent.parent.left) {
				Node y = z.parent.parent.right;
				if (getColor(y) == Color.RED) {
					z.parent.color = Color.BLACK;
					y.color = Color.BLACK;
					z.parent.parent.color = Color.RED;
					z = z.parent.parent;
				} else {
					if (z == z.parent.right) {
						z = z.parent;
						rotateLeft(z);
					}
					z.parent.color = Color.BLACK;
					z.parent.parent.color = Color.RED;
					rotateRight(z.parent.parent);
				}
			} else {
				Node y = z.parent.parent.left;
				if (getColor(y) == Color.RED) {
					z.parent.color = Color.BLACK;
					y.color = Color.BLACK;
					z.parent.parent.color = Color.RED;
					z = z.parent.parent;
				} else {
					if (z == z.parent.left) {
						z = z.parent;
						rotateRight(z);
					}
					z.parent.color = Color.BLACK;
					z.parent.parent.color = Color.RED;
					rotateLeft(z.parent.parent);
				}
			}

			// update subtree size
			z.N = size(z.left) + size(z.right) + 1;
		}

		// walk up the tree
		// update root node and update sub-tree sizes
		while (z != null) {
			// first update root node
			root = z;

			// now update the size
			z.N = size(z.left) + size(z.right) + 1;
			z = z.parent;
		}

		root.color = Color.BLACK;
	}

	public Node delete(int data) {
		// find node containing the search value
		Node z = searchNode(data);
		if (z == null) {
			return null;
		}

		Node y = null;
		if (z.left == null || z.right == null) {
			y = z;
		} else {
			y = treeSuccessor(z);
		}

		Node x = null;
		if (y.left != null) {
			x = y.left;
		} else {
			x = y.right;
		}

		Node xParent = null;
		if (x != null) {
			x.parent = y.parent;
		}
		xParent = y.parent;

		if (y.parent == null) {
			root = x;
		} else {
			if (y == y.parent.left) {
				y.parent.left = x;
			} else {
				y.parent.right = x;
			}
			// update the size
			Node k = y.parent;
			k.N = size(k.left) + size(k.right) + 1;
		}

		if (y != z)
			z.data = y.data; // copy data

		if (getColor(y) == Color.BLACK)
			rbDeleteFixup(x, xParent);

		// update size
		for (Node k = xParent; k != null; k = k.parent) {
			k.N = size(k.left) + size(k.right) + 1;
		}
		return y;
	}

	public Node rbDeleteFixup(Node x, Node xParent) {
		while (x != root && getColor(x) == Color.BLACK) {
			if (xParent == null && x == null) {
				x = root;
				break;
			}
			if (x == xParent.left) {
				Node w = xParent.right;
				if (getColor(w) == Color.RED) {
					w.color = Color.BLACK;
					xParent.color = Color.RED;
					rotateLeft(xParent);
					w = xParent.right;
				}
				if (getColor(w.left) == Color.BLACK
						&& getColor(w.right) == Color.BLACK) {
					w.color = Color.RED;
					x = xParent;
					xParent = x.parent;
				} else {
					if (getColor(w.right) == Color.BLACK) {
						w.left.color = Color.BLACK;
						w.color = Color.RED;
						rotateRight(w);
						w = xParent.right;
					}
					w.color = xParent.color;
					xParent.color = Color.BLACK;
					if (w.right != null)
						w.right.color = Color.BLACK;
					rotateLeft(xParent);
					x = root;
				}
			} else {
				Node w = xParent.left;
				if (getColor(w) == Color.RED) {
					w.color = Color.BLACK;
					xParent.color = Color.RED;
					rotateRight(xParent);
					w = xParent.left;
				}
				if (getColor(w.right) == Color.BLACK
						&& getColor(w.left) == Color.BLACK) {
					w.color = Color.RED;
					x = xParent;
					xParent = x.parent;
				} else {
					if (getColor(w.left) == Color.BLACK) {
						w.right.color = Color.BLACK;
						w.color = Color.RED;
						rotateLeft(w);
						w = xParent.left;
					}
					w.color = xParent.color;
					xParent.color = Color.BLACK;
					if (w.left != null)
						w.left.color = Color.BLACK;
					rotateRight(xParent);
					x = root;
				}
			}
			xParent = x.parent;
			Node z = x;
			z.N = size(z.left) + size(z.right) + 1;
		}

		// walk up the tree and update sub-tree sizes
		Node z = x;
		while (z != null) {
			// now update the size
			z.N = size(z.left) + size(z.right) + 1;
			z = z.parent;
		}

		if (x != null)
			x.color = Color.BLACK;
		return x;
	}

	private Color getColor(Node n) {
		if (null == n) {
			return Color.BLACK;
		}
		return n.color;
	}

	boolean hasParent(Node n) {
		return (n != null) && (n.parent != null);
	}

	public Node treeMinimum(Node x) {
		while (x.left != null) {
			x = x.left;
		}
		return x;
	}

	public Node treeSuccessor(Node x) {
		if (x.right != null) {
			return treeMinimum(x.right);
		}
		Node y = x.parent;
		while (y != null && y.right == x) {
			x = y;
			y = y.parent;
		}
		return y;
	}

	public void rotateLeft(Node x) {
		Node y = x.right;
		x.right = y.left;
		if (y.left != null) {
			y.left.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) {
			root = y;
		} else {
			if (x == x.parent.left) {
				x.parent.left = y;
			} else {
				x.parent.right = y;
			}

		}
		y.left = x;
		x.parent = y;

		// update node sizes
		y.N = x.N;
		x.N = size(x.left) + size(x.right) + 1;
	}

	public void rotateRight(Node x) {
		Node y = x.left;
		x.left = y.right;
		if (y.right != null) {
			y.right.parent = x;
		}
		y.parent = x.parent;
		if (x.parent == null) {
			root = y;
		} else {
			if (x == x.parent.left) {
				x.parent.left = y;
			} else {
				x.parent.right = y;
			}

		}
		y.right = x;
		x.parent = y;

		// update node sizes
		y.N = x.N;
		x.N = size(x.left) + size(x.right) + 1;
	}

	public int checkBlackHeight() {
		return checkBlackHeight(root);
	}

	// returns the black height of the tree
	// returns -1 if the black height is not same for all leaf nodes
	public int checkBlackHeight(Node n) {
		if (n == null) {
			return 1;
		}
		int hl = checkBlackHeight(n.left);
		int hr = checkBlackHeight(n.right);
		if (hl == -1 || hr == -1)
			return -1;
		if (hl == hr) {
			return hl + ((getColor(n)) == Color.BLACK ? 1 : 0);
		} else {
			return -1;
		}
	}

	public boolean isRedValid() {
		return isRedValid(root);
	}

	private boolean isRedValid(Node n) {
		if (n == null) {
			return true;
		}

		Color c = getColor(n);
		if (c == Color.RED) {
			Color leftColor = getColor(n.left);
			Color rightColor = getColor(n.right);
			if (leftColor == Color.RED || rightColor == Color.RED) {
				return false;
			}
		}
		return isRedValid(n.left) && isRedValid(n.right);

	}

	public static void main(String args[]) {
		RBT tree = new RBT();
		int N = 100000;
		int MAX = 300000000;
		int array[] = new int[N];
		System.out.println("Inserting values:");
		int value = 0;
		for (int i = 0; i < N; i++) {
			value = (int) (Math.random() * MAX);
			array[i] = value;
		}
		for (int i = 0; i < N; i++) {
			value = array[i];
			tree.insert(value);
		}
		System.out.println(" DONE");
		System.out.println("Deleting values:");
		for (int i = 0; i < N; i++) {
			value = array[i];
			tree.delete(value);
			// if (!tree.isRedValid() && tree.checkBlackHeight() == -1) {
			// throw new RuntimeException("Deletion failed");
			// }
			// if (tree.size() != N-i-1 ) {
			// throw new RuntimeException("Tree size is wrong!");
			// }
		}
		System.out.println(" DONE");
	}
}
