// Eric Mikulin, 14-10-2019
// Leet Unscrambler

#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <string>
#include <thread>

constexpr int asciiTableStart = 32;
constexpr int asciiTableEnd = 126;
constexpr char spaceChar = 32;
constexpr char backspaceChar = 8;
constexpr int speedMS = 25;
constexpr int maxTimePerCharMS = 500 / speedMS;

char generateRandomASCIIChar() {
    static std::random_device rd;
    static std::uniform_int_distribution<char> dist (asciiTableStart, asciiTableEnd);
    return dist(rd);
}

std::string generateRandomString(int length) {
    std::string randomString;
    randomString.reserve(length);

    for(int i = 0; i < length; ++i) {
        randomString.push_back(generateRandomASCIIChar());
    }
    return randomString;
}

int main(int argc, char *argv[]) {
	if(argc == 1) {
		std::cout << "No word was given, can't unscramble!" << std::endl;
		return 1;
	}

	std::string inputString (argv[1]);
    for(int i = 2; i < argc; ++i) {
        inputString.append(" ");
        inputString.append(argv[i]);
    }

    size_t targetLength = inputString.length();

	std::string generatedString (targetLength, spaceChar);
	std::cout << generatedString << std::flush;

    for(const auto& targetChar: inputString) {
        int interationCount = 0;
        do {
            generatedString = generateRandomString(targetLength);
            std::string deletionString (targetLength, backspaceChar);

            if(interationCount == maxTimePerCharMS) {
                generatedString[0] = targetChar;
            }

            std::cout << deletionString << generatedString << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(speedMS));

            ++interationCount;
		} while(targetChar != generatedString.front());

        --targetLength;
	}
	std::cout << std::endl;
	return 0;
}