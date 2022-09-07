#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define MAX 10000
template <typename>
class Timer;

template <typename R, typename... T>
class Timer<R(T...)> {
 public:
  typedef R (*function_type)(T...);
  function_type function;

  explicit Timer(function_type function, std::string process_name = "")
      : function_(function), process_name_(process_name) {}

  R operator()(T... args) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    R result = function_(std::forward<T>(args)...);

    end = std::chrono::high_resolution_clock::now();
    int64_t duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count();

    std::cout << std::setw(10) << process_name_ << std::setw(30)
              << "Duration: " + std::to_string(duration) + " ns\n";
    return result;
  }

 private:
  function_type function_;
  std::string process_name_;
};
int A[MAX][MAX], x[MAX], y[MAX];
int firstLoop()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i]+= A[i][j]*x[j];
    return 0;
}
int secondLoop()
{
    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i]+= A[i][j]*x[j];
    return 0;
}
int main(){
    
    /*Initialize A and x*/
    
    for(int i = 0; i < MAX; i++){
        x[i] = i+1;
        y[i] = 0;
        for(int j = 0; j < MAX; j++)
            A[i][j] = i+j;
    }
    //First pair of loops
    Timer<int()> time1(firstLoop, "");
    time1();
    Timer<int()> time2(secondLoop, "");
    time2();
}
