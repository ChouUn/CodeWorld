
template <typename _Tp>
struct Leftist_Tree
{
public	:
	typedef Leftist_Tree<_Tp>		_Self;
	typedef _Tp						value_type;
	typedef _Tp *					pointer;
	typedef _Tp &					reference;
	
public	:
	value_type data;
	int dist;
	_Self* left;
	_Self* right;
	_Self* root;
	
public	:
	Leftist_Tree(value_type __data)
	: data(__data), dist(), left(), right(), root() { }
	
public	:
	static _Self*
	merge(_Self* a, _Self* b) 
	{
		if (!(a && b)) return a ? a : b;
		if (a->data > b->data) swap(a, b);
		a->right = merge(a->right, b);
		a->right->root = a;
		if ((!a->left) || a->right->dist > a->left->dist) swap(a->left, a->right);
		a->dist = (a->right) ? (a->right->dist + 1) : (0);
		return a;
	}

	static void
	insert(_Self* &a, _Self* b)
	{
		a = merge(a, b);
	}

	static void
	erase(_Self* __node)
	{
		merge(__node->left, __node->right)->root = 0;
		(*__node) = _Self(__node->data);
	}
	
	_Self*
	find()
	{
		while (root) __node = root;
		return __node;
	}
	
};

int main() {
	
	return 0;
}
