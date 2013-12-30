package org.tuxdna.solution;

import java.util.Scanner;

import org.tuxdna.RBT;

public class QuadrantQueries2 {
	public static enum Quadrant {
		FIRST, SECOND, THIRD, FOURTH;
	}

	public static class Point {
		private int x;
		private int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public void setX(int v) {
			x = v;
		}

		public void setY(int v) {
			y = v;
		}

		public int getX() {
			return x;
		}

		public int getY() {
			return y;
		}

		public Quadrant getQuadrant() {
			if (x > 0 && y > 0) {
				return Quadrant.FIRST;
			} else if (x < 0 && y > 0) {
				return Quadrant.SECOND;
			} else if (x < 0 && y < 0) {
				return Quadrant.THIRD;
			} else if (x > 0 && y < 0) {
				return Quadrant.FOURTH;
			}
			return null;
		}
	}

	public static RBT[] quads = new RBT[4];
	static {
		for (int i = 0; i < 4; i++) {
			quads[i] = new RBT();
		}
	}

	public static void reflectX(Point p) {
		p.setY(-p.getY());
	}

	public static void reflectY(Point p) {
		p.setX(-p.getX());
	}

	public static void main(String args[]) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		Point[] points = new Point[N + 1];

		for (int i = 1; i <= N; i++) {
			int x = scanner.nextInt();
			int y = scanner.nextInt();
			points[i] = new Point(x, y);
			Quadrant q = points[i].getQuadrant();
			quads[q.ordinal()].insert(i);
		}

		Quadrant q = null;
		int Q = scanner.nextInt();
		for (int i = 0; i < Q; i++) {
			char tx = scanner.next().charAt(0);
			int I = scanner.nextInt();
			int J = scanner.nextInt();
			// System.out.println(tx + " " + I + " " + J);
			switch (tx) {
			case 'X':
				for (int k = I; k <= J; k++) {
					q = points[k].getQuadrant(); // old quadrant
					quads[q.ordinal()].delete(k);
					reflectX(points[k]);
					q = points[k].getQuadrant(); // new quadrant
					quads[q.ordinal()].insert(k);
				}
				break;
			case 'Y':
				for (int k = I; k <= J; k++) {
					q = points[k].getQuadrant(); // old quadrant
					quads[q.ordinal()].delete(k);
					reflectY(points[k]);
					q = points[k].getQuadrant(); // new quadrant
					quads[q.ordinal()].insert(k);
				}
				break;
			case 'C':
				// count points in each quadrant
				int[] qcount = new int[4]; // {0,0,0,0};
				// for (int k = I; k <= J; k++) {
				// qcount[points[k].getQuadrant().ordinal()]++;
				// }
				for (int qid = 0; qid < 4; qid++) {
					int rI = quads[qid].countLessThan(I);
					int rJ = quads[qid].countLessThan(J);
					System.out.println("[I,J]:[" + I + "," + J + "][ri,rj]:["
							+ rI + "," + rJ + "] ");
					qcount[qid] = quads[qid].size(I, J);
				}
				System.out.println(qcount[0] + " " + qcount[1] + " "
						+ qcount[2] + " " + qcount[3]);
			default: // nothing
				break;
			}
		}
	}
}
