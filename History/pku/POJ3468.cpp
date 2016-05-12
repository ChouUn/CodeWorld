/*
 *	Name : POJ3468.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年3月6日 下午8:18:22
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */
#include <standard.h>
#include <Segmtree.h>

struct segm_node {
	typedef segm_node	_Self;
	Int64 val, sum, num;

	segm_node()
	: val(), sum(), num() { }
	segm_node(Int64 __val, Int64 __sum, Int64 __num)
	: val(__val), sum(__sum), num(__num) { }

	static _Self init(const size_t n) {
		int in; scanf("%d", &in);
		return _Self(in, in, 1);
	}
	static _Self merge(const _Self& a, const _Self& b) {
		return _Self(0, a.sum + b.sum, a.num + b.num);
	}
	void update(const _Self& other) {
		val += other.val;
		sum += other.val * num;
	}
};

int main() {
	int n, m; cin >> n >> m;

	Segmtree<segm_node> f;
	f.resize(n);

	while (m--) {
		char order = 0;
		for (; order != 'C' && order != 'Q'; order = getchar());
		int a, b, c;
		switch (order) {
			case 'Q' :
				scanf("%d%d", &a, &b);
				printf(FMT "\n", f.get(a, b).sum);
				break;
			case 'C' :
				scanf("%d%d%d", &a, &b, &c);
				f.set(a, b, segm_node(c, 0, 0));
				break;
		}
	}
	return 0;
}
