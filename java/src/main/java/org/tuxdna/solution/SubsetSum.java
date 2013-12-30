package org.tuxdna.solution;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SubsetSum {

	private int s[], target;

	public SubsetSum(int s[], int value) {
		this.s = s;
		this.target = value;
	}

	public boolean subsetSum(int sum, int i, List<Integer> rv) {
		if (i >= s.length)
			return false;
		if(sum == this.target)
			return true;
		int t = sum + s[i];
		if(subsetSum(t, i+1, rv)) {
			rv.add(i);
			return true;
		}
		if(subsetSum(sum, i+1, rv)) {
			return true;
		}
		return false;
	}

	public static void main(String[] args) {
		int set[] = { 1, 2, 3, 4, 5, 9, 2 };
		int target = 12;
		
		SubsetSum ss = new SubsetSum(set, target);
		List<Integer> l = new ArrayList<Integer>();
		boolean hasSubset = ss.subsetSum(0, 0, l);
		if(hasSubset) {
			Collections.reverse(l);
			for(Integer i: l) {
				System.out.println(set[i]);
			}
		}
	}

}
