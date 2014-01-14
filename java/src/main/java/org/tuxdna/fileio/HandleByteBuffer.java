package org.tuxdna.fileio;
import java.nio.ByteBuffer;

public class HandleByteBuffer {
	public static void main(String[] args) {
		int maxID = -1;
		ByteBuffer data = null;
		data = ByteBuffer.allocate(0);
		data = ByteBuffer.allocate(maxID * 8);
	}
}
