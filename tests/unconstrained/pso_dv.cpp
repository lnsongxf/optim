//
// PSO tests
//
// g++-mp-7 -O2 -Wall -std=c++11 -I/opt/local/include pso_dv.cpp -o pso_dv.test -L/opt/local/lib -loptim -framework Accelerate
// g++-mp-7 -O2 -Wall -std=c++11 -I./../../include pso_dv.cpp -o pso_dv.test -L./../.. -loptim -framework Accelerate
//

#include "optim.hpp"
#include "./../test_fns/test_fns.hpp"

int main()
{
    //
    // test 1
    arma::vec x_1 = arma::ones(2,1);

    bool success_1 = optim::pso_dv(x_1,unconstr_test_fn_1,nullptr);

    if (success_1) {
        std::cout << "pso_dv: test_1 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_1 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_1:\n" << x_1 << arma::endl;

    //
    // test 2

    arma::vec x_2 = arma::zeros(2,1);

    bool success_2 = optim::pso_dv(x_2,unconstr_test_fn_2,nullptr);

    if (success_2) {
        std::cout << "pso_dv: test_2 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_2 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_2:\n" << x_2 << arma::endl;

    //
    // test 3
    int test_3_dim = 5;
    arma::vec x_3 = arma::ones(test_3_dim,1);

    bool success_3 = optim::pso_dv(x_3,unconstr_test_fn_3,nullptr);

    if (success_3) {
        std::cout << "pso_dv: test_3 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_3 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_3:\n" << x_3 << arma::endl;

    //
    // test 4
    arma::vec x_4 = arma::ones(2,1);

    bool success_4 = optim::pso_dv(x_4,unconstr_test_fn_4,nullptr);

    if (success_4) {
        std::cout << "pso_dv: test_4 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_4 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_4:\n" << x_4 << arma::endl;

    //
    // test 6
    optim::algo_settings settings_6;

    settings_6.pso_initial_lb = arma::zeros(2,1) - 2.0;
    settings_6.pso_initial_ub = arma::zeros(2,1) + 2.0;
    settings_6.pso_n_pop = 1000;

    unconstr_test_fn_6_data test_6_data;
    test_6_data.A = 10;

    arma::vec x_6 = arma::ones(2,1) + 1.0;

    bool success_6 = optim::pso_dv(x_6,unconstr_test_fn_6,&test_6_data,settings_6);

    if (success_6) {
        std::cout << "pso_dv: test_6 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_6 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_6:\n" << x_6 << arma::endl;

    //
    // test 7
    arma::vec x_7 = arma::ones(2,1);

    bool success_7 = optim::pso_dv(x_7,unconstr_test_fn_7,nullptr);

    if (success_7) {
        std::cout << "pso_dv: test_7 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_7 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_7:\n" << x_7 << arma::endl;

    //
    // test 8
    arma::vec x_8 = arma::zeros(2,1);

    bool success_8 = optim::pso_dv(x_8,unconstr_test_fn_8,nullptr);

    if (success_8) {
        std::cout << "pso_dv: test_8 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_8 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_8:\n" << x_8 << arma::endl;

    //
    // test 9
    optim::algo_settings settings_9;
    
    settings_9.pso_initial_lb = arma::zeros(2,1);
    settings_9.pso_initial_lb(0) = -13;
    settings_9.pso_initial_lb(1) = -2;

    settings_9.pso_initial_ub = arma::zeros(2,1);
    settings_9.pso_initial_ub(0) = -9;
    settings_9.pso_initial_ub(1) = 2;

    settings_9.vals_bound = true;

    settings_9.lower_bounds = arma::zeros(2,1);
    settings_9.lower_bounds(0) = -15.0;
    settings_9.lower_bounds(1) = -3.0;

    settings_9.upper_bounds = arma::zeros(2,1);
    settings_9.upper_bounds(0) = 15.0;
    settings_9.upper_bounds(1) = 3.0;

    arma::vec x_9 = arma::zeros(2,1);
    x_9(0) = -11.0;

    settings_9.pso_n_pop = 1000;
    settings_9.pso_n_gen = 10000;

    bool success_9 = optim::pso_dv(x_9,unconstr_test_fn_9,nullptr,settings_9);

    if (success_9) {
        std::cout << "pso_dv: test_9 completed successfully." << std::endl;
    } else {
        std::cout << "pso_dv: test_9 completed unsuccessfully." << std::endl;
    }

    arma::cout << "pso_dv: solution to test_9:\n" << x_9 << arma::endl;

    //
    // for coverage

    optim::algo_settings settings;

    optim::pso_dv(x_1,unconstr_test_fn_1,nullptr);
    optim::pso_dv(x_1,unconstr_test_fn_1,nullptr,settings);

    x_7 = arma::ones(2,1) + 1.0;
    optim::pso_dv(x_7,unconstr_test_fn_7,nullptr,settings);

    arma::cout << "pso_dv: solution to test_7:\n" << x_7 << arma::endl;

    //

    optim::algo_settings settings_2;

    settings_2.vals_bound = true;
    settings_2.lower_bounds = arma::zeros(2,1) - 4.5;
    settings_2.upper_bounds = arma::zeros(2,1) + 4.5;

    x_4 = arma::ones(2,1);
    
    success_4 = optim::pso_dv(x_4,unconstr_test_fn_4,nullptr,settings_2);

    arma::cout << "pso_dv: solution to test_4 with box constraints:\n" << x_4 << arma::endl;

    return 0;
}
