#include <iostream>
#include <vector>

int N, result = 0;
std::vector<int> op;

void push_left(std::vector<std::vector<int>> &map)
{
  for (int i = 0; i < N; ++i)
  {
    std::vector<int> new_row;
    for (int j = 0; j < N; ++j)
    {
      if (map[i][j] != 0)
        new_row.push_back(map[i][j]);
    }

    for (int j = 0; j + 1 < new_row.size(); ++j)
    {
      if (new_row[j] == new_row[j + 1])
      {
        new_row[j] *= 2;
        new_row[j + 1] = 0;
      }
    }

    std::vector<int> merged_row;
    for (int num : new_row)
    {
      if (num != 0)
        merged_row.push_back(num);
    }
    while (merged_row.size() < N)
      merged_row.push_back(0);

    map[i] = merged_row;
  }
}

void rotate(std::vector<std::vector<int>> &map, bool clock_wise)
{
  std::vector<std::vector<int>> temp(N, std::vector<int>(N));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (clock_wise)
        temp[i][j] = map[(N - 1) - j][i];
      else
        temp[i][j] = map[j][(N - 1) - i];
    }
  }
  map = temp;
}

void solve(std::vector<std::vector<int>> &map)
{
  std::vector<std::vector<int>> map_copy = map;

  // 0 : left
  // 1 : right
  // 2 : up
  // 3 : down
  for (int dir : op)
  {
    switch (dir)
    {
    case 0:
      push_left(map_copy);
      break;

    case 1: 
      rotate(map_copy, true);
      rotate(map_copy, true);
      push_left(map_copy);
      rotate(map_copy, true);
      rotate(map_copy, true);
      break;

    case 2: 
      rotate(map_copy, false);
      push_left(map_copy);
      rotate(map_copy, true);
      break;

    case 3: 
      rotate(map_copy, true);
      push_left(map_copy);
      rotate(map_copy, false);
      break;
    }
  }

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (map_copy[i][j] > result)
        result = map_copy[i][j];
    }
  }
}

void combi(std::vector<std::vector<int>> &map)
{
  if (op.size() == 5)
  {
    solve(map);
    return;
  }

  for (int i = 0; i < 4; ++i)
  {
    op.push_back(i);
    combi(map);
    op.pop_back();
  }
}

int main()
{
  std::cin >> N;
  std::vector<std::vector<int>> map(N, std::vector<int>(N));

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      std::cin >> map[i][j];
    }
  }

  combi(map);

  std::cout << result << '\n';

  return 0;
}