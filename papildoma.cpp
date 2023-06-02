#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <set>
#include <iomanip>
#include <regex>
#include <unordered_set>


bool containsNumbers(const std::wstring& word) {
    for (wchar_t c : word) {
        if (iswdigit(static_cast<unsigned short>(c))) {
            return true;
        }
    }
    return false;
}

// Case-insensitive comparison function for sorting
bool caseInsensitiveCompare(const std::wstring& a, const std::wstring& b) {
    std::wstring lowerA, lowerB;
    for (wchar_t c : a) {
        lowerA += std::tolower(c);
    }
    for (wchar_t c : b) {
        lowerB += std::tolower(c);
    }
    return lowerA < lowerB;
}

void printUrls(const std::string& text) {
    // Read the domain names from the text file
    std::ifstream file("domenai.txt");
    std::unordered_set<std::string> domains;
    std::string domain;
    while (std::getline(file, domain)) {
        domains.insert(domain);
    }
    file.close();

    // Construct the regular expression pattern
    std::string pattern = "(?:http[s]?://)?(?:www\\.)?([^\\s/$.?#]+\\.[^\\s]*)";
    std::regex urlRegex(pattern);

    std::cout << "URLs found in the text:" << std::endl;
    std::sregex_iterator regexIterator(text.begin(), text.end(), urlRegex);
    std::sregex_iterator regexIteratorEnd;

    while (regexIterator != regexIteratorEnd) {
        std::smatch match = *regexIterator;
        std::string url = match.str();

        // Extract the top-level domain from the URL
        std::size_t dotPos = url.find_last_of('.');
        std::string tld = url.substr(dotPos);

        // Check if the top-level domain is in the set of allowed domains
        if (domains.count(tld) > 0) {
            std::cout << url << std::endl;
        }

        ++regexIterator;
    }
}

int main() {
    std::unordered_map<std::wstring, int> wordCounts;
    std::unordered_map<std::wstring, std::set<int>> wordOccurrences;

    std::wifstream inputFile("tekstas.txt");

    if (!inputFile) {
        std::wcerr << L"Failed to open the input file." << std::endl;
        return 1;
    }

    inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8_utf16<wchar_t, 0x10ffff, std::little_endian>));
    std::wstring line;
    int lineNumber = 1;
    while (std::getline(inputFile, line)) {
        std::wistringstream iss(line);
        std::wstring word;
        while (iss >> word) {
            // Remove punctuation marks from the beginning and end of each word
            size_t start = 0;
            size_t end = word.length();

            while (start < end && !iswalpha(word[start])) {
                ++start;
            }

            while (end > start && !iswalpha(word[end - 1])) {
                --end;
            }

            word = word.substr(start, end - start);

            // Exclude words containing numbers or consisting entirely of numbers
            if (word.length() > 1 && !containsNumbers(word)) {
                // Convert the word to lowercase
                std::wstring lowercaseWord;
                for (wchar_t c : word) {
                    lowercaseWord += towlower(c);
                }

                // Add the word occurrence to the map
                wordOccurrences[lowercaseWord].insert(lineNumber);
                ++wordCounts[word];
            }
        }
        ++lineNumber;
    }

    // Output the results
    // Output the results
    std::wofstream outputFile1("rezultatai.txt", std::ios::binary);
    if (!outputFile1) {
        std::wcerr << L"Failed to create the output file." << std::endl;
        return 1;
    }

    outputFile1.imbue(std::locale(outputFile1.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::generate_header>));

    // Store the results in a vector for sorting
    std::vector<std::pair<std::wstring, int>> sortedWordCounts;
    for (const auto& entry : wordCounts) {
        if (entry.second > 1) {
            sortedWordCounts.push_back(entry);
        }
    }

    // Sort the vector alphabetically by word (case-insensitive)
    std::sort(sortedWordCounts.begin(), sortedWordCounts.end(), [](const auto& a, const auto& b) {
        return caseInsensitiveCompare(a.first, b.first);
        });

    for (const auto& entry : sortedWordCounts) {
        outputFile1 << entry.first << L": " << entry.second << std::endl;
    }

    std::wcout << L"Results saved to rezultatai.txt" << std::endl;

    // ...

    std::wofstream outputFile2("crossreference.txt");
    if (!outputFile2) {
        std::wcerr << L"Failed to create the output file." << std::endl;
        return 1;
    }

    outputFile2.imbue(std::locale(outputFile2.getloc(), new std::codecvt_utf8_utf16<wchar_t, 0x10ffff, std::little_endian>));
    outputFile2 << L"Cross-Reference Table:" << std::endl;

    // Store the cross-references in a vector for sorting
    std::vector<std::pair<std::wstring, std::set<int>>> sortedWordOccurrences;
    for (const auto& entry : wordOccurrences) {
        const std::wstring& word = entry.first;
        const std::set<int>& occurrences = entry.second;
        if (occurrences.size() > 1) {
            sortedWordOccurrences.push_back(entry);
        }
    }

    // Sort the vector alphabetically by word (case-insensitive)
    std::sort(sortedWordOccurrences.begin(), sortedWordOccurrences.end(), [](const auto& a, const auto& b) {
        return caseInsensitiveCompare(a.first, b.first);
        });

    for (const auto& entry : sortedWordOccurrences) {
        const std::wstring& word = entry.first;
        const std::set<int>& occurrences = entry.second;
        outputFile2 << std::left << std::setw(20) << word;
        for (int line : occurrences) {
            outputFile2 << std::setw(5) << line << L" ";
        }
        outputFile2 << std::endl;
    }

    std::wcout << L"Results saved to crossreference.txt" << std::endl;


    // Read the input file again to extract URLs
    std::ifstream inputFileUrls("tekstas.txt");
    if (!inputFileUrls) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFileUrls)), std::istreambuf_iterator<char>());

    // Print the URLs found in the input file
    printUrls(text);

    return 0;
}
