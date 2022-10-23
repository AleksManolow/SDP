#include<iostream>
#include <array>
#include <queue>
#include<string>

#define boardSize 8
class minMoves {
    using position = std::pair<int, int>;
    using positionAndSteps = std::pair<position, int>;
    using board = std::array<std::array<bool, boardSize>, boardSize>;

    board playground;

    void cleanPlayground() {
        for (auto &col : playground)
            for (auto &pos : col)
                pos = false;
    }

    position converToMatrixCord(std::string chessBoardCord)
    {
        int fisrtPos = - 1;
        switch (chessBoardCord[0])
        {
        case 'A':
            fisrtPos = 0;
            break;
        case 'B':
            fisrtPos = 1;
            break;
        case 'C':
            fisrtPos = 2;
            break;
        case 'D':
            fisrtPos = 3;
            break;
        case 'E':
            fisrtPos = 4;
            break;
        case 'F':
            fisrtPos = 5;
            break;
        case 'G':
            fisrtPos = 6;
            break;
        case 'H':
            fisrtPos = 7;
            break;
        }
        return {fisrtPos, chessBoardCord[1] - '0' - 1};
    }

    static bool equalPositions(const position &fst, const position &snd) {
        return fst.first == snd.first && fst.second == snd.second;
    }

    static bool isValidPos(const position &p) {
        return p.first >= 0 && p.second >= 0 && p.first < boardSize && p.second < boardSize;
    }

    void mark(const position &toMark) {
        playground[toMark.first][toMark.second] = true;
    }

    bool isMarked(const position &pos) const {
        return playground[pos.first][pos.second];
    }

    void pushAndMarkIfValid(std::queue<positionAndSteps> &q, const position &toPush, int steps) {
        if (isValidPos(toPush) && !isMarked(toPush)) {
            q.push({toPush, steps});
            mark(toPush);
        }
    }

    int process(const std::string startChessBoardCord, const std::string endChessBoardCord) {
        const position &startPos = converToMatrixCord(startChessBoardCord);
        const position &endPos = converToMatrixCord(endChessBoardCord);
        std::queue<positionAndSteps> q;

        q.push({startPos, 0});

        while (!q.empty()) {
            positionAndSteps currentPosition = q.front();

            q.pop();

            if (equalPositions(currentPosition.first, endPos))
                return currentPosition.second;

            int x = currentPosition.first.first;
            int y = currentPosition.first.second;
            int moves = currentPosition.second + 1;

            pushAndMarkIfValid(q, {x + 1, y + 2}, moves);
            pushAndMarkIfValid(q, {x - 1, y - 2}, moves);
            pushAndMarkIfValid(q, {x + 1, y - 2}, moves);
            pushAndMarkIfValid(q, {x - 1, y + 2}, moves);
            pushAndMarkIfValid(q, {x + 2, y - 1}, moves);
            pushAndMarkIfValid(q, {x + 2, y + 1}, moves);
            pushAndMarkIfValid(q, {x - 2, y + 1}, moves);
            pushAndMarkIfValid(q, {x - 2, y - 1}, moves);
        }
        return -1;
    }

public:
    minMoves() { cleanPlayground(); }

    int getMinMoves(const std::string start, const std::string end) {
        cleanPlayground();

        return process(start, end);
    }
};

int main() {

    minMoves m;
    
    std::cout << m.getMinMoves("A1", "H5") << std::endl;
    
    minMoves mp;

    std::cout << mp.getMinMoves("A2", "C3") << std::endl;

}