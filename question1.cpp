#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <random>
#include <vector>
#include <cassert>
#include <chrono>
#include "library.hpp"

int main(int argc, char* argv[]){
    assert(argc==4);
    int n = atoi(argv[1]);
    int nb_runs = atoi(argv[2]);
    int nb_warm_up = atoi(argv[3]);
    assert(n>0);
    assert(nb_runs>0);
    assert(nb_warm_up>0);
    assert(nb_runs>nb_warm_up);

    std::vector<int> v (n);
    std::iota(v.begin(), v.end(), 1);

    // Shuffle the elements of v using the given random number generator
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

    // tws::print_vector(v);
    // tws::reverse_print_vector(v);

    // std::cout<<tws::sum(v)<<std::endl;
    // std::cout<<v.size()*(v.size() + 1)/2<<std::endl;
    // std::cout<<std::accumulate(v.begin(), v.end(), 0)<<std::endl;

    std::vector<double> timings(nb_runs);
    std::cerr<<"[ ";
    for (int i = 0; i < nb_runs; i++)
    {
        auto t_start = std::chrono::high_resolution_clock::now();
        int sum = tws::sum(v);
        std::cerr<<sum<<" ";
        auto t_end = std::chrono::high_resolution_clock::now();
        timings[i] = std::chrono::duration<double>(t_end - t_start).count();
    }
    std::cerr<<"]"<<std::endl;

    std::cerr<<"[ ";
    for (int i = 0; i < nb_runs; i++) {
        std::cerr<<timings[i]<<" ";
    }
    std::cerr<<"]"<<std::endl;

    auto [mean, st_dev] = tws::calculate_mean_stdev(timings,nb_warm_up);
    std::cout<<n<<" "<<mean<<" "<<st_dev<<std::endl;
    return 0;
}