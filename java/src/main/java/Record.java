class Record {
	// structure
	int key;
	int count;

	// constructors
	public Record(int keyInput, int countInput) {
		key = keyInput;
		count = countInput;
	}

	public Record(int keyInput) {
		key = keyInput;
		count = 1;
	}
} // end of class Record