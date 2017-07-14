#include <bits/stdc++.h>
using namespace std;
int consump(int bill);
int bill_value(int consume);
int main()
{
	int a, b;
	int lb, ub, mid;
	int cons_a, cons_b, tot, pay_a, pay_b, diff;
	while(scanf("%d %d", &a, &b), a || b)
	{
		lb = 0; ub = tot = consump(a);
		while(lb <= ub)
		{
			mid = (lb + ub)>>1;
			cons_b = tot - mid;
			if(mid > cons_b)
			{
				ub = mid - 1;
				continue;
			}
			pay_a = bill_value(mid);
			pay_b = bill_value(cons_b);
			diff = pay_b - pay_a;
			if(diff < b)
				ub = mid - 1;
			else if(diff > b)
				lb = mid + 1;
			else
				break;
		}
		printf("%d\n", pay_a);
	}
	return 0;
}
int consump(int bill)
{
	int cwh = 0;
	if(bill > 200)
	{
		cwh = 100;
		bill -= 200;
	}
	else
		return (bill>>1);
	if(bill > 29700)
	{
		cwh = 10000;
		bill -= 29700;
	}
	else
		return cwh + (bill/3);
	if(bill > 4950000)
	{
		cwh = 1000000;
		bill -= 4950000;
	}
	else
		return cwh + (bill/5);
	return cwh + (bill/7);
}
int bill_value(int consume)
{
	int value = 0;
	if(consume > 100)
	{
		value = 200;
		consume -= 100;
	}
	else
		return consume<<1;
	if(consume > 9900)
	{
		value = 29900;
		consume -= 9900;
	}
	else
		return value + (consume*3);
	if(consume > 990000)
	{
		value = 4979900;
		consume -= 990000;
	}
	else
		return value + (consume*5);
	return value + (consume*7);
}
