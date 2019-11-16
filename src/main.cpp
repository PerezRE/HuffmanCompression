#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <map>
#include <queue>
#include <vector>
#include <ctype.h>
#include <stack>
#include "Tokenizer.hpp"
#include "Node.hpp"
#include "HuffmanTree.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
    // arg_c is 1 by defualt, even if there are not args in argv.
    argc--;
    if(argc == 0)
    {
        std::cout << "Type a filename" << std::endl;
        return 0;
    }

    // "Read" the file
    std::ifstream ifs(argv[argc]);

    // If there are reading errors.
    if (!ifs.good()) {
        std::cout << "the file does not exist" << std::endl;
        return 0;
    }

    // Read the whole file and store it in a string
    std::string txt((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

    // Create a map (table), which will store the frequency for each read character.
    std::map<char, int> dict;
    // Create a tokenizer object that allows separate each word (this is optional since the app does not count the space char).
    Tokenizer str(txt);
    // auxiliar string object that holds the word.
    std::string token;
    // Read the next word while it's not empty.
    while ((token = str.next()) != "") {
        // Read each char in the word.
        for(char &_char : token) {
            // Convert the cahr to lower (or to upper).
            char c =  tolower(_char);
            // Init the counter if the char has not been counted.
            if (dict.find(c) == dict.end())
                dict[c] = 0;
            // Increment the frequency.
            dict[c]++;
        }
    }

    for (std::pair<const char, int> &p : dict)
        std::cout << p.first << " : " << p.second << std::endl;
    cout << endl;

    
    // If the dictionary is printed, one can perceive that the keys are sorted.
    // Priority queue is needed, ordering according the frequency, so a NodeComparator is needed in tthis case.
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> queue;
    for(std::pair<const char, int> &p : dict) {
        Node *n = new Node(p.first, p.second);
        queue.push(n);
    }

    // Once the queue is built, the next step is build a new Huffman Tree.
    HuffmanTree h_tree(queue);

    // Finally, the compressed binary representation of each character is printed.
    std::map<char, std::string> coded_chars;
    h_tree.encode(coded_chars);
    for (auto pair : coded_chars)
        cout << pair.first << " : " << pair.second << endl;

    // Dump compressed message.
    cout << endl << h_tree.decode("011011110110") << endl;
    
    return 0;
}