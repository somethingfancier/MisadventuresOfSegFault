#include "universe.h"

#include <iostream>
#include <sstream>
#include <QDebug>
#include <algorithm>

WorldScore::WorldScore(){
    score = 0;
}

void WorldScore::increase(int amount){
    score = score + amount;
}

int WorldScore::getScore() {
    return score;
}

void WorldScore::Save() {
    ofstream outputFile;
    outputFile.open("segfaultScores.txt");

    ifstream inputFile("segfaultScore");


    outputFile << score << ",";

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();

    rename("segfaultScores.txt", "segfaultScore");
}

void WorldScore::Load() {

    const int maxChars = 5120;
    const int maxTokens = 200;
    const char* const delimiter = ",";

    ifstream fin;
    fin.open("segfaultScore");
    if (!fin.good())
    {
        //TODO: error message
    }
    else {
        while (!fin.eof()) {
            char buf[maxChars];
            fin.getline(buf, maxChars);

            int i = 0;

            const char* token[maxTokens] = {};

            token[0] = strtok(buf, delimiter);
            if (token[0])
            {
                for (i = 1; i < maxTokens; i++)
                {
                    token[i] = strtok(0, delimiter);
                    if (!token[i])
                    {
                        break;
                    }
                }
            }
            string maString = "";

            for (int n = 0; n < i; n++)
            {
                 maString = maString + token[n] + "\n";
            }

            stringstream playerScore;
            playerScore << token[0];
            int playerIntScore;
            playerScore >> playerIntScore;

            Universe::instance().getPlayer()->getScore()->increase(playerIntScore);

        }
    }

}

int WorldScore::HighscoreLoad() {

    const int maxChars = 5120;
    const int maxTokens = 200;
    const char* const delimiter = ",";

    ifstream fin;
    fin.open("segfaultHighScore");
    if (!fin.good())
    {
        //TODO: error message
    }
    else {
        while (!fin.eof()) {
            char buf[maxChars];
            fin.getline(buf, maxChars);

            int i = 0;

            const char* token[maxTokens] = {};

            token[0] = strtok(buf, delimiter);
            if (token[0])
            {
                for (i = 1; i < maxTokens; i++)
                {
                    token[i] = strtok(0, delimiter);
                    if (!token[i])
                    {
                        break;
                    }
                }
            }
            string maString = "";

            for (int n = 0; n < i; n++)
            {
                 maString = maString + token[n] + "\n";
            }

            stringstream playerScore;
            playerScore << token[0];
            int playerIntScore;
            playerScore >> playerIntScore;

            return playerIntScore;

        }
    }

    return 0;

}

void WorldScore::HighscoreSave() {
    int highScore = Universe::instance().getPlayer()->getScore()->HighscoreLoad();
    ofstream outputFile;
    outputFile.open("segfaultHighScores.txt");

    ifstream inputFile("segfaultHighScore");

    if (highScore < score) {
        outputFile << score << ",";

        outputFile << inputFile.rdbuf();
        inputFile.close();
        outputFile.close();

        rename("segfaultHighScores.txt", "segfaultHighScore");
    }
    else {
        outputFile << score << ",";
        inputFile.close();
        outputFile.close();

        rename("segfaultHighScores.txt", "segfaultHighScore");
    }

}
