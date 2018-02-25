package skiplist;

import skiplist.node.SkipListNode;

public class SkipList<T extends Comparable<T>> {
	private static final int MAX_LEVEL = 20; // supports N < 2^20
	private static final double p = 0.5; // probability

	private SkipListNode<T> head;
	private SkipListNode<T> tail;

	public SkipList() {
		this.head = new SkipListNode<T>(Integer.MIN_VALUE, null, SkipList.MAX_LEVEL);
		this.tail = new SkipListNode<T>(Integer.MAX_VALUE, null, SkipList.MAX_LEVEL);

		for (int i = 0; i <= SkipList.MAX_LEVEL; i++) {
			this.head.putNodeInLevel(this.tail, i);
		}
	}

	private SkipListNode<T>[] getPath(Integer elementKey) {
		@SuppressWarnings("unchecked")
		SkipListNode<T>[] updateList = (SkipListNode<T>[]) new SkipListNode[SkipList.MAX_LEVEL + 1];
		SkipListNode<T> traversingNode = this.head;
		for (int actualLevel = SkipList.MAX_LEVEL; actualLevel >= 0; actualLevel--) {
			SkipListNode<T> nextNodeInLevel = traversingNode.getNextNodeInLevel(actualLevel);
			while (nextNodeInLevel.getKey() < elementKey) {
				traversingNode = nextNodeInLevel;
				nextNodeInLevel = traversingNode.getNextNodeInLevel(actualLevel);
			}
			updateList[actualLevel] = traversingNode;
		}
		return updateList;
	}

	public void add(T element) {
		Integer elementKey = element.hashCode();
		SkipListNode<T>[] updateList = this.getPath(elementKey);
		SkipListNode<T> node = updateList[0].getNextNodeInLevel(0);

		if (node.getKey() == elementKey) {
			node.setData(element);
		} else {
			int newNodeLevel = this.getRandomLevel();
			SkipListNode<T> newNode = new SkipListNode<T>(elementKey, element, newNodeLevel);
			for (int lvl = 0; lvl <= newNodeLevel; lvl++) {
				SkipListNode<T> leftNodeInLevel = updateList[lvl];
				newNode.putNodeInLevel(leftNodeInLevel.getNextNodeInLevel(lvl), lvl);
				leftNodeInLevel.putNodeInLevel(newNode, lvl);
			}
		}
	}

	public void delete(T element) {
		Integer elementKey = element.hashCode();
		SkipListNode<T>[] updateList = this.getPath(elementKey);
		SkipListNode<T> node = updateList[0].getNextNodeInLevel(0);

		if (node.getKey() == elementKey) {
			for (int lvl = 0; lvl <= SkipList.MAX_LEVEL
					&& updateList[lvl].getNextNodeInLevel(lvl) == node; lvl++) {
				updateList[lvl].putNodeInLevel(node.getNextNodeInLevel(lvl), lvl);
			}
		}
	}

	public boolean contains(T element) {
		boolean result = false;
		Integer elementKey = element.hashCode();
		SkipListNode<T>[] path = this.getPath(elementKey);
		SkipListNode<T> traversingNode = path[0].getNextNodeInLevel(0);
		if (traversingNode.getKey() == elementKey && !traversingNode.isEmpty()
				&& traversingNode.getData().equals(element)) {
			result = true;
		}
		return result;
	}

	public String toString() {
		String result = new String();
		for (int lvl = SkipList.MAX_LEVEL; lvl >= 0; lvl--) {
			for (SkipListNode<T> node = this.head; node != this.tail; node = node
					.getNextNodeInLevel(lvl)) {
				result += node.toString() + " -> ";
			}
			result += this.tail.toString() + System.lineSeparator();
		}
		return result;
	}

	private int getRandomLevel() {
		int level = 0;
		while (Math.random() < SkipList.p && level < SkipList.MAX_LEVEL) {
			level++;
		}
		System.out.println("Level: " + level);
		return level;
	}
}
