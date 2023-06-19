#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int NUM_PEOPLE = 6;

struct State {
  int missionaries, cannibals, boat;
  int parent;
};

bool is_valid(int missionaries, int cannibals, int boat) {
  return (missionaries >= 0 && missionaries <= NUM_PEOPLE / 2) &&
         (cannibals >= 0 && cannibals <= NUM_PEOPLE / 2) &&
         (missionaries == 0 || missionaries >= cannibals) &&
         (NUM_PEOPLE - missionaries >= 0 || NUM_PEOPLE - missionaries <= NUM_PEOPLE / 2 - cannibals) &&
         (boat == 0 || boat == 1);
}

int bfs(State initial_state, State final_state) {
  queue<State> q;
  unordered_set<int> visited;

  q.push(initial_state);
  visited.insert(initial_state.missionaries * 100 + initial_state.cannibals * 10 + initial_state.boat);
  
  int step = 0;

  while (!q.empty()) {
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      State curr = q.front();
      q.pop();

      if (curr.missionaries == final_state.missionaries &&
          curr.cannibals == final_state.cannibals &&
          curr.boat == final_state.boat) {
        return step;
      }

      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 2 - j; k++) {
          int missionaries = curr.missionaries - (curr.boat == 0 ? j : -j);
          int cannibals = curr.cannibals - (curr.boat == 0 ? k : -k);
          int boat = curr.boat == 0 ? 1 : 0;

          if (is_valid(missionaries, cannibals, boat)) {
            int key = missionaries * 100 + cannibals * 10 + boat;
            if (visited.find(key) == visited.end()) {
              State next = {missionaries, cannibals, boat, key};
              q.push(next);
              visited.insert(key);
            }
          }
        }
      }
    }
    step++;
  }
  return -1;
}

int main() {
  State initial_state = {NUM_PEOPLE / 2, NUM_PEOPLE / 2, 0};
  State final_state = {0, 0, 1};
  cout << "O numero de passos necessarios é:" << bfs(initial_state, final_state) << endl;
  return 0;
}
