//
// Created by yhh on 18-10-27.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define ROW 6
#define COL 5

#define TARGET_SCORE 1000
#define STEP 30

int board[ROW][COL];//={{3,2,1,0,3},{3,1,1,1,0},{3,0,1,0,1},{3,1,3,2,3},{3,3,1,1,1},{1,2,0,0,0}};
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int stepPos[STEP][2];
int maxScore = 0;

struct board_and_score{
  int score;
  int col, row;
  int board[ROW][COL];
};

bool cmp(board_and_score a, board_and_score b){
  return a.score > b.score;
}

void dfs(int steps, int score) {
  if (steps == STEP) {
    if (score > maxScore) {
      maxScore = score;
      cout << score << ":";
      for (int i = 0; i < STEP; i++) {
        cout << "(" << stepPos[i][0] + 1 << "," << stepPos[i][1] + 1 << ") ";
      }
      cout << endl;
    }
  } else {
    board_and_score score_rc[(ROW+1)*(COL+1)];
    for (int i = steps; i < steps + ROW; i++) {
      for (int j = steps; j < steps + COL; j++) {
        int preBoard[ROW][COL];
        int preScore = score;
        memcpy(preBoard, board, sizeof(board));
        // i %= ROW;
        // j %= COL;
        int x = i % ROW , y = j % COL;
        int xx = x, yy = y;
        board[x][y] += 1;
        board[x][y] %= 4;
        score_rc[xx*COL+yy].row = x;
        score_rc[xx*COL+yy].col = y;
        while (true) {

            // cout<<steps<<endl;
          score += 90;
          int dire = board[x][y];
          x += dx[dire];
          y += dy[dire];
          if (x < 0 || x > ROW - 1 || y < 0 || y > COL - 1){
            break;
          }
          else {
            board[x][y] += 1;
            board[x][y] %= 4;
          }
        }
        score_rc[xx*COL+yy].score = score;
        memcpy(score_rc[xx*COL+yy].board, board, sizeof(board));
        memcpy(board, preBoard, sizeof(board));
        score = preScore;
      }
    }
    sort(score_rc, score_rc+ROW*COL, cmp);
    for(int k=0; k<max(steps%3,1)+1; k++){
      memcpy(board, score_rc[k].board, sizeof(board));
      int i = score_rc[k].row;
      int j = score_rc[k].col;
      // cout<<score<<endl;
      stepPos[steps][0] = i;
      stepPos[steps][1] = j;
      dfs(steps + 1, score_rc[k].score);
    }
  }
}

int main(int argc, char const *argv[]) {
  dfs(0, 0);
  return 0;
}
