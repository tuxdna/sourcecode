package org.tuxdna.fileio;
import java.io.RandomAccessFile;

class Account2 {
  private long position;
  
  public Account2(String l, long p) {
    // super(l);
    position = p;
  }
  
  public void saveFile() {
    try {
      RandomAccessFile raf = new RandomAccessFile("/tmp/sample.txt", "rw");
      raf.seek(position);
      String newContents = "my new contents here";
      // raf.writeChars(newContents.toString());
      raf.writeUTF(newContents);
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}

public class Raf {
  
  public static void main(String[] args) {
    Account2[] members = new Account2[10];
    try {
      RandomAccessFile raf = new RandomAccessFile("/tmp/sample.txt", "r");
      raf.seek(0);
      long position = raf.getFilePointer();
      int counter = 0;
      while (raf.length() > position) {
        members[counter] = new Account2(raf.readLine(), position);
        position = raf.getFilePointer();
        counter++;
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
  
}
