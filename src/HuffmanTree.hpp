#ifndef HUFFMANN_TREE_H
#define HUFFMANN_TREE_H

#include <queue>
#include <vector>
#include <string>
#include <map>
#include "Node.hpp"

/** Represents a Huffman Tree */
class HuffmanTree
{
private:
	/** Tree's Root */
	Node *root;
	/** Iterates the tree in a preorder way
		 * @param node node that would be used to perform the action to.
		 * @param map Map that holds the character and its compressed binary representation.
		 */
	void preorder(Node *, std::map<char, std::string> &, std::string) const;
	/** Iterates the tree in a postorder way 
		 * @param node node that would be used to perform the action to.
		 * @param function funciton to be called.
		*/
	void postorder(Node *, void (*)(Node *));
public:
	/** Create a new Huffman Tree
	 * @param queue A priority queue with the sorted nodes by frequency.
	 */
	HuffmanTree(std::priority_queue<Node *, std::vector<Node *>, NodeComparator> &);
	/** Detroys the Huffman Tree */
	~HuffmanTree();
	/** Create the compressed binary representation for each leaf (character).
	 * @param map Dictionary that holds the character as key and its compressed binary representation as std::string
	*/
	void encode(std::map<char, std::string> &) const;
	/** Decodes a message given a binary string representation.
	 * @param coded_message Message to decode.
	 * @return Message decoded.
	*/
	std::string decode(const std::string&) const;
};

#endif