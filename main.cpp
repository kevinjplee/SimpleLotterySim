#include <iostream>
#include <vector>
#include  <random>
#include  <iterator>
#include <algorithm>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

int main() {
  std::vector<int> list;
  int white[5] = {0};
  int power = 0;
  for(int i = 1 ; i < 70; i++)
  {
    list.push_back(i);
  }

  for(int i = 0 ; i < 5; i++)
  {
    auto it = select_randomly(list.begin(), list.end());
    white[i] = *it;
    list.erase(it);
  }

  std::vector<int> powerball;
  for(int i = 1; i < 27; i++)
  {
    powerball.push_back(i);
  }
  power = *select_randomly(powerball.begin(), powerball.end());
  std::sort(white, white + 5);

  for(int i = 0 ; i < 5; i++)
  {
    std::cout<<white[i]<<"  ";
  }
  std::cout<<"powerball is : "<<power<<'\n';
}