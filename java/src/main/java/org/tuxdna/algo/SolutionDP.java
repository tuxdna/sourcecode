package org.tuxdna.algo;
import java.util.BitSet;
import java.util.Scanner;

/**
 * Given a number N and binary digits d(0) to d(N-1)
 * 
 * Also a flip(L, R) operation which flips/toggles all the bits from d(L) to d(R).
 * 
 * Find maximum number of ones that can be obtained on any one single flip operation.
 * 
 * Example Input: N = 8, d = (10010010)
 * 
 * Output: Max ones = 6
 */
public class SolutionDP {
  static int table[][] = null;
  static boolean verbose = true;
  
  private static String bstostring(BitSet set, int N) {
    StringBuilder sb = new StringBuilder();
    sb.append("{");
    for (int i = 0; i < N; i++) {
      if (set.get(i)) {
        sb.append("1,");
      } else {
        sb.append("0,");
      }
    }
    sb.append("}");
    return sb.toString();
  }
  
  private static int countFlippedOnesOriginal(BitSet set, int l, int r, int N) {
    int c = 0;
    for (int i = 0; i <= N; i++) {
      if (l <= i && i <= r) {
        // false -> flipped one
        if (!set.get(i)) c++;
      } else if (set.get(i)) c++;
    }
    return c;
  }
  
  private static int countFlippedOnes(BitSet set, int l, int r, int N) {
    int c = 0;
    for (int i = 0; i <= N; i++) {
      if (l <= i && i <= r) {
        // false -> flipped one
        if (!set.get(i)) c++;
      } else if (set.get(i)) {
        // c++;
      }
    }
    return c;
  }
  
  private static void cof(BitSet set, int l, int r, int N, int level) {
    if (l == r) {
      table[l][r] = countFlippedOnes(set, l, r, N);
    } else {
      for (int p = l; p < r; p++) {
        // left
        if (table[l][p] == -1) cof(set, l, p, N, level + 1);
        int left = table[l][p];
        
        // right
        if (table[p + 1][r] == -1) cof(set, p + 1, r, N, level + 1);
        int right = table[p + 1][r];
        table[l][r] = left + right;
      }
    }
    if (verbose) {
      for (int i = 0; i < level; i++) {
        System.out.print(" ");
      }
      System.out.println("on (" + l + "," + r + ") => " + table[l][r]);
    }
  }
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    BitSet digits = new BitSet(N);
    
    for (int i = 0; i < N; i++) {
      int bit = sc.nextInt();
      // set the bit
      if (bit == 1) digits.set(i);
    }
    
    // logic for range in which we get max 1s
    if (verbose) System.out.println("on (_,_) -> " + bstostring(digits, N));
    
    int S = 0;
    table = new int[N][N];
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        table[i][j] = -1;
      }
    }
    
    cof(digits, 0, N - 1, N, 0);
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        System.out.printf("%3d", table[i][j]);
        S = Math.max(S, table[i][j]);
      }
      System.out.println();
    }
    sc.close();
    
    System.out.println(S);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        
        int a = 0, b = i - 1;
        int c = j + 1, d = N - 1;
        
        int originalL = (b > 0) ? (b - a + 1) - table[a][b] : 0;
        int originalR = (d < N && c < N) ? (d - c + 1) - table[c][d] : 0;
        int fullCount = originalL + table[i][j] + originalR;
        System.out.printf("%3d", fullCount);
      }
      System.out.println();
    }
    
  }
}
