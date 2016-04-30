/*
 *	Name : trie.cpp
 *	Author : CHN.ChouUn
 *	Date : 2015年4月14日 上午1:24:17
 *	Copyright : www.fateud.com
 *	Email : ChouUnSoft@gmail.com
 *	Description : None
 */

//@ Including Header
#include <string.h>
#include <stdio.h>
//@ Program Begin

//@ trie 字典树
namespace trie
{
	const static int MAX_LETTER = 26;

	struct node
	{
		node* next[MAX_LETTER];
		int data;
		node() : data() { memset(next, 0x00, sizeof(next)); }
	};

	template <typename _Node, typename _BiOp>
	inline void
	insert(_Node* root, int& size, char* word, int data, _BiOp opt)
	{
		_Node* prev = root;
		for (; *word; ++word) {
			int ch = (*word) - 1;
			if (!prev->next[ch]) {
				_Node* temp = root + (size++); (*temp) = _Node();
				prev->next[ch] = static_cast<node*>(temp);
			}
			prev = static_cast<_Node*>(prev->next[ch]);
		}
		prev->data = opt(prev->data, data);
	}

} // namespace trie
