package skiplist.node;

public class SkipListNode<T extends Comparable<T>> {
	private Integer key;
	private T data;
	private int level;
	private SkipListNode<T>[] forward;

	@SuppressWarnings("unchecked")
	public SkipListNode(Integer key, T data, int level) {
		this.key = key;
		this.data = data;
		this.level = level;
		this.forward = (SkipListNode<T>[]) new SkipListNode[this.level + 1];
	}

	public boolean isEmpty() {
		return this.data == null;
	}

	public Integer getKey() {
		return this.key;
	}

	public T getData() {
		return this.data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public int getLevel() {
		return this.level;
	}

	public SkipListNode<T>[] getForwards() {
		return this.forward;
	}

	public SkipListNode<T> getNextNodeInLevel(int level) {
		SkipListNode<T> result = null;
		if (level <= this.level) {
			result = this.forward[level];
		}
		return result;
	}

	public void putNodeInLevel(SkipListNode<T> node, int level) {
		if (level <= this.level) {
			this.forward[level] = node;
		} else {
			throw new IllegalArgumentException(
					"Node Level: " + this.level + " trying to get Next Node in Level: " + level);
		}
	}

	public String toString() {
		if (this.data == null) {
			return "(NIL)";
		} else {
			return "(" + this.key + "," + data + ")";
		}
	}
}
