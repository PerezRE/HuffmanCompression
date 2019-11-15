#ifndef NODE_H_
#define NODE_H_

#include <iostream>

/** Represents a Huffman (binary) Node */
class Node
{
private:
	/** Frequency */
	int freq;
	/** Character to be hold in node */
	char _char;
	/** Left and right nodes */
	Node *left, *right;

public:
	/** Creates a new node with default values. */
	Node();
	/** Creates a new node given a character. 
	 * @param char value to be saved in the node.
	*/
	Node(const char &);
	/** Creates a new node given a value and the frequency 
	 * @param char value to be saved in the node.
	 * @param freq char's frequency.
	*/
	Node(const char &, const int &);
	/** Creates a new node from another one.
	 * @param node node to be copied.
	 */
	Node(const Node &);
	/** Detroys the node */
	~Node();
	/** Get the value of the node.
	 * @return character saved in the node.
	*/
	char get_data() const;
	/** Get frequency of the character.
	 * @return frequency of the character saved in the node.
	 */
	int get_freq() const;
	/** Get left node.
	 * @return left node.
	 */
	Node *get_left() const;
	/** Get right node.
	 * @return right node.
	 */
	Node *get_right() const;
	/** Set a new frequency.
	 * @param freq new frequency value.
	 */
	void set_freq(const int &);
	/** Set left node.
	 * @param node new left node.
	 */
	void set_left(Node &);
	/** Set right node.
	 * @param node new right node.
	 */
	void set_right(Node &);
	/** Determines if the node is less than other one, using frequency as reference point.
	 * @param node node to be compared.
	*/
	bool operator<(const Node &) const;
	/** Determines if the node is greater than other one, using frequency as reference point. 
	 * @param node node to be compared.
	*/
	bool operator>(const Node &) const;
	/** Determines if the node is equal to another one using frequency and value.
	 * @param node node to be compared.
	 */
	bool operator==(const Node &) const;
	/** Determines if the node is different to another one, comparing frequency and value. 
	 * @param node node to be compared.
	*/
	bool operator!=(const Node &) const;
	/** Represents the node as string.
	 * @param os the ostream object.
	 * @param node node to be "printed".
	 * @return an updated ostream.
	 */
	friend std::ostream &operator<<(std::ostream &, const Node &);
};

/** Helper Class that allows compare two Huffman node pointers  */
class NodeComparator
{
public:
	/** Comprares two huffman Nodes
	 * @return true if node 'a' is greater than node 'b'.
	*/
	bool operator()(const Node *a, const Node *b)
	{
		/* The node will be used in a priority_queue for the huffman compression algorithm
			and such queue is ordered from highest to lowest, so that we want the opposite,
			it means, that the queue should order from lowest to highest, so the oeprator> is
			called instead of operator<.
		*/
		return a->get_freq() > b->get_freq();
	}
};

#endif