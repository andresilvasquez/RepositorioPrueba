#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cctype>

void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const std::string FNAME = argv[1];
    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname)
{
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        word.erase(std::remove_if(word.begin(), word.end(),
                                  [](unsigned char c){ return std::ispunct(c); }),
                   word.end());

        if (!word.empty()) {
            word_count[word]++;
        }
    }

    std::vector<std::pair<std::string, int>> freq_vec(word_count.begin(), word_count.end());
    std::sort(freq_vec.begin(), freq_vec.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second;
              });

    std::cout << "\nTop 20 most frequent words:\n";
    int count = 0;
    for (const auto& [word, freq] : freq_vec) {
        std::cout << word << ": " << freq << std::endl;
        if (++count >= 20) break;
    }
}