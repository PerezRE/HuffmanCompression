#include <iostream>
#include "Node.hpp"

using namespace std;

Node::Node() {
	freq = 0;
	_char = ' ';
	left = right = nullptr;
}

Node::Node(const char& c) {
	freq = 0;
	_char = c;
	left = right = nullptr;
}

Node::Node(const char& c, const int &f) {
	freq = f;
	_char = c;
	left = right = nullptr;
}

Node::Node(const Node& node) {
	freq = node.freq;
	_char = node._char;
	left = node.get_left();
	right = node.get_right();
}

Node::~Node() {
	freq = 0;
	_char = ' ';
	left = right = nullptr;
}

char Node::get_data() const {
	return _char;
}

int Node::get_freq() const {
	return freq;
}

Node* Node::get_left() const {
	return left;
}

Node* Node::get_right() const {
	return right;
}

void Node::set_freq(const int& f) {
	freq = f;
}

void Node::set_left(Node& l) {
	left = &l;
}

void Node::set_right(Node& r) {
	right = &r;
}

bool Node::operator<(const Node& n) const {
	return freq < n.freq;
}

bool Node::operator>(const Node& n) const {
	return !(*this < n);
}

bool Node::operator==(const Node& n) const {
	return (freq == n.freq) && (_char == n._char);
}

bool Node::operator!=(const Node& n) const {
	return !(*this == n);
}

std::ostream& operator<<(std::ostream& out, const Node& n) {
	return out << n._char << " : " << n.freq;
}