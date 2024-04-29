#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

struct TreeNode {
    std::string identifier;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(std::string id, int cnt) : identifier(id), count(cnt), left(nullptr), right(nullptr) {}
};

TreeNode* addIdentifier(TreeNode* node, const std::string& identifier) {
    if (node == nullptr) {
        return new TreeNode(identifier, 1);
    }

    int comparison = identifier.compare(node->identifier);
    if (comparison < 0) {
        node->left = addIdentifier(node->left, identifier);
    } else if (comparison > 0) {
        node->right = addIdentifier(node->right, identifier);
    } else {
        node->count++;
    }

    return node;
}

void printIdentifiers(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printIdentifiers(node->left);
    std::cout << node->identifier << ": " << node->count << std::endl;
    printIdentifiers(node->right);
}

int main() {
    std::ifstream file("program.cpp");
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    std::string line;
    TreeNode* root = nullptr;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            while (!word.empty() && ispunct(word.back())) {
                word.pop_back();
            }
            root = addIdentifier(root, word);
        }
    }

    std::cout << "Identifiers:" << std::endl;
    printIdentifiers(root);

    file.close();
    return 0;
}
