#include "pathfinder.h"

void error_handling(int argc, char *filename) {
    invalid_argc(argc);
    invalid__file_no_exists(filename);
    invalid_file_empty(filename);

    in_data.string = mx_file_to_str(filename);   // read file and set pointer to string in struct in_data

    invalid_first_line();
    invalid_format_line();
    inv_number_of_islands();
    inv_duplicate_bridges();
    invalid_sum_of_bridges();
}
