package org.tuxdna.collection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class Item {
	public String name;
	public int id;

	public Item(int id, String name) {
		this.id = id;
		this.name = name;
	}

	@Override
	public String toString() {
		return "id: " + id + ", name:" + name;
	}

}

public class ItemCollection<T> implements Iterable<T> {

	private List<T> elements = null;

	private final class ItemIterator<T> implements Iterator<T> {

		Iterator<T> iterator = null;

		public ItemIterator() {
			this.iterator = (Iterator<T>) elements.iterator();
		}

		public boolean hasNext() {
			return this.iterator.hasNext();
		}

		public T next() {
			return this.iterator.next();
		}

		public void remove() {
			// NOP
		}

	}

	public ItemCollection() {
		elements = new ArrayList<T>();
	}

	public void add(T e) {
		elements.add(e);
	}

	public Iterator<T> iterator() {
		return new ItemIterator<T>();
	}

	public static void main(String[] args) {
		ItemCollection<Item> coll = new ItemCollection<Item>();
		coll.add(new Item(0, "zero"));
		coll.add(new Item(1, "one"));
		coll.add(new Item(2, "two"));
		coll.add(new Item(3, "three"));
		for (Item i : coll) {
			System.out.println(i);
		}
	}
}
