#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll N, ATK;

struct room {
  ll t, a, h;
};

bool solve(ll cur_hp, const std::vector<room> &rooms) {
  // std::cout << "\nSolve Started\n";

  ll max_hp = cur_hp;
  ll atk = ATK;
  for (int i = 0; i < N; ++i) {

    auto [t, a, h] = rooms[i];

    if (t == 1) { //monster

      ll cnt = (h + atk - 1) / atk;
      ll dmg = (cnt - 1) * a;

      if (cur_hp <= dmg) return false;
      cur_hp -= dmg;
    }
    else { //healing room

      atk += a;
      cur_hp += h;
      cur_hp = std::min(cur_hp, max_hp);
    }
  }

  // std::cout << "Solve Ended, result is : " << max_hp << '\n';
  return true;
}

int main() {
  std::cin >> N >> ATK;

  std::vector<room> rooms(N);
  ll left = 1;
  ll right = 1LL << 62;

  for (int i = 0; i < N; ++i) {
    ll t, a, h;
    std::cin >> t >> a >> h;
    rooms[i] = {t, a, h};
  }

  while (left < right) {
    ll mid = left + (right - left) / 2;

    if (solve(mid, rooms)) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }

  std::cout << left << '\n';

  return 0;
}