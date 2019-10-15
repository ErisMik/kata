# Eric Mikulin, 14-10-2019
# Readme Generator

import os
import os.path as ospath

TEMPLATE_SRC_FILEPATH = "../README_TEMPLATE.md"
TEMPLATE_DEST_FILEPATH = "../../README.md"

EXCLUSION_LIST = [".git"]
START_DIR = "../../"

def fixCase(dirname):
    words = dirname.split("-")
    title = " ".join(words)
    return title.capitalize()

def mapChallengesAndLanguages(starting_dir):
    challengeMap = {}

    for root, dirs, files in os.walk(starting_dir, topdown=True):
        for name in dirs:
            if all(invalid not in root and invalid not in name for invalid in EXCLUSION_LIST):
                if root == START_DIR:
                    challengeMap[name] = set()
                elif os.path.basename(root) in challengeMap:
                    challengeMap[os.path.basename(root)].add(name)

    return challengeMap

def printTableToFile(file_ptr, languageList, challengeMap):
    file_ptr.write("Challenge | " + " | ".join(languageList) + "\n")
    file_ptr.write("--- | " * (len(languageList) +1) + "\n")
    for challenge, languages in challengeMap.items():
        tableRow = []
        for lang in languageList:
            if lang.lower() in languages:
                tableRow.append(f"[CODE](./{challenge}/{lang.lower()})")
            else:
                tableRow.append("-")
        file_ptr.write(f"[{fixCase(challenge)}](./{challenge})" + " | " + " | ".join(tableRow) + "\n")

def main():
    challengeMap = mapChallengesAndLanguages(START_DIR)

    languageList = set()
    for key, values in challengeMap.items():
        for lang in values:
            languageList.add(lang.capitalize())
    languageList = sorted(languageList)

    with open(TEMPLATE_SRC_FILEPATH, 'r') as input_template:
        with open(TEMPLATE_DEST_FILEPATH, 'w') as output_template:
            for line in input_template:
                if "<!-- TEMPLATE -->" in line:
                    printTableToFile(output_template, languageList, challengeMap)
                else:
                    output_template.write(line)

if __name__ == "__main__":
    main()