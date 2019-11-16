#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& queue) {
	// While the queue has more than one element
	while (queue.size() > 1) {
		Node *n = queue.top();
		queue.pop();
		Node *m = queue.top();
		queue.pop();
		Node* _new = new Node('*');
        _new->set_freq(n->get_freq() + m->get_freq());
		_new->set_left(*n); // The smaller goes to the left
		_new->set_right(*m); // The greater goes to the right.
		queue.push(_new);
	}
	// The last item in the queue is the root of the tree.
	root = queue.top();
	queue.pop();
}

HuffmanTree::~HuffmanTree() {
	postorder(root, [](Node* n) { delete n; });
}

void HuffmanTree::postorder(Node* n, void(*fn)(Node*)) {
	if (!n)
		return;
	postorder(n->get_left(), fn);
	postorder(n->get_right(), fn);
	fn(n);
}

void HuffmanTree::preorder(Node *n, std::map<char, std::string> &coded, std::string str) const {
	if (n == NULL)
		return;
	if (n->get_data() != '*')
		coded[n->get_data()] = str;
	preorder(n->get_left(), coded, str + "0");
	preorder(n->get_right(), coded, str + "1");
}

void HuffmanTree::encode(std::map<char, std::string> &coded) const {
	std::string str;
	preorder(root, coded, str);
}

std::string HuffmanTree::decode(const std::string& coded_message) const {
	if (!root)
		return "There is no compressed code";
	std::string message;
	Node *current_node = root;
	for (const char &bit : coded_message) {
		if (bit == '1')
			current_node = current_node->get_right();
		else
			current_node = current_node->get_left();
		if (current_node->is_leaf()) {
			message += current_node->get_data();
			current_node = root;
		}
	}
	return message;
}