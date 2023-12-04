#ifndef TWS_LIBRARY_HPP
#define TWS_LIBRARY_HPP

#include <vector>
#include <tuple>
namespace tws
{
    void print_vector(std::vector<int> const & v);
    void print_vector(std::vector<double> const & v);
    void reverse_print_vector(std::vector<int> const & v);
    std::tuple<double, double> calculate_mean_stdev(std::vector<double> const & v,const int nbtodiscard=5);
    int sum(std::vector<int> const & v);
} /* tws */ 

#endif /* ifndef TWS_LIBRARY_HPP */
