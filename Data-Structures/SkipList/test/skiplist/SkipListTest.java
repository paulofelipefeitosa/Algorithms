package skiplist;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class SkipListTest {

	private SkipList<Integer> list;

	@Before
	public void setUp() {
		this.list = new SkipList<Integer>();
	}

	@Test
	public void testEmptyList() {
		System.out.println(this.list.toString());
	}

	@Test
	public void testSkipList() {
		Assert.assertFalse(this.list.contains(5));
		this.list.add(5);
		System.out.println(this.list.toString());
		Assert.assertTrue(this.list.contains(5));

		Assert.assertFalse(this.list.contains(1));
		this.list.add(1);
		System.out.println(this.list.toString());
		Assert.assertTrue(this.list.contains(1));

		Assert.assertFalse(this.list.contains(3));
		this.list.add(3);
		System.out.println(this.list.toString());
		Assert.assertTrue(this.list.contains(3));

		Assert.assertFalse(this.list.contains(7));
		this.list.add(7);
		System.out.println(this.list.toString());
		Assert.assertTrue(this.list.contains(7));

		this.list.delete(5);
		System.out.println(this.list.toString());
		Assert.assertFalse(this.list.contains(5));
		this.list.delete(1);
		System.out.println(this.list.toString());
		Assert.assertFalse(this.list.contains(1));
		this.list.delete(7);
		System.out.println(this.list.toString());
		Assert.assertFalse(this.list.contains(7));
		this.list.delete(3);
		System.out.println(this.list.toString());
		Assert.assertFalse(this.list.contains(3));
	}
}
