// Tested on https://quick-bench.com/

static void reverseCString(benchmark::State& state) {
  char str[] = "123456789101112131415";
  int n = strlen(str);
  for(auto _ : state){
    for (int i = 0; i < n / 2; i++) {
      std::swap(str[i], str[n - i - 1]);
    }
  }
}

BENCHMARK(reverseCString);

static void reverseString(benchmark::State &state) {
  std::string str = "123456789101112131415";
  int n = str.length();
  for (auto _ : state) {
    for (int i = 0; i < n / 2; i++) {
      std::swap(str[i], str[n - i - 1]);
    }
  }
}

BENCHMARK(reverseString);

static void reverse(benchmark::State &state) {
  std::string str = "123456789101112131415";
  for (auto _ : state) {
    std::reverse(str.begin(), str.end());
  }
}

BENCHMARK(reverse);

static void reverseCons(benchmark::State &state) {
  std::string str = "123456789101112131415";
  for (auto _ : state) {
    std::string rev(str.rbegin(), str.rend());
  }
}

BENCHMARK(reverseCons);
