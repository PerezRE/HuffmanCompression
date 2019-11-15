#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "HuffmanTree.hpp"

HuffmanTree::HuffmanTree(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& queue) {
	// Mientras que haya más de un nodo en la cola:
	while (queue.size() > 1) {
		Node *n = queue.top();
		queue.pop();
		Node *m = queue.top();
		queue.pop();
		Node* _new = new Node('*');
        _new->set_freq(n->get_freq() + m->get_freq());
		_new->set_left(*n); // El menor va a la izq.
		_new->set_right(*m); // El mayor va a la der.
		queue.push(_new);
	}
	// Quedó el nodo con la mayor frecuencia en la cola de prioridad, debido a la condición del while.
	// Entonces solo queda tomar dicho nodo, que será la raíz de nuestro árbol.
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

void HuffmanTree::preorder(std::map<char, std::string> &coded) const {
	std::string str;
	preorder(root, coded, str);
}