#include "strings/packed_prefix/packed_prefix_test.h"

#include "strings/crib/crib_test.h"

int main() {
    strings_packed_prefix::TestAll();
    strings_packed_prefix::RunProgram();

    strings_crib::TestAll();
    strings_crib::RunProgram();

}