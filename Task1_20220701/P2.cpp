#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

class StringSet {
    friend StringSet operator+(const StringSet&, const StringSet&);
    friend StringSet operator*(const StringSet&, const StringSet&);
    friend double computeSimilarity(const StringSet&, const StringSet&);

public:
    StringSet(const std::string& s = "") {
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            stringSet.insert(word);
        }
    }

    int getSize() const {
        return stringSet.size();
    }

    void outputSet() const {
        std::cout << "{";
        for (const auto& word : stringSet) {
            std::cout << " " << word;
        }
        std::cout << " }" << std::endl;
    }

private:
    std::set<std::string> stringSet;
};

StringSet operator+(const StringSet& s1, const StringSet& s2) {
    StringSet resultSet(s1);
    resultSet.stringSet.insert(s2.stringSet.begin(), s2.stringSet.end());
    return resultSet;
}

StringSet operator*(const StringSet& s1, const StringSet& s2) {
    StringSet resultSet;
    std::set_intersection(
        s1.stringSet.begin(), s1.stringSet.end(), s2.stringSet.begin(), s2.stringSet.end(),
        std::inserter(resultSet.stringSet, resultSet.stringSet.begin())
    );
    return resultSet;
}

double computeSimilarity(const StringSet& s1, const StringSet& s2) {
    int intersectionSize = (s1 * s2).getSize();
    double sqrtProduct = sqrt(static_cast<double>(s1.getSize() * s2.getSize()));

    // Calculate the binary cosine coefficient
    return (intersectionSize / sqrtProduct);
}

int main() {
    StringSet document("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    StringSet query("Chocolate is delicious.");

    // Display the sets
    std::cout << "Document set: ";
    document.outputSet();
    std::cout << "Query set: ";
    query.outputSet();

    // Calculate the similarity
    double similarity = computeSimilarity(document, query);
    std::cout << "Similarity: " << similarity << std::endl;

    return 0;
}
